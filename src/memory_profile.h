// C++ source code
// File: "/home/pilla/numalb/src/hieschella/src/memory_profile.h"
// Created: "Sun, 15 Apr 2012 13:08:37 +0200 (pilla)"
// Updated: "Thu, 26 Sep 2013 10:38:27 +0200 (pilla)"
/*
 * ===========================================================================
 * 
 *       Filename:  hwloc_gather_distances.h
 * 
 *    Description:  
 * 
 *        Version:  1.0
 *        Created:  04/15/2012 01:08:37 PM CEST
 *       Revision:  none
 *       Compiler:  gcc
 * 
 * ===========================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <hwloc.h>
#include "topology_model.h"

#include "../lmbench3/src/bench.h"
#include "lat_mem_rd.h"
#include "bw_mem.h"
//#include "fake_benchs.h"

//##########################################################
// Definitions
//##########################################################
#define REPETITIONS     30
#define WARMUP          5

#define LAT             13245
#define BW              98743
#define NO_DISTANCE     -1.0
#define NEW_HASH        678
#define OLD_HASH        345
#define MY_PRIME        101

#define BASE_LATENCY    1.0
#define BASE_BANDWIDTH  1e12
#define PLAIN_LATENCY   1e-6
#define PLAIN_BANDWIDTH 1e18
//##########################################################
// Data types
//##########################################################
// Hash to quickly benchmark NUMA machines
struct comm_hash_t {
    float distance;
    int source;
    int dest;
    float cost;
} comm_hash;

//##########################################################
// Variables
//##########################################################
static int nb_nodes;        //number of numa nodes
static int nb_cores;        //number of cores
static int nb_cache_lvls;   //number of cache lvls
static int stride;          //line size of the last cache lvl in bits
hwloc_uint64_t* mem_sizes;  //size of the memories (caches and main memory)
hwloc_uint64_t* bench_sizes;//size to be used on the benchmarks

float* cache_lats;          //cache latencies
float* cache_bws;           //cache bandwidths
float* mem_lats;            //memory latencies
float* mem_bws;             //memory bandwidths

int debug;                  //verbose flag
struct comm_hash_t *simplified_costs;   //quick way to benchmark a nonuniformity at memory level
//##########################################################
// Functions
//##########################################################
void usage();
int gather_memory_sizes (hwloc_topology_t topology, hwloc_uint64_t* mem_sizes, int mem_lvls, int nb_nodes);
int compute_memory_for_benchmarks (hwloc_uint64_t* mem_sizes, hwloc_uint64_t* bench_sizes, int nb_cache_lvls, int min_size);

void add_costs (hwloc_topology_t topology, const char* name, float* cache_costs, float* mem_costs, int nb_nodes);

void benchmark_cache_latency (hwloc_topology_t topology, float* cache_lats, hwloc_uint64_t* bench_sizes, int nb_cache_lvls, int warm, int rep);
void benchmark_cache_bandwidth (hwloc_topology_t topology, float* cache_bws, hwloc_uint64_t* bench_sizes, int nb_cache_lvls, int warm, int rep);
void benchmark_memory_latency (hwloc_topology_t topology, float* mem_lats, hwloc_uint64_t bench_size, int nb_nodes, int warm, int rep, int speed);
void benchmark_memory_bandwidth (hwloc_topology_t topology, float* mem_bws, hwloc_uint64_t bench_size, int nb_nodes, int warm, int rep, int speed);

void benchmark_uniform_memory (hwloc_topology_t topology, float* output, hwloc_uint64_t bench_size, int warm, int rep, int name);
void benchmark_numa (hwloc_topology_t topology, float* output, hwloc_uint64_t bench_size, int nb_nodes, int warm, int rep, int name, int speed);
void benchmark_numa_complete (hwloc_topology_t topology, float* output, hwloc_uint64_t bench_size, int nb_nodes, int warm, int rep, int name);
void benchmark_numa_fast (hwloc_topology_t topology, float* output, hwloc_uint64_t bench_size, int nb_nodes, int warm, int rep, int name);

void artificial_costs (hwloc_topology_t topology, int nb_nodes);
void plain_costs (int nb_nodes);

void bind_to_core(hwloc_topology_t topology, int i, int nb_nodes);
void bind_to_memory(hwloc_topology_t topology, int j);

//Hash functions
inline int alloc_hash(int size);
inline void free_hash();
void fill_hash(const struct hwloc_distances_s *distances, struct comm_hash_t *hash);
inline int find_hash_position(float base, int hash_size, struct comm_hash_t *hash);
inline int hash_index(float base, int hash_size);

