/*****************************************************************************
 * $Source$
 * $Author$ Laércio Pilla
 * $Date$ 06-2013
 * $Revision$ 1.0
 *****************************************************************************/

#include "TopologyAwareLB.h"

CreateLBFunc_Def(TopologyAwareLB, "Topology-aware base for load balancing algorithms.");

/***********************************************************************/
void TopologyAwareLB::init (){
//    init(XMLFILE);
}

/***********************************************************************/
void TopologyAwareLB::init (char* xmlfile){

    CkPrintf("[%d] XML file: %s\n", CkMyPe(), xmlfile);
    hwloc_topology_init(&topology);
    hwloc_topology_set_xml(topology, xmlfile);
    hwloc_topology_set_userdata_import_callback(topology, import_comm_costs);
    hwloc_topology_load(topology);
}

/***********************************************************************/
TopologyAwareLB::TopologyAwareLB(const CkLBOptions &opt): CentralLB(opt)
{
    init();
    if (CkMyPe() == 0)
        CkPrintf("[%d] TopologyAwareLB created\n",CkMyPe());
}

TopologyAwareLB::TopologyAwareLB(CkMigrateMessage *m):CentralLB(m) {
    init();
}

CmiBool TopologyAwareLB::QueryBalanceNow(int _step)
{
    //  CkPrintf("[%d] Balancing on step %d\n",CkMyPe(),_step);
    return CmiTrue;
}

/***********************************************************************/
void TopologyAwareLB::work(LDStats *stats) {

    //Does a basic parsing
    pus = ParsePUs(stats);
    tasks = ParseTasks(stats);

    // Statistics received by the the load balancer about the last iterations
    // of its PUs
    if(_lb_args.debug()){
       ProfileData();
    }
}

/***********************************************************************/
/* Parse and process the processing units array */
std::vector< ProcInfo > TopologyAwareLB::ParsePUs (BaseLB::LDStats *stats){
    std::vector<ProcInfo> procs;
    int i;
    int n_pus = stats->nprocs();
    for (i = 0; i < n_pus; i++){
        procs.push_back( ProcInfo(  i, 
                                    (stats->procs[i].bg_walltime)*stats->procs[i].pe_speed, 
                                    (stats->procs[i].total_walltime - stats->procs[i].idletime)*stats->procs[i].pe_speed,
                                    stats->procs[i].pe_speed, 
                                    stats->procs[i].available ) );
    } 
    return procs;
}

/***********************************************************************/
/* Parse and process the tasks array */
std::vector< Vertex > TopologyAwareLB::ParseTasks (BaseLB::LDStats *stats){
    std::vector<Vertex> vertices;
    int i, pu, from, to, edge, n_objs, offset, id;
    double load;
    bool migratable;
    int n_tasks = stats->n_objs;
    int n_pus = stats->nprocs();

    //adds tasks to the Vertex vector
    for (i = 0; i < n_tasks; i++){
        load = stats->objData[i].wallTime;
        migratable = stats->objData[i].migratable;
        pu = stats->from_proc[i];

        if (!migratable){ //checks if a non migratable task will crash the load balancer
            //non migratable task from a PU that "does not exist"
            if (pu >= n_pus) CmiAbort("LB: nonmigratable object on a PE that does not exist! Aborting!\n");
            //non migratable task on an unavailable PU
            if (!stats->procs[pu].available) CmiAbort("LB: nonmigratable object on an unavailable PE! Aborting!\n");
        }
        if (pu < n_pus){ //if mapped to an existing PU, multiple its time by the PU's speed
            load = load * stats->procs[pu].pe_speed;
        }

        //add task to tthe vector
        vertices.push_back( Vertex(i, load, migratable, pu, pu) );
    }

    //adds the communication graph to the Vertex vector
    stats->makeCommHash();
    for(edge = 0; edge < stats->n_comm; edge++) {
        LDCommData &commData = stats->commData[edge];
        // ensure that the message is not from a processor but from an object
        if (!commData.from_proc()){
            // and that the type is an object to object message
            if (commData.recv_type()==LD_OBJ_MSG) {
                from = stats->getHash(commData.sender);
                to = stats->getHash(commData.receiver.get_destObj());

                if ((from != -1) && (to != -1)){ //ignores in the case that one of the tasks is not found
                    vertices[from].sendToList.push_back(Edge(to, commData.messages, commData.bytes));
                    vertices[to].recvFromList.push_back(Edge(from, commData.messages, commData.bytes));
                }
            } //else if a multicast list
            else if (commData.recv_type() == LD_OBJLIST_MSG){
                LDObjKey *objs = commData.receiver.get_destObjs(n_objs);
                McastSrc sender(n_objs, commData.messages, commData.bytes);
                from = stats->getHash(commData.sender);
                offset = vertices[from].mcastToList.size();
                
                if (from != -1){ //ignores in the case that the sender is not found
                    for (i = 0; i < n_objs; i++) {
                        id = stats->getHash(objs[i]);
                        if (id != -1){ //ignores in the case of a receiver is not found
                            vertices[id].mcastFromList.push_back(McastDest(from, offset, commData.messages, commData.bytes));
                            sender.destList.push_back(id);
                        }
                    }
                    vertices[from].mcastToList.push_back(sender);
                }
            }
        }
    }
    return vertices;
}

/****************************************************************************/
/*** General profiling functions ***/
/****************************************************************************/
void TopologyAwareLB::ProfileData (){
    std::vector<double> profiledData, profiledData2;
    unsigned int i;
    double start, end;

    start = CmiWallTimer();
    CkPrintf("Data\tAverage\tMedian\tMax\tMin\tTotal\n", CkMyPe());
    //Number of chares per processor
    profiledData = TasksPerPU();
    CkPrintf("[%d] Chares per processor\t", CkMyPe());
    PrintVector (profiledData);
    
    //Chare load
    profiledData = TasksLoadVector();
    CkPrintf("[%d] Chare load\t", CkMyPe());
    PrintVector (profiledData);

    //Chare messages
    profiledData = TasksMessageVector();
    CkPrintf("[%d] Chare message\t", CkMyPe());
    PrintVector (profiledData);

    //Chare load
    profiledData = TasksBytesVector();
    CkPrintf("[%d] Chare bytes\t", CkMyPe());
    PrintVector (profiledData);

    //Processor load
    profiledData = PULoadVector();
    CkPrintf("[%d] Processor load\t", CkMyPe());
    PrintVector (profiledData);

    //Processor overhead
    profiledData = PUOverheadVector();
    CkPrintf("[%d] Processor overhead\t", CkMyPe());
    PrintVector (profiledData);

    CkPrintf("-------------------------------\n");
    //Messages in the topology
    profiledData = TasksMessageMatrix();
    CkPrintf("[%d] Messages in the topology\t", CkMyPe());
    PrintTopologyVector(profiledData);
    
    //Bytes in the topology
    profiledData2 = TasksBytesMatrix();
    CkPrintf("[%d] Bytes in the topology\t", CkMyPe());
    PrintTopologyVector(profiledData2);

    //Bytes per message in the topology
    CkPrintf("[%d] Bytes per message in the topology\t", CkMyPe());
    PrintTopologyBpM(profiledData, profiledData2);
    end = CmiWallTimer();
    CkPrintf("[%d] LB Profiling time: %lf\n", CkMyPe(), end - start);

    return;
}

/****************************************************************************/
/* Number of chares per processor as vector */
std::vector<double> TopologyAwareLB::TasksPerPU (){
    int i, procSize, objSize, proc;
    procSize = pus.size();
    std::vector<double> data(procSize);
    objSize = tasks.size();
    
    for (i = 0; i < objSize; i++){
        proc = tasks[i].getCurrentPe();
        if ((proc >= 0) && (proc < procSize)) data[proc]++; 
    }
    return data;
}

/****************************************************************************/
/* Chare load as vector */
std::vector<double> TopologyAwareLB::TasksLoadVector (){
    int i, size;
    size = tasks.size();
    std::vector<double> data(size);

    for (i = 0; i < size; i++){
        data[i] = tasks[i].getVertexLoad();
    }
    return data;
}

/****************************************************************************/
/* Chare messages as vector */
std::vector<double> TopologyAwareLB::TasksMessageVector (){
    unsigned int i, j, size;
    size = tasks.size();
    std::vector<double> data(size);

    for (i = 0; i < size; i++){
        data[i] = 0.0;
        for (j = 0; j < tasks[i].recvFromList.size(); j++){
            data[i] += tasks[i].recvFromList[j].getNumMsgs();
        }
        for (j = 0; j < tasks[i].mcastFromList.size(); j++){
            data[i] += tasks[i].mcastFromList[j].getNumMsgs();
        }
    }
    return data;
}

/****************************************************************************/
/* Chare bytes as vector */
std::vector<double> TopologyAwareLB::TasksBytesVector (){
    unsigned int i, j, size;
    size = tasks.size();
    std::vector<double> data(size);

    for (i = 0; i < size; i++){
        data[i] = 0.0;
        for (j = 0; j < tasks[i].recvFromList.size(); j++){
            data[i] += tasks[i].recvFromList[j].getNumBytes();
        }
        for (j = 0; j < tasks[i].mcastFromList.size(); j++){
            data[i] += tasks[i].mcastFromList[j].getNumBytes();
        }
    }
    return data;
}

/****************************************************************************/
/* Processor load as vector */
std::vector<double> TopologyAwareLB::PULoadVector (){
    int i, size;
    size = pus.size();
    std::vector<double> data(size);

    for (i = 0; i < size; i++){
        data[i] = pus[i].getTotalLoad();
    }
    return data;
}

/****************************************************************************/
/* Processor overhead as vector */
std::vector<double> TopologyAwareLB::PUOverheadVector (){
    int i, size;
    size = pus.size();
    std::vector<double> data(size);

    for (i = 0; i < size; i++){
        data[i] = pus[i].overhead();
    }
    return data;
}

/****************************************************************************/
/* Messages for each pair of processors */
std::vector<double> TopologyAwareLB::TasksMessageMatrix (){
    unsigned int i, j, procSize, objSize, origProc, neighProc, neigh;
    procSize = pus.size();
    objSize = tasks.size();
    std::vector<double> data(procSize*procSize,0.0);

    for (i = 0; i < objSize; i++){
        origProc = tasks[i].getCurrentPe();
        if ((origProc >= 0) && (origProc < procSize)){ //Can only do this evaluation for mapped tasks
            for (j = 0; j < tasks[i].recvFromList.size(); j++){
                neigh = tasks[i].recvFromList[j].getNeighborId();
                neighProc = tasks[neigh].getCurrentPe();
                if ((neighProc >= 0) && (neighProc < procSize)) data[origProc*procSize + neighProc] += tasks[i].recvFromList[j].getNumMsgs();
            }
            for (j = 0; j < tasks[i].mcastFromList.size(); j++){
                neigh = tasks[i].mcastFromList[j].getSrc();
                neighProc = tasks[neigh].getCurrentPe();
                if ((neighProc >= 0) && (neighProc < procSize)) data[origProc*procSize + neighProc] += tasks[i].mcastFromList[j].getNumMsgs();
            }
        }
    }
    return data;
}

/****************************************************************************/
/* Bytes for each pair of processors */
std::vector<double> TopologyAwareLB::TasksBytesMatrix (){
    unsigned int i, j, procSize, objSize, origProc, neighProc, neigh;
    procSize = pus.size();
    objSize = tasks.size();
    std::vector<double> data(procSize*procSize,0.0);

    for (i = 0; i < objSize; i++){
        origProc = tasks[i].getCurrentPe();
        if ((origProc >= 0) && (origProc < procSize)){ //Can only do this evaluation for mapped tasks
            for (j = 0; j < tasks[i].recvFromList.size(); j++){
                neigh = tasks[i].recvFromList[j].getNeighborId();
                neighProc = tasks[neigh].getCurrentPe();
                if ((neighProc >= 0) && (neighProc < procSize)) data[origProc*procSize + neighProc] += tasks[i].recvFromList[j].getNumBytes();
            }
            for (j = 0; j < tasks[i].mcastFromList.size(); j++){
                neigh = tasks[i].mcastFromList[j].getSrc();
                neighProc = tasks[neigh].getCurrentPe();
                if ((neighProc >= 0) && (neighProc < procSize)) data[origProc*procSize + neighProc] += tasks[i].mcastFromList[j].getNumBytes();
            }
        }
    }
    return data;
}

/***********************************************************************/
/*** Data is printed as (average) (median) (max) (min) (total) ***/
void TopologyAwareLB::PrintVector (std::vector<double> infoVector){
    int i, size;
    double maximum, minimum, average, median, total;

    sort(infoVector.begin(), infoVector.end()); //sorts data
    size = infoVector.size();
    minimum = infoVector[0];
    maximum = infoVector[size-1];
    median = infoVector[size/2];
    total = 0.0;
    for (i = 0; i < size; i++) total += infoVector[i];
    average = total / (double) size;

    CkPrintf("%lf\t%lf\t%lf\t%lf\t%lf\n", average, median, maximum, minimum, total);

    return;
}

/***********************************************************************/
void TopologyAwareLB::PrintTopologyVector (std::vector<double> infoVector){
    int i, j, procSize, topoSize, level;
    hwloc_obj_t core1, core2, common;
    procSize = pus.size();
    topoSize = hwloc_topology_get_depth(topology);
    std::vector<double> data(topoSize,0.0);

    //gathers data
    for (i = 0; i < procSize; i++){ //iterates over all cores
        core1 = hwloc_get_pu_obj_by_os_index(topology, i);
        for (j = i; j < procSize; j++){ //iterates over all cores that haven't been checked yet
            core2 = hwloc_get_pu_obj_by_os_index(topology, j);
            common = hwloc_get_common_ancestor_obj(topology, core1, core2);
            level = common->depth;          //finds first shared level between cores
            if (i == j)  data[level] += infoVector[i*procSize + j];
            else data[level] += infoVector[i*procSize + j] + infoVector[j*procSize + i];
        }
    }
    //prints data
    for (i = topoSize; i > 0; i--){
        CkPrintf("%lf\t", data[i-1]);
    }
    CkPrintf ("\n");
    return;
}

/***********************************************************************/
void TopologyAwareLB::PrintTopologyBpM (std::vector<double> messages, std::vector<double> bytes){   /* Maps communication information to the topology (bytes per message)*/
    int i, j, procSize, topoSize, level;
    hwloc_obj_t core1, core2, common;
    procSize = pus.size();
    topoSize = hwloc_topology_get_depth(topology);
    std::vector<double> number(topoSize,0.0);
    std::vector<double> size(topoSize,0.0);

    //gathers data
    for (i = 0; i < procSize; i++){ //iterates over all cores
        core1 = hwloc_get_pu_obj_by_os_index(topology, i);
        for (j = i; j < procSize; j++){ //iterates over all cores that haven't been checked yet
            core2 = hwloc_get_pu_obj_by_os_index(topology, j);
            common = hwloc_get_common_ancestor_obj(topology, core1, core2);
            level = common->depth;          //finds first shared level between cores
            if (i == j){
                number[level] += messages[i*procSize + j];
                size[level] += bytes[i*procSize + j];
            } else {
                number[level] += messages[i*procSize + j] + messages[j*procSize + i];
                size[level] += bytes[i*procSize + j] + bytes[j*procSize + i];
            }
        }
    }
    //prints data
    for (i = topoSize; i > 0; i--){
        if (number[i-1] > 0.0)
            CkPrintf("%lf\t", size[i-1]/number[i-1]);
        else
            CkPrintf("%lf\t", 0.0);
    }
    CkPrintf ("\n");
    return;
}

struct comm_t CommunicationCosts::getCommCost(hwloc_topology_t topo, int i, int j){
    switch(_level){
        case LEVELTYPE_WHOLETOPOLOGY:
        case LEVELTYPE_COMPUTENODE:
            return get_comm(topo, i, j);
            break;
        case LEVELTYPE_NETWORK:
        default:
            return get_comm_net(topo, i, j);
            break;
    }

}

#include "TopologyAwareLB.def.h"
