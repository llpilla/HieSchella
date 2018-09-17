#!/bin/bash
#PBS -l mppwidth=1
#PBS -l mppnppn=1
#PBS -l mppdepth=32
#PBS -j oe

#LBs PARAMETERS
LB_TEST_TOPO="randgraph"

LB="StatsLB HwTopoLB GreedyCommLB ScotchLB RefineCommLB"

#NUMBER OF REPETITIONS
COUNT=20
MACHINES=1

#NUMBER OF CORES TO USE
CPUS=32
let MAP=${CPUS}-1

#OUTPUT FOLDER AND BINARIES FOLDER
BASEDIR=$PBS_O_WORKDIR
OUT=$BASEDIR/results
cd $BASEDIR/bin

export LD_LIBRARY_PATH=$HOME/hwloc/lib:$HOME/charm/lib:$HOME/scotch_5.1.12/lib:/opt/gcc/4.6.1/snos/lib64/

PERF="aprun -n ${MACHINES} -N 1 -d ${CPUS} -cc 0-${MAP} perf stat -e cycles -e migrations -e L1-dcache-loads -e L1-dcache-load-misses -e LLC-loads -e LLC-load-misses"
PARAM="+p${CPUS} +setcpuaffinity +pemap 0-${MAP}"

#########################################LB_TEST
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
      ${PERF} $BASEDIR/bin/lb_test ${PARAM} $ELEMENTS $ITER 1 10 $MIN $MAX $topo +balancer $lb +LBDebug 1 >> ${OUT}/lb_test.${lb} 2>> ${OUT}/${lb}.lb_test
    done
  done
done

#########################################STENCIL 4D
ELEMENTS=128
BLOCK=32
ITER=50
for lb in $LB
do
  for i in `seq $COUNT`;
  do 
      ${PERF} $BASEDIR/bin/stencil4d ${PARAM} $ELEMENTS $BLOCK $ITER +balancer $lb +LBDebug 1 >> ${OUT}/stencil4d.${lb} 2>> ${OUT}/${lb}.stencil4d
  done
done

##########################################LEAN MD
ITER=501
for lb in $LB
do
  for i in `seq ${COUNT}`;
  do 
      ${PERF} $BASEDIR/bin/leanmd ${PARAM} 6 6 5 $ITER 20 100 +balancer $lb +LBDebug 1 >> ${OUT}/leanmd.${lb} 2>> ${OUT}/${lb}.leanmd
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
      ${PERF} $BASEDIR/bin/kNeighbor ${PARAM} $ELEMENTS 50 $MSGS $WORK 10 +balancer $lb +LBDebug 1 >> ${OUT}/kneighbor.${lb} 2>> ${OUT}/${lb}.kneighbor

  done
done

