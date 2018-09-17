### Small explanation of commands and their use here
### cat: print the file
### grep: get the lines of interest
### sed: fix words and numbers
### awk: printf the colunms of interest

#-- perf stat info: 1 per benchmark execution
parse_perf_stat() {
    for word in time node_misses l1_misses llc_misses
    do
        echo $word > $out/$word
    done
    cat $work | grep 'seconds time' | sed s/[0-9]\ [0-9]/\1\2/g | sed s/\,/\./g | awk '{print $1}' >> $out/time
    cat $work | grep 'node-load-misses'| sed s/[0-9]\ [0-9]/\1\2/g | sed s/[0-9]\,[0-9]/\1\2/g | awk '{print $1}' >> $out/node_misses
    cat $work | grep '[lL]1-dcache-load-misses'| sed s/[0-9]\ [0-9]/\1\2/g | sed s/[0-9]\,[0-9]/\1\2/g | awk '{print $1}' >> $out/l1_misses
    cat $work | grep '[lL][lL][cC]-load-misses'| sed s/[0-9]\ [0-9]/\1\2/g | sed s/[0-9]\,[0-9]/\1\2/g | awk '{print $1}' >> $out/llc_misses
    
#    paste -d , $out/time $out/l1_misses $out/llc_misses > $out/perf
    paste -d , $out/time $out/l1_misses $out/llc_misses $out/node_misses > $out/perf
}

#--load balancer info: 1 per load balancing call
parse_lb(){
    for word in start_lba end_lba start_lb end_lb migrations
    do
        echo $word > $out/$word
    done
    cat $work | grep 'strategy starting at' | awk '{print $8}' >> $out/start_lba
    cat $work | grep 'strategy finished at' | awk '{print $8}' >> $out/end_lba
    cat $work | grep 'step [0-9] starting at' | awk '{print $9}' >> $out/start_lb
    cat $work | grep 'step [0-9] finished at' | awk '{print $9}' >> $out/end_lb
    cat $work | grep 'Objects migrating' | sed s/\,/\ /g | awk '{print $7}' >> $out/migrations
    
    for word in cl cm cb pl po
    do
        echo $word.mean,$word.median,$word.max,$word.min,$word.total > $out/$word
    done
    cat $work | grep 'Chare load' | awk '{print $3,$4,$5,$6,$7}' | sed s/\ /\,/g  >> $out/cl
    cat $work | grep 'Chare message' | awk '{print $3,$4,$5,$6,$7}' | sed s/\ /\,/g  >> $out/cm
    cat $work | grep 'Chare bytes' | awk '{print $3,$4,$5,$6,$7}' | sed s/\ /\,/g  >> $out/cb
    cat $work | grep 'Processor load' | awk '{print $3,$4,$5,$6,$7}' | sed s/\ /\,/g  >> $out/pl
    cat $work | grep 'Processor overhead' | awk '{print $3,$4,$5,$6,$7}' | sed s/\ /\,/g  >> $out/po
    paste -d , $out/start_lba $out/end_lba $out/start_lb $out/end_lb $out/migrations $out/cl $out/cm $out/cb $out/pl $out/po> $out/lb
    
    cat $work | grep 'Messages in the topology' | sed s/"Messages in the topology"[[:space:]]//g | sed 's/\([0-9]\)[[:space:]]\([0-9]\)/\1\,\2/g' > $out/topo_messages
    cat $work | grep 'Bytes in the topology' | sed s/"Bytes in the topology"[[:space:]]//g | sed 's/\([0-9]\)[[:space:]]\([0-9]\)/\1\,\2/g' > $out/topo_bytes 
}

#-- application info: related to iterations, have to be filtered later
parse_iterations() {
    echo iter > $out/iter
    if [ "$app" = 'leanmd' ]; then
        cat $work | grep 'Benchmark Time' | awk '{print $5}' >> $out/iter
    else 
        if [ "$app" = 'stencil4d' ]; then
            cat $work | grep 'maxTime' | awk '{print $7}' >> $out/iter
        else
            if [ "$app" = 'lb_test' ]; then
                cat $work |  grep 'TIME PER STEP' | awk '{print $6}' >> $out/iter
            else #for now, else = kneighbor
                cat $work | grep 'Iter ' | awk '{print $3}' >> $out/iter
            fi
        fi
     fi
}

#-- clean up
parse_clean(){
    for word in time node_misses l1_misses llc_misses start_lba end_lba start_lb end_lb migrations cl cm cb pl po
    do
        rm $out/$word
    done
}
