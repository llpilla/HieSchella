# Makefile
# File: "/home/pilla/Repositorios/hieschella/src/Makefile"
# Created: "Wed, 24 Apr 2013 00:38:11 -0300 (pilla)"
# Updated: "Ter, 02 Jun 2015 17:47:11 -0300 (pilla)"
# $Id$
#
FLAGS=-Wall -g
INCLUDE=-I${HOME}/hwloc/include -I${INC}
LIBRARY=-L${HOME}/hwloc/lib -L. -lhwloc -lhieschella -L${LIB} -lm
CC=gcc
LMBENCH=../lmbench3/bin/x86_64-linux-gnu/lmbench.a
BIN=../bin
INC=../include
LIB=../lib
TOPO=../topology

all: library profile read 
#network

library: topology_model.o 
	${CC} -shared -o ${LIB}/libhieschella.so topology_model.o

topology_model.o: topology_model.c ${INC}/topology_model.h
	${CC} -c -fpic topology_model.c ${FLAGS} ${INCLUDE}

profile: memory_profile.c memory_profile.h library
	${CC} memory_profile.c ${FLAGS} ${LMBENCH} ${INCLUDE} ${LIBRARY} -lm -o ${BIN}/memory_profile

read: read_topology.c library
	${CC} read_topology.c ${FLAGS} ${INCLUDE} ${LIBRARY} -o ${BIN}/read_topology

#network: network_extension.c network_extension.h library
#	${CC} network_extension.c ${FLAGS} ${INCLUDE} ${LIBRARY} -lm -o ${BIN}/network_extension

clean:
	rm ${BIN}/* ${LIB}/*
