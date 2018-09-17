#!/bin/bash
# File: "/home/pilla/hieschella/hieschella/src/scripts/Results/parse_net.sh"
# Created: "Tue, 09 Oct 2012 13:56:15 +0200 (pilla)"
# Updated: "Mon, 17 Dec 2012 10:18:35 +0800 (pilla)"

## This is part of a set of scripts to parse data obtained
## from load balancers of Charm++.
## The current scripts reads the output file for several
## benchmarks and load balancers, and stores the information of
## interest in the csv format in different directories for each
## pair of benchmark, load balancer

#######################################################
### Definitions
MACHINE=machine
DATE=date
RESULTS_PATH=$HOME/Results/${MACHINE}/${DATE}/leanmd2
PARSED_PATH=$RESULTS_PATH/parsed

#######################################################
### Data to be parsed
LBS="StatsLB HwTopoLB GreedyCommLB ScotchLB RefineCommLB"
APPS="leanmd"

#######################################################
. parse_functions.sh

cd $RESULTS_PATH

#-- creates directory for parsed files
if [ ! -d "$PARSED_PATH" ]; then
    mkdir $PARSED_PATH
fi

for app in $APPS    #parses all benchmarks
do
    echo $app
    for lb in $LBS  #parses a benchmark for all load balancers
    do
        work=$app.$lb

        cd $PARSED_PATH
        if [ ! -d "$work" ]; then
            mkdir $work
        fi
        cd $RESULTS_PATH
        
        out=$PARSED_PATH/$work
        
        #-- greps load balancer results and stores them in different files
        #-- perf stat info: 1 per benchmark execution
        parse_perf_stat
        
        #--load balancer info: 1 per load balancing call
        parse_lb
        
        #-- application info: related to iterations, have to be filtered later
        parse_iterations
        
        #-- clean up
        parse_clean
    done
done


