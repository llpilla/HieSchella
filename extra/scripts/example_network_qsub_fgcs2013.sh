#!/bin/bash
#PBS -l mppwidth=2
#PBS -l mppnppn=1
#PBS -l mppdepth=32
#PBS -j oe

#LBs PARAMETERS
LB_TEST_TOPO="randgraph"

LB="StatsLB HwTopoLB GreedyCommLB ScotchLB RefineCommLB"

#NUMBER OF REPETITIONS
COUNT=20
MACHINES=2

#NUMBER OF CORES TO USE
CPUS=32
let MAP=${CPUS}-1

#OUTPUT FOLDER AND BINARIES FOLDER
BASEDIR=$PBS_O_WORKDIR
OUT=$BASEDIR/leanmd$MACHINES
cd $BASEDIR/bin

export LD_LIBRARY_PATH=$HOME/hwloc/lib:$HOME/charm/lib:$HOME/scotch_5.1.12/lib

PERF="aprun -n ${MACHINES} -N 1 -d ${CPUS} -cc 0-${MAP} perf stat -e cycles -e migrations -e L1-dcache-loads -e L1-dcache-load-misses -e LLC-loads -e LLC-load-misses"
PARAM="+ppn${CPUS} +setcpuaffinity +pemap 0-${MAP}"

xtnodestat
##########################################LEAN MD
ITER=301
for lb in $LB
do
  for i in `seq ${COUNT}`;
  do
      ${PERF} $BASEDIR/bin/leanmd ${PARAM} 5 10 5 $ITER 20 100 +balancer $lb >> ${OUT}/leanmd.${lb} 2>> ${OUT}/errors.leanmd
  done
done


