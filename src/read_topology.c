/* C source code
 * File: "/home/llpilla/numalb/src/hwloc_plus/hwloc1.7/read_topology.c"
 * Created: "Wed, 24 Apr 2013 16:48:08 -0300 (llpilla)"
 * Updated: "Fri, 26 Apr 2013 14:29:31 -0300 (llpilla)"
 * $Id$
 * Copyright (C) 2013, Laércio Lima Pilla <llpilla@inf.ufrgs.br> 
 */
/*
 * ===========================================================================
 *
 *       Filename:  read_topology.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/24/2013 04:48:08 PM BRT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * ==========================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <hwloc.h>
#include "topology_model.h"

    
/***********************************************************/
void usage(){
   printf("Usage options\n");
   printf("  -h --help            Prints this message\n");
   printf("  -i --input file.xml  Uses a different xml file instead of the standard file\n");
   printf("\n");
}


/***********************************************************/
static void print_children(hwloc_topology_t topology, hwloc_obj_t obj, int depth)
{
    char string[128];
    unsigned i;
    hwloc_obj_snprintf(string, sizeof(string), topology, obj, "#", 0);
    printf("%*s%s\n", 2*depth, "", string);
    for (i = 0; i < obj->arity; i++) {
        print_children(topology, obj->children[i], depth + 1);
    }
}

/***********************************************************/
int main (int argc, char **argv) {
    hwloc_topology_t topo;
    int i,j, nb_pus, opt;
    int diff_input = FALSE;
    char *input;
    float cost;

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
            else {
                opt = 2;
                if (argc < 2) {
                    usage();
                    exit(INPUT_FAILURE);
                }
                if ((!strcmp(argv[0], "-i")) || (!strcmp(argv[0], "--input"))){
                        input = argv[1];
                        diff_input = TRUE;
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


    // Load compute node topology
    hwloc_topology_init (&topo);
    if (diff_input)
        hwloc_topology_set_xml (topo, input);
    else
        hwloc_topology_set_xml (topo, XMLFILE);
    hwloc_topology_set_userdata_import_callback(topo, import_comm_costs);
    hwloc_topology_load (topo);

    print_children (topo, hwloc_get_root_obj (topo), 0);
    nb_pus = hwloc_get_nbobjs_by_depth (topo, hwloc_get_type_depth (topo, HWLOC_OBJ_PU));

    printf("Latencies:\n");
    for (i = 0; i < nb_pus; i++){
        for (j = 0; j < nb_pus; j++){
            cost = get_latency (topo, i, j);
            printf("%d %d %f\n", i, j, cost);
        }
    }

    printf("Bandwidths:\n");
    for (i = 0; i < nb_pus; i++){
        for (j = 0; j < nb_pus; j++){
            cost = get_bandwidth (topo, i, j);
            printf("%d %d %f\n", i, j, cost);
        }
    }
    exit(OK);

}

