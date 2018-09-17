/*****************************************************************************
 * $Source$
 * $Author$ Christiane Pousa, Laércio Pilla, Daniel Cordeiro
 * $Date$ 07-2013
 * $Revision$ 1.3
 *****************************************************************************/

#include "NucoLB.h"

#define NUCOLB_MAX_DOUBLE 1e29
#define NUCOLB_ALPHA 0.00001
#define CENTRALSIZE 

CreateLBFunc_Def(NucoLB, "Greedy algorithm which takes the communication graph and the NUCO factor into account. Tries to avoid too many migrations.")

void NucoLB::init (){
    topology_level = LEVELTYPE_WHOLETOPOLOGY;
    init(XMLFILE, -1);
}

void NucoLB::init (char* xmlfile, int nodesize){

    lbname = (char*)"NucoLB";
    #ifndef NUCOLB_ALPHA
    alpha = _lb_args.alpha();
    #else
    alpha = NUCOLB_ALPHA;
    #endif

    if (nodesize == -1){
        if (CkMyPe() == 0){
            CkPrintf("[%d] Centralized NucoLB starting\n",CkMyPe());
            CkPrintf("Alpha = %lf\n",alpha);

            TopologyAwareLB::init(xmlfile);
            discoverTopology(); //prepares topology information so different variations of NucoLB can work
        }
    }
    else {
        if (CkMyPe()%nodesize == 0){   //Only one LB per compute node
            CkPrintf("[%d] NucoLB starting\n",CkMyPe());
            
            TopologyAwareLB::init(xmlfile);
            discoverTopology(); //prepares topology information so different variations of NucoLB can work
        }
    }
}


NucoLB::NucoLB(const CkLBOptions &opt): TopologyAwareLB(opt)
{
    init();
    if (CkMyPe() == 0)
        CkPrintf("[%d] NucoLB created\n",CkMyPe());
}

NucoLB::NucoLB(CkMigrateMessage *m):TopologyAwareLB(m) {
    init();
}

CmiBool NucoLB::QueryBalanceNow(int _step)
{
    //  CkPrintf("[%d] Balancing on step %d\n",CkMyPe(),_step);
    return CmiTrue;
}

void NucoLB::work(LDStats *stats) {
    unsigned int i, obj, proc, comm, n, best_proc, ngb_id, ngb_proc, current_proc, n_pus, n_tasks;
    unsigned int node, ngb_node;
    double weight, best_weight, final_weight, local_lat, remote_lat, nuco_factor;
    double start, end;
    Vertex *task;
    ProcInfo *pu;
    ProcInfo *new_pu;

    double node_weight[nuco_nodes];
    int node_computed[nuco_nodes];
    
    /** ========================== INITIALIZATION ============================= */
    TopologyAwareLB::work(stats);

    start = CmiWallTimer();
    n_pus = pus.size();
    n_tasks = tasks.size();
    
    std::vector< Vertex > loads(tasks);	// Sorted list of objects loads
    std::sort(loads.begin(), loads.end(), Vertex::compareHigherVertexLoad); // Sorts objects by load

    #ifdef NOOVERHEAD
    CkPrintf("No overhead\n");
    for (proc = 0; proc < n_pus; proc++){
        pus[proc].setTotalLoad(pus[proc].getTotalLoad() - pus[proc].getOverhead()); 
    }
    #endif

    /** ============================= STRATEGY ================================ */
    //gets the minimal W(k,*) for each chare
    /* N = number of processors
     * K = number of chares
     * i,j = processors
     * k = chare
     * L(i) = load on processor i
     * NF(i,j) = NUMA Factor from i to j
     * M(k,i) = amount of bytes that chare k communicates with chares on processor i
     * W(k,i) = scheduling weight (likeability of chare k to migrate to processor i)
     *
     * W(k,i) = L(i) - M(k,i) + sum of j=1..N where j!=i (M(k,j)*NF(j,i))
     * optimization: gets M(k,i) directly from the communications with
     * chares
     */

    for (i = 0; i < n_tasks; i++){ //iterates through all chares
        obj = loads[i].getVertexId();
        if (!tasks[obj].isMigratable()) continue; //no need to evaluate a task that is not migratable

        //Setup for iteration for current task
        best_weight = NUCOLB_MAX_DOUBLE;
        best_proc = 0;

        for (n = 0; n < nuco_nodes; n++) { 
            node_computed[n] = 0; 
        }

        task = &tasks[obj];
        current_proc = task->getCurrentPe();

        if (current_proc < n_pus){ //checks if the task is in an existing PU
            pu = &pus[current_proc];
            //removes the task's load from its current PU
            pu->setTotalLoad(pu->getTotalLoad() - task->getVertexLoad());
        }

        //Iterates throught all possible PUs
        for (proc = 0; proc < n_pus; proc++){
            if (!pus[proc].isAvailable()) continue; //no need to evaluate a PU that is not available either

            //checks if the tasks weight has already been computed for this PU's NUMA node 
            node = getNode(proc);
            if (!node_computed[node]) {
                //only computes a new weight if it is not the same for the last processor
                //the weight will be the same if both processors are in the same NUMA node

                weight = 0.0;
                //stores local memory latency for computing the NUCO factor
                local_lat = getLocalLatency(node);

                //iterates over all communicating tasks
                for (comm = 0 ; comm < task->recvFromList.size(); comm++){
                    ngb_id = task->recvFromList[comm].getNeighborId();          //neighbor's id
                    ngb_proc = tasks[ngb_id].getNewPe();                //neighbor's processor
                    
                    //checks if the neighbor task is in an existing PU
                    //if not, ignores the task for the time being
                    if (ngb_proc < n_pus){

                        ngb_node = getNode(ngb_proc);

                        //finds if both PUs reside in the same NUMA node
                        if (node != ngb_node){
                            //different NUMA nodes
                            //CkPrintf("[%d] %d - %d\t %d - %d\n", CkMyPe(), proc, node, ngb_proc, ngb_node);
                            remote_lat = get_latency(topology, proc, ngb_proc);
//getRemoteLatency(node, ngb_node);
                            nuco_factor = remote_lat / local_lat;
                            weight += task->recvFromList[comm].getNumMsgs() * nuco_factor;
                        }
                        else {
                            weight -= task->recvFromList[comm].getNumMsgs();
                        }
                    }
                }   //end for comm
            }
            else {
                weight = node_weight[node];
            }

            final_weight = weight*alpha + pus[proc].getTotalLoad();
            //CkPrintf("Task %d\tPU %d\tNode %d\tWeight %8.3lf\tLoad %8.3lf\n", obj, proc, node, final_weight, pus[proc].getTotalLoad());
            if( final_weight < best_weight ){
                best_weight = final_weight;
                best_proc = proc;
            }
        }   //end for pus

        //found a PU for the evaluated task
        new_pu = &pus[best_proc];
        new_pu->setTotalLoad(new_pu->getTotalLoad() + task->getVertexLoad());
        task->setNewPe(best_proc);    //set new processor
        stats->to_proc[obj] = best_proc;
    }   //end for chares

    end = CmiWallTimer();
    if(_lb_args.debug()){
        CkPrintf("[%d] NucoLB time: %lf\n", CkMyPe(), end - start);
    }

    /** ============================== CLEANUP ================================ */
    //ogr->convertDecisions(stats);         // Send decisions back to LDStats

}

/***********************************************************************/
void NucoLB::discoverTopology (){
    int nb_nodes, nb_machines, nodes_depth, machines_depth;

    //checks the number of NUMA nodes in the system
    nodes_depth = hwloc_get_type_depth(topology, HWLOC_OBJ_NODE);
    if (nodes_depth == HWLOC_TYPE_DEPTH_UNKNOWN) {nb_nodes = 1;}
    else {nb_nodes = hwloc_get_nbobjs_by_depth(topology, nodes_depth);}

    //checks the number of machines in the system
    machines_depth = hwloc_get_type_depth(topology, HWLOC_OBJ_MACHINE);
    nb_machines = hwloc_get_nbobjs_by_depth(topology, machines_depth);
    assert(nb_machines > 0);

    //decisions are taken depending on the variation that NucoLB is working.
    switch(topology_level){
        case LEVELTYPE_COMPUTENODE: //shared memory only
            nuco_nodes = nb_nodes;          //# of NUMA nodes only
            nuco_depth = machines_depth;    //non-uniformity is stored at machine depth
            if (nb_nodes > 1) {local_depth = nodes_depth;}  //local level = memory level (NUMA machine)
            else {local_depth = machines_depth;}            //local level = machine level (UMA machine)
            break;

        case LEVELTYPE_WHOLETOPOLOGY:   //whole topology
            if (nb_nodes > nb_machines){    //NUMA system
                nuco_nodes = nb_nodes;          //# of NUMA nodes
                nuco_depth = machines_depth;    //non-uniformity is stored at least at machine depth
                local_depth = nodes_depth;      //local level = memory level
            }
            else {                          //UMA system
                nuco_nodes = nb_machines;       //# of machines
                local_depth = machines_depth;   //local level = machine level
                if (nb_machines > 1) {nuco_depth = machines_depth-1;}   //non-uniformity at system depth
                else {nuco_depth = machines_depth;}                     //non-uniformity is stored at least at machine depth
            }
            break;

        case LEVELTYPE_NETWORK:         //network only
        default:
            nuco_nodes = nb_machines;       //# of machines only
            nuco_depth = machines_depth-1;  //non-uniformity is stored at system depth
            local_depth = machines_depth;   //local level = machine level
            break;
    }

    return;

    //node extra cost vector
    assert(nuco_nodes > 0);
//    node_weight = new double[nuco_nodes];
//    node_computed = new int[nuco_nodes];
//    assert(node_weight != NULL);
//    assert(node_computed != NULL);
}


/***********************************************************************/
unsigned int NucoLB::getNode (unsigned int pu){
    hwloc_obj_t core, ancestor;
    unsigned int node;

    switch(topology_level){
        case LEVELTYPE_COMPUTENODE: //shared memory only
        case LEVELTYPE_WHOLETOPOLOGY:   //whole topology
            core = hwloc_get_pu_obj_by_os_index(topology, pu);                       //get the pu
            ancestor = hwloc_get_ancestor_obj_by_depth(topology, local_depth, core); //get the node or machine
            node = ancestor->logical_index;                                          //get the logical index
            break;

        case LEVELTYPE_NETWORK:         //network only
        default:
            if (pu >= nuco_nodes) { CmiAbort("The number of virtual processors is bigger than the number of machines. Aborting!\n"); }

            node = pu;                  //each machine counts as a node in the system
            break;
    }
    return node;
}

/***********************************************************************/
float NucoLB::getLocalLatency (unsigned int node){
    float latency;
    hwloc_obj_t obj;

    //the local depth can be a machine or a NUMA node. In both case, the cost
    //in position zero is the local cost
    obj = hwloc_get_obj_by_depth(topology, local_depth, node);
    latency = get_obj_latency(obj);
    return latency;
}

/***********************************************************************/
float NucoLB::getRemoteLatency (unsigned int local_node, unsigned int remote_node){
    float latency;
    hwloc_obj_t node, ngb_node;

    node = hwloc_get_obj_by_depth(topology, local_depth, local_node);
    ngb_node = hwloc_get_obj_by_depth(topology, local_depth, remote_node);
	//CkPrintf("%d (%d) & %d (%d) \n",node->logical_index, node->depth, ngb_node->logical_index, ngb_node->depth);
//	CkPrintf("[%d] Latency between two NUMA nodes %d (%d %d) and %d (%d %d)\n =", CkMyPe(), local_node, node->logical_index, node->os_index, remote_node, ngb_node->logical_index, ngb_node->os_index);
    latency = get_latency_objs(topology, node, ngb_node);
	CkPrintf("%lf\n",latency);
    return latency;
}


#include "NucoLB.def.h"

/*@}*/

