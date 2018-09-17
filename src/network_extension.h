// C++ source code
// File: "/home/llpilla/numalb/src/hieschella/network_extension.h"
// Created: "Sun, 15 Apr 2012 13:08:37 +0200 (pilla)"
// Updated: "Mon, 29 Apr 2013 17:36:37 -0300 (llpilla)"
/*
 * ===========================================================================
 * 
 *       Filename:  hwloc_extend_topology.h
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

//##########################################################
// Definitions
//##########################################################


//##########################################################
// Functions
//##########################################################
void usage();
void update_pus(hwloc_topology_t topo, int nb_cns, int nb_pus);
