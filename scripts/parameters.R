#Base parameters for the script
base_name <- "~/Desktop/parsenetwork/pingo-"    #path and file name
cns <- 16                                       #number of compute nodes
last <- cns-1                                   #last compute node id
machines <- as.array(0:last)                    #all compute node ids
output_name <- "network"                        #path and file name for the output
