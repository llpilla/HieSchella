#include "network_extension.h"

/***********************************************************/
int main (int argc, char **argv) {
    hwloc_topology_t child, parent;
    hwloc_obj_t parent_root, child_root;
    int i, j, opt, cns, costs, err, nb_pus;
    float buffer;
    int diff_input = FALSE;
    int diff_output = FALSE;
    int diff_profile = FALSE;
    int debug = FALSE;
    char *input;
    char *output;
    char *profile;
    float *latencies;
    float *bandwidths;
    FILE *fp;

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
            else if ((!strcmp(argv[0], "-v")) || (!strcmp(argv[0], "--verbose")))
                debug = TRUE; 
            else {
                opt = 2;
                if (argc < 2) {
                    usage();
                    exit(INPUT_FAILURE);
                }
                if ((!strcmp(argv[0], "-p")) || (!strcmp(argv[0], "--profile"))){
                    profile = argv[1];
                    diff_profile = TRUE;
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

    /*******************************************************************/
    // Reads the input file containing the communication costs
    if (diff_profile)
        fp = fopen(profile, "r");
    else
        fp = fopen(NETWORKFILE, "r");
    assert(fp != NULL);
    
    //reads the number of compute nodes in the platform
    err = fscanf(fp, "%d", &cns);
    assert(err > 0);
    assert(cns > 0);

    //reads the number of communication costs at network level
    err = fscanf(fp, "%d", &costs);
    assert(err > 0);
    assert((costs == 1)||(costs == cns));

    //reads network latencies
    latencies = (float *) malloc(costs*costs*sizeof(float));
    assert(latencies != NULL);
    for (i = 0; i < costs*costs; i++){
        err = fscanf(fp, "%f", &buffer);
        assert(err > 0);
        assert(buffer > 0);
        latencies[i] = buffer;
    }

    //reads network bandwidths
    bandwidths = (float *) malloc(costs*costs*sizeof(float));
    assert(bandwidths != NULL);
    for (i = 0; i < costs*costs; i++){
        err = fscanf(fp, "%f", &buffer);
        assert(err > 0);
        assert(buffer > 0);
        bandwidths[i] = buffer;
    }   

    fclose(fp);
    /*******************************************************************/

    // Reads the machine topology of one compute node
    hwloc_topology_init(&child);
    if (diff_input)
        hwloc_topology_set_xml(child, input);
    else
        hwloc_topology_set_xml(child, XMLFILE);
    hwloc_topology_set_userdata_import_callback(child, import_comm_costs);
    hwloc_topology_load(child);

    if(debug){
        printf("------------------------------\n");
        printf("Compute node topology\n");
        printf("# Processing units = %d\n", hwloc_get_nbobjs_by_type(child, HWLOC_OBJ_PU));
        printf("# Memory nodes =     %d\n", hwloc_get_nbobjs_by_type(child, HWLOC_OBJ_NODE));
        printf("------------------------------\n");
    }

    // Starts the machine topology to include the network level
    hwloc_topology_init(&parent);
    hwloc_topology_set_custom(parent);
    hwloc_topology_set_userdata_import_callback(parent, import_comm_costs);
  
    //gets the roots of both trees
    parent_root = hwloc_get_root_obj(parent);
    child_root = hwloc_get_root_obj(child);

    //adds #nodes childs to the parent tree
    for (i = 0; i < cns; i++) {
        hwloc_custom_insert_topology (parent, parent_root, child, child_root);
    }
    hwloc_topology_load(parent);
    
    if(debug){
        printf("------------------------------\n");
        printf("Network topology\n");
        printf("# Compute nodes =    %d\n", hwloc_get_nbobjs_by_type(parent, HWLOC_OBJ_MACHINE));
        printf("------------------------------\n");
    }

    //stores the communication costs at network level
    parent_root = hwloc_get_root_obj(parent);
    set_latency_array(parent_root, latencies, cns*cns);
    set_bandwidth_array(parent_root, bandwidths, cns*cns);

    nb_pus = hwloc_get_nbobjs_by_type(child, HWLOC_OBJ_PU);
    update_pus(parent, cns, nb_pus); 
    
    if(debug){
        printf("------------------------------\n\n");
        printf("Network latencies\n");
        for (i = 0; i < costs; i++){
            for (j = 0; j < costs; j++){
                printf ("%d reads from %d =  %f ns\n",i, j, latencies[i*costs+j]);
            }
        }
        printf("Network bandwidths\n");
        for (i = 0; i < costs; i++){
            for (j = 0; j < costs; j++){
                printf ("%d reads from %d =  %f MB/s\n",i, j, bandwidths[i*costs+j]);
            }
        }
        printf("------------------------------\n\n");
    }

    //exports the machine topology to an xml file
    hwloc_topology_set_userdata_export_callback(parent, export_comm_costs);
    if (diff_output)
        hwloc_topology_export_xml(parent, output);
    else
        hwloc_topology_export_xml(parent, XMLFILE);

    //frees data structures
    free(latencies);
    free(bandwidths);
    
  exit(OK);
} 

/***********************************************************/
void usage(){
   printf("Usage options\n");
   printf("  -h --help            Prints this message\n");
   printf("  -v --verbose         Includes additional information\n");
   printf("  -i --input file.xml  Uses a different xml file to represent the compute nodes\n");
   printf("  -o --output file.xml Outputs the resulting xml to a different file\n");
   printf("  -p --profile file    Read the network profile from a different base file\n");
   printf("\n");
}

/***********************************************************/
// Changes os_indexes to keep processing units and compute nodes more inform
void update_pus(hwloc_topology_t topo, int nb_cns, int nb_pus){
    hwloc_obj_t cn, pu;
    int i,j;
    
    for (i = 1; i < nb_cns; i++){
        cn = hwloc_get_obj_by_type(topo, HWLOC_OBJ_MACHINE, i);
        cn->os_index = i;
        for (j = 0; j < nb_pus; j++){
            pu = hwloc_get_obj_by_type(topo, HWLOC_OBJ_PU, j+i*nb_pus);
            pu->os_index = pu->os_index + i*nb_pus;
        }
    }
}

