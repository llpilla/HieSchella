# /bin/bash

BASE_DIR=$(pwd)
LBS_DIR=$BASE_DIR/load_balancers
CHARM_DIR=$HOME/charm

# Copy LB files to Charm++

cp $LBS_DIR/* $CHARM_DIR/tmp/
cp $BASE_DIR/charm_extras/* $CHARM_DIR/tmp/

# Enter Charm++ directory and install LB
cd $CHARM_DIR/tmp
./Makefile_lb.sh
make depends
make charm++ OPTS="-O2"
