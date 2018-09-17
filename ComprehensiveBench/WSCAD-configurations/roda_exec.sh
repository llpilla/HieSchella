#!/bin/bash

#####################################################################
#####################################################################
#####################################################################
#
# Parâmetros do teste
#
#####################################################################

# Balanceadores de carga a serem utilizados no teste

declare -A load_balancer=(
													["none"]=""
													["greedyLB"]="+balancer GreedyLB"
													["greedyCommLB"]="+balancer GreedyCommLB"
													["refineLB"]="+balancer RefineLB"
													["refineCommLB"]="+balancer RefineCommLB"
													["randCentLB"]="+balancer RandCentLB"
												)

# Número de aplicações
num_of_execs=16

# Número de cores
num_cores=8

# Número de repetições
num_repetitions=10

# Diretório dos executáveis
exec_dir="execs"

# Nome dos arquivos de saída e diretório de saída
output_dir="test_output"
data_file_name="$output_dir/data.txt"
test_info_file_name="$output_dir/info.csv"

# Nome do arquivo temporário para armazenar a saída da execução
tmp_output_file_name="tmp.txt"

#####################################################################
#####################################################################
#####################################################################
#
# Inicialização
#
#####################################################################

# Inicializa arquivos
rm -r $output_dir
mkdir $output_dir

# Insere os cabeçalhos da tabela no arquivo de saída principal
echo "Id,Numero do teste,Repeticao,LB,Tempo iteracoes,Tempo LB,Tempo total" >> $test_info_file_name

# Inicializa contadores
exec_id=0
test_counter=0

#####################################################################
#####################################################################
#####################################################################
#
# Gera os executáveis
#
#####################################################################

# Gera os executáveis
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
# Executa os testes
#
#####################################################################

while [ $exec_id -lt $num_of_execs ]; do
	for balancer in "${!load_balancer[@]}"; do
		rep_counter=0
		while [ $rep_counter -lt $num_repetitions ]; do

			# Gera nome do executável
			exec_file_name="$exec_dir/e$exec_id"

			# Executa utilizando o número de cores especificado e o balanceadore escolhido
			let tmp=$num_cores-1
			echo "numatcl --physcpubind=0-"$tmp" ./$exec_file_name +p"$num_cores" "${load_balancer["$balancer"]} > $tmp_output_file_name
			numactl --physcpubind=0-$tmp ./$exec_file_name +p$num_cores ${load_balancer["$balancer"]} >> $tmp_output_file_name
			cat $tmp_output_file_name >> $data_file_name

			# Obtém o tempo total das iterações e do LB
			IT_time=$(cat $tmp_output_file_name | grep "Iterations total time" | grep -o '[0-9\.].*')
			LB_time=$(cat $tmp_output_file_name | grep "LB total time" | grep -o '[0-9\.].*')
			TOTAL_time=$(echo $IT_time + $LB_time | bc)
		
			# Insere o registro no arquivo de saída principal
			echo $exec_id","$test_counter","$rep_counter","$balancer","$IT_time","$LB_time","$TOTAL_time >> $test_info_file_name

			let rep_counter=$rep_counter+1
		done
		let test_counter=$test_counter+1
	done
	let exec_id=$exec_id+1
done


# Finaliza
rm $tmp_output_file_name

