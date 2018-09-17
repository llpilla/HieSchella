#include "memory_profile.h"

/***********************************************************/
int main (int argc, char *argv[]) {
    hwloc_topology_t topo;
    hwloc_obj_t obj;
    int i,j,opt;
    int fast = FALSE;
    int diff_input = FALSE;
    int diff_output = FALSE;
    int plain = FALSE;
    int artificial = FALSE;
    char *input;
    char *output;
    int warmup = WARMUP;
    int repetitions = REPETITIONS;
    debug = FALSE;

    //reads inputs from user
    argc--;
    argv++;
    while (argc >= 1){
        opt = 1;
        if (*argv[0] == '-'){
            if ((!strcmp(argv[0], "-h")) || (!strcmp(argv[0], "--help"))){
                usage();
                exit(OK);
            }
            else if ((!strcmp(argv[0], "-f")) || (!strcmp(argv[0], "--fast")))
                fast = TRUE;
            else if ((!strcmp(argv[0], "-v")) || (!strcmp(argv[0], "--verbose")))
                debug = TRUE; 
            else if ((!strcmp(argv[0], "-p")) || (!strcmp(argv[0], "--plain")))
                plain = TRUE; 
            else if ((!strcmp(argv[0], "-a")) || (!strcmp(argv[0], "--artificial")))
                artificial = TRUE; 
            else {
                opt = 2;
                if (argc < 2) {
                    usage();
                    exit(INPUT_FAILURE);
                }
                if ((!strcmp(argv[0], "-w")) || (!strcmp(argv[0], "--warmup"))){
                    warmup = atoi(argv[1]);
                    if(warmup < 0){
                        printf("Warmup cannot be negative: %d\n", warmup);
                        exit(INPUT_FAILURE);
                    }
                }
                else if ((!strcmp(argv[0], "-r")) || (!strcmp(argv[0], "--repetitions"))){
                        repetitions = atoi(argv[1]);
                        if(repetitions < 1){
                            printf("Too few repetitions: %d\n", repetitions);
                            exit(INPUT_FAILURE);
                        }
                    }
                    else if ((!strcmp(argv[0], "-i")) || (!strcmp(argv[0], "--input"))){
                        input = argv[1];
                        diff_input = TRUE;
                    }
                    else if ((!strcmp(argv[0], "-o")) || (!strcmp(argv[0], "--output"))){
                        output = argv[1];
                        diff_output = TRUE;
                    }
                    else {
                        usage();
                        exit(INPUT_FAILURE);
                    }
            }
        }
        argc -= opt;
        argv += opt;
    }

    if(debug){
        printf("------------------------------\n");
        printf("Execution parameters\n");
        printf("Warmup iterations = %d\n", warmup);
        printf("Benchmark iterations = %d\n", repetitions);
        if(artificial) printf("Artificial latencies and bandwidths will be used instead of benchmarking.\n");
        else if(plain) printf("The same latency and bandwidth are going to be used for all topology levels. No benchmarking will be done.\n");
        printf("------------------------------\n\n");
    }

    // Load compute node topology
    hwloc_topology_init (&topo);
    if (diff_input){
        hwloc_topology_set_xml(topo, input);
    }
    hwloc_topology_load (topo);
  
    /**Initialization**/
    /**Gather information using hwloc**/

    //Number of memory nodes and processing units
    nb_nodes = hwloc_get_nbobjs_by_depth (topo, hwloc_get_type_depth (topo, HWLOC_OBJ_NODE));
    if (!nb_nodes) nb_nodes = 1;   //fix the number of NUMA nodes for UMA architectures
    nb_cores = hwloc_get_nbobjs_by_depth (topo, hwloc_get_type_depth (topo, HWLOC_OBJ_PU));
    assert(nb_cores > 0);
  
    //Number of cache levels (usually 3)
    for (obj = hwloc_get_root_obj (topo); obj->type != HWLOC_OBJ_CACHE; obj = obj->first_child);
    if (obj) {
        nb_cache_lvls = obj->attr->cache.depth;
    }
    else {
        printf ("No cache found; Aborting.\n"); 
        exit(HWLOC_FAILURE);
    }
    //Cache line size
    stride = obj->attr->cache.linesize*8;

    if(debug){
        printf("------------------------------\n");
        printf("Platform parameters\n");
        printf("# Processing Units = %d\n", nb_cores);
        printf("# Memory nodes =     %d\n", nb_nodes);
        printf("# Cache levels =     %d\n",nb_cache_lvls);
    }

    //Memory allocations
    mem_sizes = malloc (sizeof(hwloc_uint64_t)*(nb_cache_lvls+1));
    bench_sizes = malloc (sizeof(hwloc_uint64_t)*(nb_cache_lvls+1));
    cache_lats = malloc (sizeof(float)*nb_cache_lvls);
    cache_bws = malloc (sizeof(float)*nb_cache_lvls);
    mem_lats = malloc (sizeof(float*)*nb_nodes*nb_nodes);
    mem_bws = malloc (sizeof(float*)*nb_nodes*nb_nodes);

    //Gathers the size of each cache and memory level
    if (gather_memory_sizes (topo, mem_sizes, nb_cache_lvls+1, nb_nodes)) {
        printf("Error capturing memory sizes. Aborting.\n");
        exit(HWLOC_FAILURE);
    }

    //Computes the midpoints to be used by benchmarks
    if (compute_memory_for_benchmarks (mem_sizes, bench_sizes, nb_cache_lvls, stride)) {
        printf("Error computing midpoints. Aborting.\n");
        exit(HWLOC_FAILURE);
    }

    if(debug){
        printf("Cache line =         %d B\n",stride);
        printf("Memory sizes and midpoints:\n");
        for (i = 0; i < nb_cache_lvls; i++){
            printf("-- L%d cache:\tSize %ld B\t\t Midpoint %ld B\n", i+1, mem_sizes[i], bench_sizes[i]);
        }
        printf("-- Memory:\tSize %ld B\t Midpoint %ld B\n", mem_sizes[nb_cache_lvls], bench_sizes[nb_cache_lvls]);
        printf("------------------------------\n\n");
    }

    if(artificial) artificial_costs(topo, nb_nodes);
    else if(plain) plain_costs(nb_nodes);
    else {
        /**Benchmarking**/
        /**Benchmarks latency and bandwidth using lmbench (lat_mem_rd and bw_mem)**/
        benchmark_cache_latency (topo, cache_lats, bench_sizes, nb_cache_lvls, warmup, repetitions);
        benchmark_cache_bandwidth (topo, cache_bws, bench_sizes, nb_cache_lvls, warmup, repetitions);
        benchmark_memory_latency (topo, mem_lats, bench_sizes[nb_cache_lvls], nb_nodes, warmup, repetitions, fast);
        benchmark_memory_bandwidth (topo, mem_bws, bench_sizes[nb_cache_lvls], nb_nodes, warmup, repetitions, fast);
    }

    if(debug){
        printf("------------------------------\n");
        printf("Benchmarked parameters\n");
        printf("Cache latencies\n");
        for (i = 0; i < nb_cache_lvls; i++){
            printf("L%d Cache:           %f ns\n",i+1, cache_lats[i]);
        }
        printf("Cache bandwidths\n");
        for (i = 0; i < nb_cache_lvls; i++){
            printf("L%d Cache:           %f MB/s\n",i+1, cache_bws[i]);
        }
        printf("Memory latencies\n");
        for (i = 0; i < nb_nodes; i++){
            for (j = 0; j < nb_nodes; j++){
                printf ("%d reads from %d =  %f ns\n",i,j,mem_lats[i*nb_nodes+j]);
            }
        }
        printf("Memory bandwidths\n");
        for (i = 0; i < nb_nodes; i++){
            for (j = 0; j < nb_nodes; j++){
                printf ("%d reads from %d =  %f MB/s\n",i,j,mem_bws[i*nb_nodes+j]);
            }
        }
        printf("------------------------------\n\n");
    }
  
    /**Ending**/
    /**Add measured information to hwloc**/
    add_costs (topo, "Latency", cache_lats, mem_lats, nb_nodes);
    add_costs (topo, "Bandwidth", cache_bws, mem_bws, nb_nodes);

    /**Saves the topology on a file**/
    hwloc_topology_set_userdata_export_callback (topo, export_comm_costs);
    if (diff_output)
        hwloc_topology_export_xml (topo, output);
    else
        hwloc_topology_export_xml (topo, XMLFILE);

    /**Frees data structures**/
    free(mem_sizes);
    free(bench_sizes);
    free(cache_lats);
    free(cache_bws);
    free(mem_lats);
    free(mem_bws);
    free_hash();

  return 0;
} 

/***********************************************************/
void usage(){
   printf("Usage options\n");
   printf("  -h --help            Prints this message\n");
   printf("  -v --verbose         Includes additional information\n");
   printf("  -f --fast            Simplifies benchmarking using distances matrix\n");
   printf("  -w --warmup #N       Changes the number of warmup iterations (default value = %d\n",WARMUP);
   printf("  -r --repetitions #N  Changes the number of benchmark iterations (default = %d\n",REPETITIONS);
   printf("  -i --input file.xml  Uses a xml file instead of the original topology\n");
   printf("  -o --output file.xml Outputs the resulting xml to a different file\n");
   printf("  -p --plain           Gives the same value for latency and bandwidth to all topology levels\n");
   printf("  -a --artificial      Gives artificial values to latency and bandwidth (one order of magnitude per level). Has precedence over -p\n");
   printf("\n");
}

/***********************************************************/
void benchmark_cache_bandwidth (hwloc_topology_t topology, float* cache_bws, hwloc_uint64_t* bench_sizes, int nb_cache_lvls, int warm, int rep){
    int i;

    for (i = 0; i < nb_cache_lvls; i++){
        cache_bws[i] = compute_bandwidth (bench_sizes[i], warm, rep);
    }
}

/***********************************************************/
void benchmark_cache_latency (hwloc_topology_t topology, float* cache_lats, hwloc_uint64_t* bench_sizes, int nb_cache_lvls, int warm, int rep){
    int i;

    for (i = 0; i < nb_cache_lvls; i++){
        cache_lats[i] = compute_latency (bench_sizes[i], stride, warm, rep);
    }
}

/***********************************************************/
void benchmark_memory_latency (hwloc_topology_t topology, float* mem_lats, hwloc_uint64_t bench_size, int nb_nodes, int warm, int rep, int speed){
    if (nb_nodes > 1)
        benchmark_numa(topology, mem_lats, bench_size, nb_nodes, warm, rep, LAT, speed);
    else
        benchmark_uniform_memory(topology, mem_lats, bench_size, warm, rep, LAT);
}
/***********************************************************/
void benchmark_memory_bandwidth (hwloc_topology_t topology, float* mem_bws, hwloc_uint64_t bench_size, int nb_nodes, int warm, int rep, int speed){
    if (nb_nodes > 1)
        benchmark_numa(topology, mem_bws, bench_size, nb_nodes, warm, rep, BW, speed);
    else
        benchmark_uniform_memory(topology, mem_bws, bench_size, warm, rep, BW);
}

/***********************************************************/
void benchmark_uniform_memory (hwloc_topology_t topology, float* output, hwloc_uint64_t bench_size, int warm, int rep, int name){
  
    bind_to_core(topology, 0, 1);
    if (name == LAT)
        output[0] = compute_latency (bench_size, stride, warm, rep);
    else
        output[0] = compute_bandwidth (bench_size, warm, rep); //runs the benchmark
}
/***********************************************************/
void benchmark_numa (hwloc_topology_t topology, float* output, hwloc_uint64_t bench_size, int nb_nodes, int warm, int rep, int name, int speed){
    if (speed)
        benchmark_numa_fast(topology, output, bench_size, nb_nodes, warm, rep, name);
    else
        benchmark_numa_complete(topology, output, bench_size, nb_nodes, warm, rep, name);
}
/***********************************************************/
// Benchmarks NUMA nodes based on the distance matrix
void benchmark_numa_fast (hwloc_topology_t topology, float* output, hwloc_uint64_t bench_size, int nb_nodes, int warm, int rep, int name){
    int hash;
    int k, i, j, pos;
    int size = nb_nodes*nb_nodes;
    const struct hwloc_distances_s *distances;
    float dist;

    hash = alloc_hash(size);
    
    if (hash == NEW_HASH){
        //Get the distance matrix
        distances = hwloc_get_whole_distance_matrix_by_type(topology, HWLOC_OBJ_NODE);
        if (distances == NULL) {
            printf("No NUMA distance matrix found. Aborting.\n");
            exit(HWLOC_FAILURE);
        }

        //fill the hash with distances and pairs of NUMA nodes to guide our fast benchmarking
        fill_hash(distances, simplified_costs);
    }

    //Goes through the hash benchmarking the selected pairs of NUMA nodes
    if (debug){
        printf("------------------------------\n\n");
        printf("Fast benchmarking for NUMA machines\n");
    }
    for (k = 0; k < size; k++ ){
        if (simplified_costs[k].distance > NO_DISTANCE){
            //Found a distance that has not been benchmarked yet
            //Goes through a process similar to benchmark_numa_complete
            i = simplified_costs[k].source;
            bind_to_core(topology, i, nb_nodes);

            j = simplified_costs[k].dest;
            bind_to_memory(topology, j);

            if (debug){
                printf("Fast: %d reads from %d\n",i,j);
            }
            //stores costs in the hash
            if (name == LAT)
                simplified_costs[k].cost = compute_latency (bench_size, stride, warm, rep);
            else
                simplified_costs[k].cost = compute_bandwidth (bench_size, warm, rep); 

        }
    }
    if (debug){
        printf("------------------------------\n\n");
    }

    //Goes through the distance matrix to set the output matrix
    for (k = 0; k < size; k++ ){
        dist = distances->latency[k];
        pos = find_hash_position(dist, size, simplified_costs);
        output[k] = simplified_costs[pos].cost;
    }

}
/***********************************************************/
void benchmark_numa_complete (hwloc_topology_t topology, float* output, hwloc_uint64_t bench_size, int nb_nodes, int warm, int rep, int name){
    int i,j;
  
    for (i = 0; i < nb_nodes; i++){ //iterates process binding
        bind_to_core(topology, i, nb_nodes);

        for (j = 0; j < nb_nodes; j++){ //iterates memory binding
            bind_to_memory(topology, j);
            
            if (name == LAT)
                output[i*nb_nodes + j] = compute_latency (bench_size, stride, warm, rep);
            else
                output[i*nb_nodes + j] = compute_bandwidth (bench_size, warm, rep); 
        }
    }
}

/***********************************************************/
/* Goes through the topology tree and finds the size of the memory of each
 * level. The small the index, the lower the memory (index 0 would be a L1
 * cache) */
int gather_memory_sizes (hwloc_topology_t topology, hwloc_uint64_t* mem_sizes, int mem_lvls, int nb_nodes) {
    hwloc_obj_t obj;
    hwloc_obj_t node;
    int i = mem_lvls;   //index for the mem_sizes array. Will be subtracted before each use

    for (obj = hwloc_get_root_obj (topology); obj->type != HWLOC_OBJ_PU; obj = obj->first_child){
        switch(obj->type){
            case HWLOC_OBJ_CACHE:   //found a cache: gets it's size
                i--;
                mem_sizes[i] = obj->attr->cache.size;
                break;

            case HWLOC_OBJ_NODE:    //found a NUMA node: checks the size of all NUMA nodes and uses the smallest one
                node = obj;
                int j;
                hwloc_uint64_t size = obj->memory.local_memory;
                for (j = 0; j < nb_nodes; j++){
                    if (node->memory.local_memory < size) size = node->memory.local_memory;
                    node = node->next_cousin;
                }
                i--;
                mem_sizes[i] = size;
                break;

            case HWLOC_OBJ_MACHINE:   //checks if the machine is UMA.
                if (nb_nodes == 1){
                    i--;
                    mem_sizes[i] = obj->memory.local_memory;
                }
                break;
            default:
                break;
        }
    }
    return i;
}

/***********************************************************/
/* Computes the size of memory to be used by the benchmarks.
 * The size for each level is equal to the middle point between it and its lower level
 * in a log scale. We start with the size of a cache line for prefetching
 * (usually 512) for L1. */
int compute_memory_for_benchmarks (hwloc_uint64_t* mem_sizes, hwloc_uint64_t* bench_sizes, int nb_cache_lvls, int min_size) {
    double size;
    int i;
    //first case: L1
    size = exp ((log (mem_sizes[0]/min_size)/2) + log (min_size));
    bench_sizes[0] = size;  //convertion from double to uint64!
    if (bench_sizes[0] % 2) bench_sizes[0]++;  //becomes even if necessary

    for (i = 1; i <= nb_cache_lvls; i++){
        size = exp ((log (mem_sizes[i]/mem_sizes[i-1])/2) + log (mem_sizes[i-1]));
        bench_sizes[i] = size; //convertion from double to uint64!
        if (bench_sizes[i] % 2) bench_sizes[i]++;  //becomes even if necessary
    }

    return 0;
}

/***********************************************************/
/* Adds the costs to the topology tree.
 * One single value is used per cache and memory. In the case of a NUMA
 * machine, n^2 values are added, where n is the number of NUMA nodes. 
 * Starts from the leaves and goes in the direction of the root. */
void add_costs (hwloc_topology_t topology, const char* name, float* cache_costs, float* mem_costs, int nb_nodes){
    hwloc_obj_t obj, cousin;
    int i, depth, n, id;

    for (obj = hwloc_get_obj_by_type (topology, HWLOC_OBJ_PU, 0); obj != NULL; obj = obj->parent){
        switch(obj->type){
            case HWLOC_OBJ_CACHE: //adds one cost for that cache
                depth = obj->attr->cache.depth;
                n = hwloc_get_nbobjs_by_depth(topology, obj->depth);
                cousin = obj;
                for (i = 0; i < n; i++){ //sets cost to all caches in the same level
                    set_comm_cost_by_name(cousin, cache_costs[depth-1], name);
                    cousin = cousin->next_cousin;
                }
                break;

            case HWLOC_OBJ_NODE:  //adds one value for local memory access
                n = hwloc_get_nbobjs_by_type(topology, HWLOC_OBJ_NODE);
                cousin = obj;
                for (i = 0; i < n; i++){ //sets cost to all NUMA nodes
                    id = cousin->logical_index;  //finds the id of that NUMA node
                    set_comm_cost_by_name(cousin, mem_costs[id*nb_nodes + id], name);
                    cousin = cousin->next_cousin;
                }
                break;

            case HWLOC_OBJ_MACHINE: //adds one value for local memory access if UMA, matrix if NUMA
                if (nb_nodes > 1){ //NUMA machine -> adds the cost matrix
                    set_comm_cost_array_by_name(obj, mem_costs, nb_nodes*nb_nodes, name); //memory costs is a matrix
                } else {           //UMA machine -> adds a single value
                    set_comm_cost_by_name(obj, mem_costs[0], name); //memory costs is one value
                }
                break;
            default:
                break;
        }
    }
}

/***********************************************************/
/**Artificial latencies and bandwidths**/
void artificial_costs (hwloc_topology_t topology, int nb_nodes){
    float latency = BASE_LATENCY;
    float bandwidth = BASE_BANDWIDTH;
    int i, j;

    for(i = 0; i < nb_cache_lvls; i++){
        cache_lats[i] = latency;
        cache_bws[i] = bandwidth;
        latency *= 10.0;
        bandwidth /= 10.0;
    }

    if(nb_nodes > 1){
        float dist;
        const struct hwloc_distances_s *distances;
        distances = hwloc_get_whole_distance_matrix_by_type(topology, HWLOC_OBJ_NODE);
        if (distances == NULL) {
            printf("No NUMA distance matrix found. Aborting.\n");
            exit(HWLOC_FAILURE);
        }

        for(i = 0; i < nb_nodes; i++){
            for(j = 0; j < nb_nodes; j++){
                dist = distances->latency[i*nb_nodes + j];      //get the distance value for a pair of NUMA nodes
                mem_lats[i*nb_nodes + j] = dist*latency;
                mem_bws[i*nb_nodes + j] = bandwidth/dist;
            }
        }
    }
    else {
        mem_lats[0] = latency;
        mem_bws[0] = bandwidth;
    }
}

/***********************************************************/
/**All levels in the machine topology receive the same latency and bandwidth**/
void plain_costs (int nb_nodes){
    int i, j;
    
    for(i = 0; i < nb_cache_lvls; i++){
        cache_lats[i] = PLAIN_LATENCY;
        cache_bws[i] = PLAIN_BANDWIDTH;
    }

    for(i = 0; i < nb_nodes; i++){
        for(j = 0; j < nb_nodes; j++){
            mem_lats[i*nb_nodes + j] = PLAIN_LATENCY;
            mem_bws[i*nb_nodes + j] = PLAIN_BANDWIDTH;
        }
    }

}

/***********************************************************/
inline int alloc_hash(int size){
    int i;

    if (simplified_costs == NULL){
        simplified_costs = (struct comm_hash_t *) malloc(sizeof(comm_hash)*size);
        for (i = 0; i < size; i++){
            simplified_costs[i].distance = NO_DISTANCE;
        }
        return NEW_HASH;
    }
    else {
        return OLD_HASH;
    }
}



/***********************************************************/
inline void free_hash(){
    if (simplified_costs != NULL)
        free(simplified_costs);
}

/***********************************************************/
void fill_hash(const struct hwloc_distances_s *distances, struct comm_hash_t *hash){
    int size = distances->nbobjs;
    int i, j, pos;
    float dist;
    int total_size = size*size;

    for (j = 0; j < size; j++){
        for (i = 0; i < size; i++){
            dist = distances->latency[i*size + j];      //get the distance value for a pair of NUMA nodes
            //checks if the distance exists in the hash, and adds it if it is
            //a new one
            pos = find_hash_position(dist, total_size, hash);
            if (hash[pos].distance == dist) break;      //this distance has already been added to the hash
            else {  //free position, adds distance to the hash
                hash[pos].distance = dist;
                hash[pos].source = i;
                hash[pos].dest = j;
                break;
            }
        }
    }
}

/***********************************************************/
/* Returns a position in the hash for a given distance, or the first free
 * position */
inline int find_hash_position(float base, int hash_size, struct comm_hash_t *hash){
    int index = hash_index(base, hash_size);
    int k, pos;

    for (k = 0; k < hash_size; k++){
        pos = (index + k) % hash_size;         
        if (hash[pos].distance == base) break; //exact position for distance dist
        else if (hash[pos].distance <= NO_DISTANCE) break; //found a free position
        // continues searching
    }
    return pos;
}

/***********************************************************/
inline int hash_index(float base, int hash_size){
    int result = base*MY_PRIME;
    return result % hash_size;
}

/***********************************************************/
void bind_to_core(hwloc_topology_t topology, int i, int nb_nodes){
    hwloc_cpuset_t cpuset;
    hwloc_obj_t core;
    int errors = 0;

    cpuset = hwloc_bitmap_alloc();
    if (nb_nodes > 1)
        core = hwloc_get_obj_below_by_type (topology, HWLOC_OBJ_NODE, i, HWLOC_OBJ_PU, 0); //finds a core in the NUMA node i
    else
        core = hwloc_get_obj_by_type (topology, HWLOC_OBJ_PU, 0);
    hwloc_bitmap_zero (cpuset);
    hwloc_bitmap_set (cpuset, core->os_index); //binding uses physical indexes!
    errors = hwloc_set_cpubind (topology, cpuset, HWLOC_CPUBIND_PROCESS); //binds process to the first core of NUMA node i
    if (errors == -1){
        printf("Error binding the process. Aborting.\n");
        exit(HWLOC_FAILURE);
    }
}

/***********************************************************/
void bind_to_memory(hwloc_topology_t topology, int j){
    hwloc_nodeset_t memset;
    hwloc_obj_t node;
    int errors = 0;

    memset = hwloc_bitmap_alloc();
    node = hwloc_get_obj_by_type (topology, HWLOC_OBJ_NODE, j);
    hwloc_bitmap_zero (memset);
    hwloc_bitmap_set (memset, node->os_index);
    errors = hwloc_set_membind_nodeset (topology, memset, HWLOC_MEMBIND_BIND, HWLOC_MEMBIND_MIGRATE);
    if (errors != 0){
        printf("Error binding memory. Aborting.\n");
        exit(HWLOC_FAILURE);
    }
}
