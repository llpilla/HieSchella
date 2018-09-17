#!/bin/bash
# File: "/home/llpilla/numalb/src/hieschella/install.sh"
# Created: "Thu, 02 May 2013 15:42:08 -0300 (llpilla)"
# Updated: "Thu, 02 May 2013 15:56:56 -0300 (llpilla)"
# $Id$
# Copyright (C) 2013, Laércio Lima Pilla <llpilla@inf.ufrgs.br> 

# Prepares directories
for DIR in "include lib topology bin"
do
    if [ ! -d "$DIR" ]; then
        mkdir $DIR
    fi
done

# Sets the path for the topology files
sed s:TOPOLOGYPATH:`pwd`: < src/base_topology_model.h > include/topology_model.h

# Calls make
make

