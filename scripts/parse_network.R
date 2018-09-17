#How to use this script
#1) check the parameters in parameters.R
#2) run R --vanilla < parse_network.R
#3) use the output with bin/network_extension

get_metrics <- function( name, machine, last ){
    #Reads the results for a compute node
    #Style: Neighbor , Bytes , Total.time..usecs. , Mean.time..usecs.
    data <- read.csv( name, comment.char= "#" )

    #Removes the first row data has "(all data)"
    #and transforms all vectors to numeric
    bytes  <- as.numeric(as.vector(data$Bytes[2:length(data$Bytes)]))
    times <- as.numeric(as.vector(data$Mean.time..usecs.[2:length(data$Mean.time..usecs.)]))
    neighbors <- as.numeric(as.vector(data$Neighbor[2:length(data$Neighbor)]))

    output <- matrix( nrow = last+1, ncol = 2)

    #Applies a linear regression for each neighbor
    for( i in 0:last ){
        if( i != machine ){
            model <- lm( times ~ bytes, subset = (neighbors == i)&(bytes<=16384))
            # latency in ns
            output[ i+1,1 ] <- (model$coefficients[1]*1000)/2  
            model <- lm( times ~ bytes, subset = (neighbors == i)&(bytes>=32768))
            # bandwidth in MB/s
            output[ i+1,2 ] <- 1/model$coefficients[2]
        }
        else {
            output[ i+1,1 ] <- 1000.0   # 1 us latency
            output[ i+1,2 ] <- 10000.0  # 10.000 MB/s bandwidth
        }
    }
    output
}

parse_machine <- function( machine, last, base_name ){
    name <- paste( base_name, machine, ".log", sep="" )
    get_metrics( name, machine, last )
}

source("parameters.R")

#Gets latencies and bandwidths for all compute nodes
metrics <- apply(machines, 1, parse_machine, last = last, base_name = base_name)

#Write them in the output file
write(cns, ncolumns=1, file = output_name)
write(cns, ncolumns=1, file = output_name, append = TRUE)
write(metrics[1:cns,], ncolumns=cns, file = output_name, append = TRUE)
write(metrics[(cns+1):(cns*2),], ncolumns=cns, file = output_name, append = TRUE)

