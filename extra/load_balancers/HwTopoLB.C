/*****************************************************************************
 * $Source$
 * $Author$ Christiane Pousa, Laércio Pilla, François Broquedis, Pierre Coucheney
 * $Date$ 08-2013
 * $Revision$ 1.4
 *****************************************************************************/

#include "HwTopoLB.h"

CreateLBFunc_Def(HwTopoLB, "Topology-aware load balancing algorithm. Takes into account the communication costs of the machine (as latency and bandwidth). Proved asymptotically optimal.")


void HwTopoLB::init (){
    costs = CommunicationCosts(LEVELTYPE_WHOLETOPOLOGY);
    init(XMLFILE, -1);
}

void HwTopoLB::init (char* xmlfile, int nodesize){
    lbname = (char *)"HwTopoLB";

    //Hand coded alpha and beta to chose the processor/task
    alpha = 0.8;
    beta = 0.8;

    //temperature - used to chose the target processor to migrate the task
    temperature = 0.1; 

    //Initialize the uniform generator seed
    struct timeval tp;

    if (nodesize == -1){
        if (CkMyPe() == 0){
            CkPrintf ("[%d] Centralized HwTopoLB starting\n", CkMyPe ());
            //loads topology with benchmarked information
            TopologyAwareLB::init(xmlfile);

            gettimeofday(&tp,NULL);
            srand((int)((((int)tp.tv_sec)%10000)*1000000)+tp.tv_usec);
            srand( time(NULL) );
        }
    }
    else {
        if (CkMyPe()%nodesize == 0){
            CkPrintf ("[%d] HwTopoLB starting\n", CkMyPe ());
            //loads topology with benchmarked information
            TopologyAwareLB::init(xmlfile);

            gettimeofday(&tp,NULL);
            srand((int)((((int)tp.tv_sec)%10000)*1000000)+tp.tv_usec);
            srand( time(NULL) );
        }

    }
}

HwTopoLB::HwTopoLB(const CkLBOptions &opt): TopologyAwareLB(opt)
{
    init();
    if (CkMyPe() == 0)
        CkPrintf("[%d] HwTopoLB created\n",CkMyPe());
}

HwTopoLB::HwTopoLB(CkMigrateMessage *m):TopologyAwareLB(m) {
    init();
}

CmiBool HwTopoLB::QueryBalanceNow(int _step)
{
    //  CkPrintf("[%d] Balancing on step %d\n",CkMyPe(),_step);
    return CmiTrue;
}


double HwTopoLB::unif()
{
  return rand()/(1.0+(double) RAND_MAX);
}

void HwTopoLB::work(LDStats *stats) {
    int pSize;                                      // Total number of processors
    int cSize;                                      // Total number of chares
    int newProc;
    int chosenProc;                                 // chosen processor in a given iteration
    int chosenChare;                                // chosen chare in a given iteration
    int c, extra_tasks;
    std::vector<int> *CharesOnProcs;                // lists the chares mapped to a processor
    double start, end;

    TopologyAwareLB::work(stats);
    
    start = CmiWallTimer();
    pSize = pus.size();
    cSize = tasks.size();
    NewLoadArray = new double[pSize];

    /* General idea of the algorithm:
     * 0) Prepare costs to consider chares communication
     * 1) While we iterate our algorithm (working on how to define the best
     * stop objective)
     * 2) Choose a processor
     * 3) Choose a chare
     * 4) Compute possible mappings
     * 5) Choose one mapping
     * 6) Apply this mapping
     * */

    /***** 0) Prepare costs to consider chares communication *****/
    CharesOnProcs = preprocess(cSize,pSize);

    /***** 0.1) Maps unmapped tasks *****/
    extra_tasks = 0;
    for (c = 0; c < cSize; c++){
        if(tasks[c].getNewPe() >= pSize){
            chosenProc = tasks[c].getNewPe();
            newProc = chooseMapping(pSize, chosenProc, c);
            applyMapping(pSize, chosenProc, newProc, c, CharesOnProcs, stats);
	    extra_tasks++;
        }
    }

    /***** 1) While we iterate our algorithm *****/
    bool iterate = true;
    int iterations = 0;

    while ((iterate)&&(iterations < cSize)) {

        /***** 2) Choose a processor *****/
        chosenProc = choosePU(pSize, CharesOnProcs);
        
        /***** 3) Choose a chare *****/
        chosenChare = chooseTask(chosenProc, CharesOnProcs);

        /***** 4) Compute possible mappings; and *****/
        /***** 5) Choose one mapping *****/
        newProc = chooseMapping(pSize, chosenProc, chosenChare);
     
        /***** 6) Apply this mapping *****/
        iterate = applyMapping(pSize, chosenProc, newProc, chosenChare, CharesOnProcs, stats);
        iterations++;
    }
    end = CmiWallTimer();
    if(_lb_args.debug()){
        CkPrintf("[%d] Internal iterations = %d + %d newly mapped\n", CkMyPe(), iterations, extra_tasks);
        CkPrintf("[%d] HwTopoLB time: %lf\n", CkMyPe(), end - start);
    }


    //free memory
    delete NewLoadArray;

}

double HwTopoLB::changeLoads( int chareId, int newProc, double *loads ){
    /* Steps to change load 
     * 1) Take chare from its current processor and map it to the new one 
     * 2) Change the load of the processors that have chares that receive
     * messages from chareId
     * 3) Change the load of the new processor considering the costs of
     * messages received by chareId
     * */

    struct comm_t new_comm_cost, old_comm_cost, comm_cost;
    int i, cSize, ngb_id, ngb_proc, j, destSize;
    double extraLoad, latency, bandwidth;
    Vertex *chare = &tasks[chareId];
    int currentProc = chare->getNewPe();
    int pSize = pus.size();

    /** 1 **/
    loads[newProc] += OriginalLoads[chareId]; //add original load
    if (currentProc < pSize){ //if the task is currently mapped somewhere
        loads[currentProc] -= chare->getVertexLoad(); //remove load with comm
    }

    /** 2 **/
    cSize = chare->sendToList.size();
    for (i = 0; i < cSize; i++){
        ngb_id = chare->sendToList[i].getNeighborId();
        ngb_proc = tasks[ngb_id].getNewPe();
        if (ngb_proc < pSize){ //can only change the load of the neighbor's PU if it is mapped somewhere
            new_comm_cost = costs.getCommCost(topology, ngb_proc, newProc);          //new latency and bandwidth
            latency = chare->sendToList[i].getNumMsgs() * new_comm_cost.latency;      //new latency
            bandwidth =  chare->sendToList[i].getNumBytes()/ new_comm_cost.bandwidth; //new bw
            
            if (currentProc < pSize){ //if the task is currently mapped somewhere
                old_comm_cost = costs.getCommCost(topology, ngb_proc, currentProc);      //old latency and bandwidth
                latency -= chare->sendToList[i].getNumMsgs() * old_comm_cost.latency; //subtract the old latency
                bandwidth -= chare->sendToList[i].getNumBytes()/ old_comm_cost.bandwidth; //subtract the old bw
            }

            //latency and bandwidth differences
            loads[ngb_proc] += latency*LATFACTOR + bandwidth/BANDFACTOR;   //changes cost to ns
        }
    }

    cSize = chare->mcastToList.size();
    for (i = 0; i < cSize; i++){
        destSize = chare->mcastToList[i].destList.size(); 
        for( j = 0 ; j < destSize ; j++ ){ 
            ngb_id = chare->mcastToList[i].destList[j];
            ngb_proc = tasks[ngb_id].getNewPe();
            if (ngb_proc < pSize){ //can only change the load of the neighbor's PU if it is mapped somewhere
                new_comm_cost = costs.getCommCost(topology, ngb_proc, newProc);          //new latency and bandwidth
                latency = (chare->mcastToList[i].getNumMsgs()/destSize) * new_comm_cost.latency;
                bandwidth = (chare->mcastToList[i].getNumBytes()/destSize)/ new_comm_cost.bandwidth; //new bw

                if (currentProc < pSize){ //if the task is currently mapped somewhere
                    old_comm_cost = costs.getCommCost(topology, ngb_proc, currentProc);      //old latency and bandwidth
                    latency -= (chare->mcastToList[i].getNumMsgs()/destSize) * old_comm_cost.latency; //subtract the old latency
                    bandwidth -= (chare->mcastToList[i].getNumBytes()/destSize)/ old_comm_cost.bandwidth; //subtract the old bw
                }

                //latency and bandwidth differences
                loads[ngb_proc] += latency*LATFACTOR + bandwidth/BANDFACTOR;   //changes cost to ns
            }
        }
    }

    /** 3 **/
    latency = 0.0;
    bandwidth = 0.0;
    cSize = chare->recvFromList.size();
    for (i = 0; i < cSize; i++){
        ngb_id = chare->recvFromList[i].getNeighborId();
        ngb_proc = tasks[ngb_id].getNewPe();
        if (ngb_proc < pSize){ //can only change the load related to a neighbor if it is mapped somewhere
            comm_cost = costs.getCommCost(topology, newProc, ngb_proc);
            latency += chare->recvFromList[i].getNumMsgs() * comm_cost.latency;
            bandwidth += chare->recvFromList[i].getNumBytes() / comm_cost.bandwidth;
        }
    }
    cSize = chare->mcastFromList.size();
    for (i = 0; i < cSize; i++){
        ngb_id = chare->mcastFromList[i].getSrc();
        ngb_proc = tasks[ngb_id].getNewPe();
        if (ngb_proc < pSize){ //can only change the load related to a neighbor if it is mapped somewhere
            comm_cost = costs.getCommCost(topology, newProc, ngb_proc);
            latency += chare->mcastFromList[i].getNumMsgs() * comm_cost.latency;
            bandwidth += chare->mcastFromList[i].getNumBytes() / comm_cost.bandwidth;
        }
    }
    extraLoad = latency*LATFACTOR + bandwidth/BANDFACTOR;   //changes cost to ns
    loads[newProc] += extraLoad;

    return extraLoad;
}

double HwTopoLB::computeNewMaxProcLoad( int chareId, int newProc ){
    double *NewLoads;       // array of new processor loads
    double maxLoad = 0.0;   // new maximum processor load
    int p;                  // processor iterator
    int pSize = pus.size();

    NewLoads = new double[pSize];

    for( p=0;p<pSize;p++ ){ //initializes the new loads with the old loads
        NewLoads[p] = pus[p].getTotalLoad();
    }

    changeLoads( chareId, newProc, NewLoads ); //changes the loads consider the migration

    for( p=0;p<pSize;p++ ){ //get the new maximum load
        if( maxLoad <= NewLoads[p] ) maxLoad = NewLoads[p];
    }

    delete NewLoads;
    return maxLoad;
}

//Pre-process tasks and PUs. Adds communication costs to the loads.
//Returns a list of tasks per PU
std::vector<int>* HwTopoLB::preprocess(int cSize, int pSize){
    std::vector<int> *CharesOnProcs;
    int c, p, comm, commChares, ngb_id, ngb_proc;
    double latency, bandwidth, commCostChare;
    Vertex *chare;
    ProcInfo *processor;
    struct comm_t comm_cost;

    CharesOnProcs = new std::vector<int>[pSize];
    OriginalLoads = new double[cSize];  //global

    //Computing the total load of a processor: Computation + Communication - Overhead
    //Create a list of chares per processor and update chares processor
    for (c = 0; c < cSize; c++){
        chare = &tasks[c];
        OriginalLoads[c] = chare->getVertexLoad(); //stores current load before changing it
        p = chare->getCurrentPe();      //gets current processor
        if(p >= pSize) continue;        //if the task is not yet mapped, there is nothing to do here

        CharesOnProcs[p].push_back(c);  //adds chare to the list of chares in that processor
        processor = &pus[p];    //pointer to the processor

        //adds the communication costs related to other chares
        latency = 0.0;
        bandwidth = 0.0;

        commChares = chare->recvFromList.size();    //gets communication list
        for (comm = 0; comm < commChares; comm++){ //adds communication cost per neighbor
            ngb_id = chare->recvFromList[comm].getNeighborId();     //neighbor's id
            ngb_proc = tasks[ngb_id].getCurrentPe();        //neighbor's processor
            if(ngb_proc >= pSize) continue;        //if the neighbor task is not yet mapped, there is nothing to do here

            comm_cost = costs.getCommCost(topology, p, ngb_proc);
            latency += chare->recvFromList[comm].getNumMsgs()*          //communication cost
                       comm_cost.latency;
            bandwidth += chare->recvFromList[comm].getNumBytes()/
                         comm_cost.bandwidth;
        }

        commChares = chare->mcastFromList.size();    //gets communication list
        for (comm = 0; comm < commChares; comm++){ //adds communication cost per neighbor
            ngb_id = chare->mcastFromList[comm].getSrc();     	//neighbor's id
            ngb_proc = tasks[ngb_id].getCurrentPe();        //neighbor's processor
            if(ngb_proc >= pSize) continue;        //if the neighbor task is not yet mapped, there is nothing to do here
            
            comm_cost = costs.getCommCost(topology, p, ngb_proc);
            latency += chare->mcastFromList[comm].getNumMsgs()*          //communication cost
                       comm_cost.latency;
            bandwidth += chare->mcastFromList[comm].getNumBytes()/
                         comm_cost.bandwidth;
        }

        commCostChare = latency*LATFACTOR + bandwidth/BANDFACTOR;   //changes cost to ns
        chare->setVertexLoad(chare->getVertexLoad() + commCostChare);   // adds communication costs
        processor->setTotalLoad(processor->getTotalLoad() + commCostChare); // adds it to the procesosr too
    }

    return CharesOnProcs;
}

int HwTopoLB::choosePU(int pSize, std::vector<int> *CharesOnProcs) {
    //Find most loaded processor
    double maxProcLoad;
    int chosenProc, p;

    if (unif() <= alpha){   //choose the slowest PU with prob. alpha
        maxProcLoad = 0.0;   //load of the most loaded processor
        chosenProc = -1;      //most loaded processor
        
        for (p = 0; p < pSize; p++){
            //checks if the PU is available and has tasks on it
            if (pus[p].isAvailable() && CharesOnProcs[p].size()){
                //checks if it has the largest Load
                if (maxProcLoad <= pus[p].getTotalLoad()){
                    maxProcLoad = pus[p].getTotalLoad();
                    chosenProc = p;
                }
            }
        }
    	//CkPrintf("[%d] Chosen proc = %d (%d) with %d tasks.\n", CkMyPe(), chosenProc, pSize, CharesOnProcs[chosenProc].size());
    }
    else {                  //otherwise, choose any PU uniformly
        #define CHOOSEPROCLIMIT 1000
        for (p = 0; p < CHOOSEPROCLIMIT; p++){
            chosenProc = floor((pSize-1)*unif());
            //guarantees that the chosen PU is available and has tasks
            if (pus[chosenProc].isAvailable() && CharesOnProcs[chosenProc].size()) break;
        }
        if (p == CHOOSEPROCLIMIT) chosenProc = -1;  //did not find a PU after all iterations
    	//CkPrintf("[%d] Chosen proc = %d (%d) with %d tasks.\n", CkMyPe(), chosenProc, pSize, CharesOnProcs[chosenProc].size(), p);
    }

    if (chosenProc == -1) CmiAbort("HwTopoLB: cannot find an available PE with chares on it! Aborting!\n");

    return chosenProc;
}


int HwTopoLB::chooseTask(int chosenProc, std::vector<int> *CharesOnProcs){
    double maxChareLoad;
    int chosenChare, cSize, c, tempId;
    Vertex *chare;

    cSize = CharesOnProcs[chosenProc].size();   //number of tasks on the chosen PU
    if(unif() <= beta){    //choose the heaviest task with prob beta
        chosenChare = -1;
        maxChareLoad = -1000000.0;
        for (c = 0; c < cSize; c++){
            tempId = CharesOnProcs[chosenProc][c];
            chare = &tasks[tempId];      //gets one of the chares of the chosen core
            if (chare->isMigratable()){     //guarantees that we are choosing a migratable task
                if (maxChareLoad <= chare->getVertexLoad()){
                    maxChareLoad = chare->getVertexLoad();
                    chosenChare = c;
                }
            }
        }
        //CkPrintf("[%d] Chosen chare = %d (%d) from %d (%d).\n", CkMyPe(), chosenChare, cSize, chosenProc, tasks[CharesOnProcs[chosenProc][chosenChare]].isMigratable());
    }
    else {  //choose any other task uniformly
        #define CHOOSECHARELIMIT 100
        for (c = 0; c < CHOOSECHARELIMIT; c++){
            chosenChare = floor((cSize-1)*unif());  //1-beta of choosing another one
            tempId = CharesOnProcs[chosenProc][chosenChare];
            chare = &tasks[tempId];
            if (chare->isMigratable()) break;
        }
        //CkPrintf("[%d] Chosen chare = %d (%d) from %d (%d) after %d tries.\n", CkMyPe(), chosenChare, cSize, chosenProc, tasks[CharesOnProcs[chosenProc][chosenChare]].isMigratable(), c);
        if (c == CHOOSECHARELIMIT) chosenChare = -1; 
    }

    if (chosenChare == -1) CmiAbort("HwTopoLB: cannot find a migratable chare! Aborting!\n");

    return CharesOnProcs[chosenProc][chosenChare];
}


double HwTopoLB::computeCurrentMaxProcLoad(int pSize) {
    int p;
    double maxProcLoad = 0.0;
    for (p = 0; p < pSize; p++){
        if (maxProcLoad <= pus[p].getTotalLoad()) maxProcLoad = pus[p].getTotalLoad();
    }
    return maxProcLoad;
}

int HwTopoLB::chooseMapping (int pSize, int chosenProc, int chosenChare){
    int p, newProc, i;
    double sum;
    double maxcost = 0.0;
    double cost, prob;
    double *CostArray = new double[pSize];             // Cost array (for Gibbs distribution)
    double *ProbArray = new double[pSize];             // Probability array (for Gibbs distribution)
    double local_temperature = temperature;		// Factor to avoid problems with exponentiation
    /* To compute all possible mappings, we have to
     * 4.1) Consider each processor
     * 4.2) Consider the chares that communicate with the chosenChare
     * 4.3) Evaluate how the migration affects the makespan
     * */
    for (p = 0; p < pSize; p++){  /** 4.1 **/
        if (pus[p].isAvailable()){ //only available PUs have costs computed
            if( p == chosenProc ){ //if this is our current processor, there is nothing to compute
                cost = computeCurrentMaxProcLoad( pSize ); 
        	//CkPrintf("[%d] Cost %d = %lf\n", CkMyPe(), p, cost);
            } else { //we have to compute the new makespan
                /** 4.2 and 4.3 **/
                cost = computeNewMaxProcLoad( chosenChare, p );
        	//CkPrintf("[%d] Cost %d = %lf\n", CkMyPe(), p, cost);
            }
	    if (cost > maxcost) maxcost = cost;
	    CostArray[p] = cost;
        } else {
            CostArray[p] = 123456.789; //temporary value, will not be used
        }
    }

    /***** 4.99) Guarantee that costs will not results in -nan mapping *****/
    prob = exp(-maxcost/local_temperature);
    while (!(prob > 0)){
	local_temperature *= 2.0;
    	prob = exp(-maxcost/local_temperature);
    }
    //CkPrintf("[%d] Temperature adjusment = %lf\n", CkMyPe(), local_temperature/temperature);

    /***** 5) Choose one mapping *****/
    sum = 0.0;
    for (p = 0; p < pSize; p++){
        if (pus[p].isAvailable()){ //only available PUs provide values
            CostArray[p] = exp(-CostArray[p]/local_temperature);  //top part of the gibbs distribution
            sum += CostArray[p];    //bottom part of the gibbs distribution
        }
    }
    for (p = 0 ; p < pSize; p++){ 
        if (pus[p].isAvailable()){ //only available PUs have costs computed
            ProbArray[p] = CostArray[p]/sum;    //gibbs distribution for each i = 1..n
        } else {
            ProbArray[p] = 0.000;               //unavailable PUs have no chance of being chosen
        }
        //CkPrintf("[%d] Prob %d = %lf\n", CkMyPe(), p, ProbArray[p]);
    }
    //choose the processor using this distribution
    float randInt = unif();
    float temp = ProbArray[0];
    i = 0;
    while (temp < randInt){
        i++;
        temp+=ProbArray[i];
    }  
    newProc = i;    //new processor for the chosen chare
    if (newProc >= pSize) newProc = pSize-1; //just a small check to guarantee that rounding error did not mess up this
    
    //CkPrintf("[%d] New mapping = %d with prob %lf (old = %d)\n", CkMyPe(), newProc, ProbArray[newProc], chosenProc);

    delete CostArray;
    delete ProbArray;

    return newProc;
}


bool HwTopoLB::applyMapping(int pSize, int chosenProc, int newProc, int chosenChare, std::vector<int> *CharesOnProcs, LDStats* stats){
    int cSize, c, p;
    bool iterate;
    Vertex *chare;

    if (newProc == chosenProc){
        //currently, if we choose not to migrate this chare, we stop
        //nothing to do here
        iterate = false;
    } else {
        //we will migrate the chosen chare for this new processor
        //we have to correct all loads
        iterate = true;
        double extraLoad;
        for (p = 0; p < pSize; p++){
            NewLoadArray[p] = pus[p].getTotalLoad();
        }
        extraLoad = changeLoads( chosenChare, newProc, NewLoadArray );
        for (p = 0; p < pSize;p ++){
            pus[p].setTotalLoad( NewLoadArray[p] );
        }
        //and to set its new processor
        chare = &tasks[chosenChare];
        chare->setVertexLoad(OriginalLoads[chosenChare] + extraLoad); //correct chare load
        chare->setNewPe(newProc); //set new mapping
        stats->to_proc[chosenChare] = newProc;

        CharesOnProcs[newProc].push_back(chosenChare);  //adds the chare to the new processor list

        if (chosenProc < pSize){ //checks if we are not mapping a task from an unexisting PU
            cSize = CharesOnProcs[chosenProc].size();
            for (c = 0; c < cSize; c++){
                if (CharesOnProcs[chosenProc][c] == chosenChare){  //finds the chare on the old processor list
                    CharesOnProcs[chosenProc].erase(CharesOnProcs[chosenProc].begin()+c); //removes it
                    break;
                }
            }
        }
    }

    return iterate;
}

#include "HwTopoLB.def.h"
