/* C source code
 * File: "/home/llpilla/numalb/src/hieschella/src/topology_model.c"
 * Created: "Tue, 23 Apr 2013 23:41:21 -0300 (pilla)"
 * Updated: "Wed, 26 Jun 2013 14:31:59 -0300 (llpilla)"
 * $Id$
 * Copyright (C) 2013, Laercio Lima Pilla <llpilla@inf.ufrgs.br> 
 */
/*
 * ===========================================================================
 *
 *       Filename:  topology_model.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/23/2013 11:41:21 PM BRT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * ==========================================================================
 */

#include "topology_model.h"

//##########################################################
//Checks if data structure has been allocated, and does it was not done before
//##########################################################
inline void alloc_userdata(hwloc_obj_t obj, int size){
    if (obj->userdata == NULL){
        struct comm_costs_t *data;
        data = (struct comm_costs_t *) malloc(sizeof(comm_costs));
        data->size = size;
        data->latency = (float *) malloc(size*sizeof(float));
        data->bandwidth = (float *) malloc(size*sizeof(float));
        obj->userdata = (void *) data;
    }
    assert(obj->userdata != NULL);
}

//##########################################################
// Callback to store communication costs in the topology xml
//##########################################################
void export_comm_costs(void *reserved, hwloc_topology_t topo, hwloc_obj_t obj) {

    char buffer[16];
    int err;
    struct comm_costs_t *data;
    data = (struct comm_costs_t *) obj->userdata;

    //Stores latencies. ID = LatencyX, where X == size
    sprintf(buffer, "Latency%d", data->size);
    err = hwloc_export_obj_userdata_base64(reserved, topo, obj, buffer, data->latency, data->size*sizeof(float));
    assert(err >= 0);

    //Stores bandwidths. ID = BandwidthX, where X == size
    sprintf(buffer, "Bandwidth%d", data->size);
    err = hwloc_export_obj_userdata_base64(reserved, topo, obj, buffer, data->bandwidth, data->size*sizeof(float));
    assert(err >= 0);

}

//##########################################################
// Callback to recover communication costs from the topology xml
//##########################################################
void import_comm_costs(hwloc_topology_t topo __hwloc_attribute_unused, hwloc_obj_t obj, const char *name, const void *buffer, size_t length) {

    void *err;
    int size;
    struct comm_costs_t *data;
    
    //Read latencies
    if (!strncmp(LATENCY, name, 7)) {
        size = atoi (name+7);
        assert(size >= 0);
        alloc_userdata(obj, size);
        data = (struct comm_costs_t *) obj->userdata;
        err = memcpy(data->latency, buffer, size*sizeof(float));
        assert(err != NULL);
    } 
    else {
        if (!strncmp(BANDWIDTH, name, 9)) {
            size = atoi (name+9);
            assert(size >= 0);
            alloc_userdata(obj, size);
            data = (struct comm_costs_t *) obj->userdata;
            err = memcpy(data->bandwidth, buffer, size*sizeof(float));
            assert(err != NULL);
        }
        else {
            assert(0);
        }
    }
}

//##########################################################
// Communication costs writers
//##########################################################
void set_latency(hwloc_obj_t obj, float cost){
    set_comm_cost_by_name(obj, cost, LATENCY);
}

void set_bandwidth(hwloc_obj_t obj, float cost){
    set_comm_cost_by_name(obj, cost, BANDWIDTH);
}

void set_comm_cost_by_name(hwloc_obj_t obj, float cost, const char* name){
    set_comm_cost_array_by_name(obj, &cost, 1, name);
}

void set_latency_array(hwloc_obj_t obj, float *cost, int size){
    set_comm_cost_array_by_name(obj, cost, size, LATENCY);
}

void set_bandwidth_array(hwloc_obj_t obj, float *cost, int size){
    set_comm_cost_array_by_name(obj, cost, size, BANDWIDTH);
}

void set_comm_cost_array_by_name(hwloc_obj_t obj, float *cost, int size, const char* name){
    struct comm_costs_t *data;
    void *err;

    alloc_userdata(obj, size); //checks the existence of userdata and allocates it if necessary
    data = (struct comm_costs_t *) obj->userdata;

    if (!strcmp(LATENCY, name)){
        err = memcpy(data->latency, (void *) cost, size*sizeof(float));
    }
    else {
        if (!strcmp(BANDWIDTH, name)){
            err = memcpy(data->bandwidth, (void *) cost, size*sizeof(float));
        }
        else {
            printf("Invalid communication cost type. Aborting.\n");
            assert(0);
        }
    }
    assert(err != NULL);
}


//##########################################################
// Communication costs readers
//##########################################################
float get_bandwidth(hwloc_topology_t topo, int pu1, int pu2){
    struct comm_t cost;
    cost = get_comm_cost_by_name(topo, pu1, pu2, BANDWIDTH);
    return cost.bandwidth;
}

float get_latency(hwloc_topology_t topo, int pu1, int pu2){
    struct comm_t cost;
    cost = get_comm_cost_by_name(topo, pu1, pu2, LATENCY);
    return cost.latency;
}

struct comm_t get_comm(hwloc_topology_t topo, int pu1, int pu2){
    return get_comm_cost_by_name(topo, pu1, pu2, ALL);
}

float get_bandwidth_objs(hwloc_topology_t topo, hwloc_obj_t obj1, hwloc_obj_t obj2){
    struct comm_t cost;
    cost = get_comm_cost_by_name_objs(topo, obj1, obj2, BANDWIDTH);
    return cost.bandwidth;
}

float get_latency_objs(hwloc_topology_t topo, hwloc_obj_t obj1, hwloc_obj_t obj2){
    struct comm_t cost;
    cost = get_comm_cost_by_name_objs(topo, obj1, obj2, LATENCY);
    return cost.latency;
}

struct comm_t get_comm_objs(hwloc_topology_t topo, hwloc_obj_t obj1, hwloc_obj_t obj2){
    return get_comm_cost_by_name_objs(topo, obj1, obj2, ALL);
}

struct comm_t get_comm_cost_by_name(hwloc_topology_t topo, int pu1, int pu2, const char* name){
    hwloc_obj_t obj1, obj2;
    //Finds the respective processing units
    obj1 = hwloc_get_pu_obj_by_os_index(topo, pu1); 
    obj2 = hwloc_get_pu_obj_by_os_index(topo, pu2); 
    //obj1 = hwloc_get_obj_by_type (topo, HWLOC_OBJ_PU, pu1);
    //obj2 = hwloc_get_obj_by_type (topo, HWLOC_OBJ_PU, pu2);
    return get_comm_cost_by_name_objs(topo, obj1, obj2, ALL);
}

struct comm_t get_comm_cost_by_name_objs(hwloc_topology_t topo, hwloc_obj_t obj1, hwloc_obj_t obj2, const char* name){
    struct comm_costs_t *data;
    hwloc_obj_t ancestor, nonunif, anc1, anc2;
    int level_size, n1, n2, index;
    struct comm_t cost;

    //Finds the common ancestor that contains communication costs
    ancestor = hwloc_get_common_ancestor_obj (topo, obj1, obj2);
    while (ancestor->userdata == NULL){ 
        ancestor = ancestor->parent;
    }
    assert(ancestor->userdata != NULL);

    //If it contains more than one communication cost, then the ancestors in
    //the nonuniform level have to be identified
    data = (struct comm_costs_t *) ancestor->userdata;
    if (data->size == 1){
        index = 0;
   }
    else {
        //Nonuniformity is stored at a machine or system level, which is above
        //where it happens. Due to that, we have to find the nonuniform level
        //and the ancestors of obj1 and obj2 there.
        nonunif = ancestor->first_child;
        while ((nonunif->type != HWLOC_OBJ_NODE)&&(nonunif->type != HWLOC_OBJ_MACHINE)){
            nonunif = nonunif->first_child;
        }
        assert(nonunif != NULL);

        //finds obj1 and obj2 ancestors at the nonuniform level
        if(obj1->depth == nonunif->depth){
            anc1 = obj1;
            anc2 = obj2;
        }
        else {  
            anc1 = hwloc_get_ancestor_obj_by_type (topo, nonunif->type, obj1);
            anc2 = hwloc_get_ancestor_obj_by_type (topo, nonunif->type, obj2);
        }

        //checks how many nodes exist in that nonuniform level
        level_size = sqrt(data->size);

        //computes their logical indexes
        n1 = anc1->logical_index % level_size;
        n2 = anc2->logical_index % level_size;
        index = n1*level_size + n2;
    }
    assert(index > -1);

    if (!strcmp(LATENCY, name)) 
        cost.latency = data->latency[index];
    else if (!strcmp(BANDWIDTH, name)) 
        cost.bandwidth = data->bandwidth[index];
    else if (!strcmp(ALL, name)){
        cost.latency = data->latency[index];
        cost.bandwidth = data->bandwidth[index];
    }
    else {
        printf("Invalid communication cost type. Aborting.\n");
        assert(0);
    }
    return cost;
}

struct comm_t get_comm_net(hwloc_topology_t topo, int cn1, int cn2){
    struct comm_costs_t *data;
    hwloc_obj_t root;
    int level_size, index;
    struct comm_t cost;

    root = hwloc_get_root_obj(topo);
    assert(root->userdata != NULL);

    data = (struct comm_costs_t *) root->userdata;
    if (data->size == 1){
        index = 0;
    }
    else {
        level_size = sqrt(data->size);
        assert(level_size >= cn1);
        assert(level_size >= cn2);
        index = cn1*level_size + cn2;
    }

    cost.latency = data->latency[index];
    cost.bandwidth = data->bandwidth[index];

    return cost;
}



float get_obj_latency(hwloc_obj_t obj){
    struct comm_costs_t *data;

    assert(obj->userdata != NULL);
    data = obj->userdata; 
    return data->latency[0];
}

float get_obj_bandwidth(hwloc_obj_t obj){
    struct comm_costs_t *data;

    assert(obj->userdata != NULL);
    data = obj->userdata; 
    return data->bandwidth[0];
}

struct comm_t get_obj_comm(hwloc_obj_t obj){
    struct comm_costs_t *data;
    struct comm_t cost;

    assert(obj->userdata != NULL);
    data = obj->userdata; 
    cost.latency = data->latency[0];
    cost.bandwidth = data->bandwidth[0];
    return cost;
}

//##########################################################
//Read the machine topology with communication costs
//##########################################################
void machine_topology_setup(hwloc_topology_t topo){
    hwloc_topology_init(&topo);
    hwloc_topology_set_xml(topo, XMLFILE);
    hwloc_topology_set_userdata_import_callback(topo, import_comm_costs);
    hwloc_topology_load(topo);
    assert(topo != NULL);
}
