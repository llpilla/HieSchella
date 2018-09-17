#!/bin/bash

LB="StatsLB HwTopoLB GreedyCommLB ScotchLB RefineCommLB"

#NUMBER OF REPETITIONS
COUNT=20

#NUMBER OF CORES TO USE
SYSFS_CPU="/sys/devices/system/cpu"
CPUS=`ls -d ${SYSFS_CPU}/cpu[0-9]* | wc -l`
let MAP=${CPUS}-1

PERFBIN="/usr/bin/perf_3.2" 
PERF="${PERFBIN} stat -e l1-dcache-load-misses -e llc-load-misses -e migrations -e cache-misses -e faults -e node-loads -e node-stores -e node-load-misses -e node-store-misses"
PARAM="+p${CPUS} +setcpuaffinity +pemap 0-${MAP}"

export LD_LIBRARY_PATH=$HOME/hwloc/lib:$HOME/charm/lib:$HOME/scotch_5.1.12/lib
#OUTPUT FOLDER AND BINARIES FOLDER
OUT=../results
cd bin

##########################################LB_TEST
ELEMENTS=400
MIN=50000
MAX=200000
ITER=50
LB_TEST_TOPO="randgraph"
for lb in $LB
do
  for topo in $LB_TEST_TOPO
  do
    for i in `seq ${COUNT}`;
    do
      ${PERF} -o ${OUT}/lb_test.${lb} --append ./lb_test ${PARAM} $ELEMENTS $ITER 1 10 $MIN $MAX $topo +balancer $lb +LBDebug 1 >> ${OUT}/lb_test.${lb} 2>> ${OUT}/errors
    done
  done
done

##########################################STENCIL 4D
ELEMENTS=128
BLOCK=32
ITER=50
for lb in $LB
do
  for i in `seq $COUNT`;
  do
      ${PERF} -o ${OUT}/stencil4d.${lb} --append ./stencil4d ${PARAM} $ELEMENTS $BLOCK $ITER +balancer $lb +LBDebug 1 >> ${OUT}/stencil4d.${lb} 2>> ${OUT}/errors
  done
done

#########################################LEAN MD
XYZ=5
ITER=501
for lb in $LB
do
  for i in `seq $COUNT`;
  do
      ${PERF} -o ${OUT}/leanmd.${lb} --append ./leanmd ${PARAM} 6 6 5 $ITER 20 100 +balancer $lb +LBDebug 1 >> ${OUT}/leanmd.${lb} 2>> ${OUT}/errors
  done
done

########################################KN 
ELEMENTS=400
MSGS=8192
WORK=10
for lb in $LB
do
  for i in `seq $COUNT`;
  do
      ${PERF} -o ${OUT}/kneighbor.${lb} --append ./kNeighbor ${PARAM} $ELEMENTS 50 $MSGS $WORK 10 +balancer $lb +LBDebug 1 >> ${OUT}/kneighbor.${lb} 2>> ${OUT}/errors

  done
done

