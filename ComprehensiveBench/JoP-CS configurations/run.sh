#!/bin/bash

#####################################################################
#####################################################################
#####################################################################
#
# Test parameters
#
#####################################################################

# Load balancers

load_balancer=( " " "+balancer GreedyLB" "+balancer GreedyCommLB" "+balancer RefineLB" "+balancer RefineCommLB" "+balancer RandCentLB" )

# Number of applications
num_of_execs=14

# Number of cores
num_cores=128

# Number of repetitions
num_repetitions=1

# Applications directory
exec_dir="execs"

# Name of output files
output_dir="test_output"
data_file_name="$output_dir/data.txt"
test_info_file_name="$output_dir/info.csv"

# Name of temp file
tmp_output_file_name="tmp.txt"

#####################################################################
#####################################################################
#####################################################################
#
# Initialization
#
#####################################################################

rm -r $output_dir
mkdir $output_dir

echo "Id,Test number,Repetitions, LB, Iteration time, LB time, Total time" >> $test_info_file_name

exec_id=0
test_counter=0

#####################################################################
#####################################################################
#####################################################################
#
# Compiles ComprehensiveBench
#
#####################################################################

mkdir $exec_dir
i=1
j=0
while [ $i -le $num_of_execs ]; do
	config_file_name="config"$i".txt"	
	exec_file_name="$exec_dir/e$j"
	bash build.sh $config_file_name $exec_file_name
	let i=$i+1
	let j=$j+1
done

#####################################################################
#####################################################################
#####################################################################
#
# Runs the experiments
#
#####################################################################

while [ $exec_id -lt $num_of_execs ]; do
	for balancer in "${!load_balancer[@]}"; do
		rep_counter=0
		while [ $rep_counter -lt $num_repetitions ]; do

			exec_file_name="$exec_dir/e$exec_id"

			let tmp=$num_cores-1
			echo "numatcl --physcpubind=0-"$tmp" ./$exec_file_name +p"$num_cores" "${load_balancer["$balancer"]}
			echo "numatcl --physcpubind=0-"$tmp" ./$exec_file_name +p"$num_cores" "${load_balancer["$balancer"]} > $tmp_output_file_name
			numactl --physcpubind=0-$tmp ./$exec_file_name +p$num_cores ${load_balancer["$balancer"]} >> $tmp_output_file_name
#			numactl --physcpubind=0-$tmp ./$exec_file_name +p$num_cores ${load_balancer["$balancer"]} +LBDebug 2 >> $tmp_output_file_name
			cat $tmp_output_file_name >> $data_file_name

			IT_time=$(cat $tmp_output_file_name | grep "Iterations total time" | grep -o '[0-9\.].*')
			LB_time=$(cat $tmp_output_file_name | grep "LB total time" | grep -o '[0-9\.].*')
			TOTAL_time=$(echo $IT_time + $LB_time | bc)
		
			echo $exec_id","$test_counter","$rep_counter","$balancer","$IT_time","$LB_time","$TOTAL_time >> $test_info_file_name

			let rep_counter=$rep_counter+1
		done
		let test_counter=$test_counter+1
	done
	let exec_id=$exec_id+1
done

rm $tmp_output_file_name

