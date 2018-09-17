# reads csv files
read_file <- function(path, name, header = TRUE){
    fullname <- paste(path, name, sep="/")
    read.csv(fullname, header = header)
}

# discovers the number of runs
find_runs <- function(path, iterations){
    rawdata <- read_file(path,"iter")          #rawdata is a data.frame with a column $iter
    length(rawdata[,1])/ iterations                #number of runs is equal to number of lines divided by the number of iterations printed
}

# parses iteration data while ignoring the iterations that happen before load balancing
parse_iterations <- function(path, iterations, first, after){
    rawdata <- read_file(path,"iter")          #rawdata is a data.frame with a column $iter
    good <- vector("numeric", length(rawdata$iter))
    good <- good + 1:iterations     #number of the iterations inside each run
    #removes the iterations before the first load balancing call
    #and the iterations just after each load balancing call
    index <- (good > first) & (!is.element(good,after)) 
    data <- rawdata$iter[index]
    data
}

# checks the number of runs necessary for statistical confidence
# using Student's t-distribution and an error margin
check_confidence <- function(data, runs, confidence = 0.975, error = 0.05){
    # the predicted number of iterations necessary for such confidence and
    # error is equal to
    # (variance * t^2) / (mean^2 * error^2)
    v <- var(data)
    x <- mean(data)
    t <- qt(confidence, runs-1)
    v*t^2 / (x^2*error^2)
}

# parses load balancing information. returns the means
parse_lb <- function(path, runs){
    rawdata <- read_file(path,"lb")     
    #splits data in different groups: lb time, migrations, and others
    lb_time <- mean(rawdata$end_lb - rawdata$start_lb)
    names(lb_time) <- "lb_time"
    algo_time <- mean(rawdata$end_lba - rawdata$start_lba)
    names(algo_time) <- "algo_time"
    migrations <- mean(rawdata$migrations)
    names(migrations) <- "migrations"
    drops <- c("start_lb", "end_lb", "migrations")
    data <- rawdata[, !(names(rawdata) %in% drops) ]
    #removes the first load balancer call from each run
    good <- vector("numeric", length(data[,1]))
    good <- good + 1:(length(data[,1])/runs)
    data <- data[good > 1,]
    means <- apply(data, 2, mean)
    c(lb_time, algo_time, migrations, means)
}

# parses machine hardware information. returns the means
parse_hw <- function(path, runs){
    rawdata <- read_file(path,"perf")
    data <- apply(rawdata, 2, mean)
    needed_runs <- check_confidence(rawdata$time, runs)
    names(needed_runs) <- "runs.conf"
    names(runs) <- "runs"
    c(data, needed_runs, runs)
}

# parses communication information related to the topology. returns the means
parse_topology <- function(path, type, runs){
    name <- paste("topo", type, sep="_")
    rawdata <- read_file(path, name, FALSE)
    #removes the first load balancer call from each run
    good <- vector("numeric", length(rawdata[,1]))
    good <- good + 1:(length(rawdata[,1])/runs)
    rawdata <- rawdata[good > 1,]
    data <- mean(rawdata)
    names(data) <- fix_names(type, length(data))
    data
}

# changes the name of data in a vector to "name".l{1:size}
fix_names <- function(word, size){
    name <- paste(word, "l", sep=".")
    paste(name, 1:size, sep="")
}

# delivers all communication information related to the topology
parse_communication <- function(path, runs){
    bytes <- parse_topology(path, "bytes", runs)
    messages <- parse_topology(path, "messages", runs)
    bpm <- bytes/messages
    names(bpm) <- fix_names("bpm", length(bpm))
    c(bytes, messages, bpm)
}

# gathers all information for one benchmark with one load balancer
parse_pair <- function(path, iterations, first, after){
    runs <- find_runs(path, iterations)
    hw <- parse_hw(path, runs)
    all_iterations <- parse_iterations(path, iterations, first, after)
    needed_runs <- check_confidence(all_iterations, runs)
    iter <- mean(all_iterations)
    names(needed_runs) <- "iter_time.conf"
    names(iter) <- "iter_time"
    c(iter, needed_runs, hw)
}

# gather information for one benchmark and several load balancers
parse_benchmark <- function(benchmark, lbs, iterations, first, after){
    paths <- paste(benchmark, lbs, sep=".")
    data <- apply(as.array(paths), 1, parse_pair, iterations = iterations, first = first, after = after)
    final_data <- data.frame(data)
    names(final_data) <- lbs
    # removes lines with zero or NaN
    final_data <-final_data[(! is.na(final_data[,2])) & final_data[,2]> 0,]
    final_data
}

#leanmd
leanmd <- function(){
    lmd <- "leanmd"
    lmd_path <- paste(path, lmd, sep="/")
    iterations <- 15
    first <- 1
    after <- c(2, 7, 12)
    parse_benchmark(lmd_path, lbs, iterations, first, after)

}

}

write_csvs <- function(l, path_results){
    write.csv( l, file = paste( path_results, "leanmd8.csv", sep="/" ) )

}

lbs <- c("StatsLB", "HwTopoLB", "GreedyCommLB", "ScotchLB", "RefineCommLB")
path <- "/home/user/Results/machine/date/leanmd2/parsed"
path_results <- "/home/user/Results/output"

l <- leanmd()

write_csvs(l, path_results)
