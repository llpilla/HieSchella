// C++ source code
// File: "/home/llpilla/numalb/src/hieschella/src/base_topology_model.h"
// Created: "Sun, 15 Apr 2012 13:08:37 +0200 (pilla)"
// Updated: "Tue, 11 Jun 2013 15:22:58 -0300 (llpilla)"
/*
 * ===========================================================================
 * 
 *       Filename:  topology_model.h
 * 
 *    Description:  
 * 
 *        Version:  1.0
 *        Created:  23/04/2013 01:08:37 PM CEST
 *       Revision:  none
 *       Compiler:  gcc
 * 
 * ===========================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <hwloc.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#ifndef __TOPOLOGY_MODEL

#define __TOPOLOGY_MODEL 2605

//##########################################################
// Definitions
//##########################################################
#define XMLFILE "TOPOLOGYPATH/topology/machine.xml"
#define NODEFILE "TOPOLOGYPATH/topology/one_node.xml"
#define NETWORKFILE "TOPOLOGYPATH/topology/network"
#define LATENCY "Latency"
#define BANDWIDTH "Bandwidth"
#define ALL "All"

#define INPUT_FAILURE   -1
#define HWLOC_FAILURE   -2
#define OK              0

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
//##########################################################
// Data types
//##########################################################

// The way latencies and bandwidths are stored in userdata
typedef struct comm_costs_t {
    int size;
    float *latency;             //latency in nanoseconds
    float *bandwidth;           //bandwidth in MB/s
} comm_costs;

// Easier way to return both latency and bandwidth in a request
struct comm_t {
    float latency;
    float bandwidth;
};

//##########################################################
// Functions
//##########################################################
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

//Checks if data structure has been allocated, and does it was not done before
inline void alloc_userdata(hwloc_obj_t obj, int size);

// Callback to store communication costs in the topology xml
extern void export_comm_costs(void *reserved, hwloc_topology_t topo, hwloc_obj_t obj);

// Callback to recover communication costs from the topology xml
extern void import_comm_costs(hwloc_topology_t topo __hwloc_attribute_unused, hwloc_obj_t obj, const char *name, const void *buffer, size_t length);

// Read data
extern float get_latency(hwloc_topology_t topo, int pu1, int pu2);
extern float get_bandwidth(hwloc_topology_t topo, int pu1, int pu2);
extern struct comm_t get_comm_cost_by_name(hwloc_topology_t topo, int pu1, int pu2, const char* name);
extern struct comm_t get_comm(hwloc_topology_t topo, int pu1, int pu2);

extern float get_bandwidth_objs(hwloc_topology_t topo, hwloc_obj_t obj1, hwloc_obj_t obj2);
extern float get_latency_objs(hwloc_topology_t topo, hwloc_obj_t obj1, hwloc_obj_t obj2);
extern struct comm_t get_comm_objs(hwloc_topology_t topo, hwloc_obj_t obj1, hwloc_obj_t obj2);
extern struct comm_t get_comm_cost_by_name_objs(hwloc_topology_t topo, hwloc_obj_t obj1, hwloc_obj_t obj2, const char* name);
extern struct comm_t get_comm_net(hwloc_topology_t topo, int cn1, int cn2);

extern float get_obj_latency(hwloc_obj_t obj);
extern float get_obj_bandwidth(hwloc_obj_t obj);
extern struct comm_t get_obj_comm(hwloc_obj_t obj);

// Write data
extern void set_latency(hwloc_obj_t obj, float cost);
extern void set_bandwidth(hwloc_obj_t obj, float cost);
extern void set_comm_cost_by_name(hwloc_obj_t obj, float cost, const char* name);

// Write data array
extern void set_latency_array(hwloc_obj_t obj, float *cost, int size);
extern void set_bandwidth_array(hwloc_obj_t obj, float *cost, int size);
extern void set_comm_cost_array_by_name(hwloc_obj_t obj, float *cost, int size, const char* name);

//Read the machine topology with communication costs
extern void machine_topology_setup(hwloc_topology_t topo);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __TOPOLOGY_MODEL
