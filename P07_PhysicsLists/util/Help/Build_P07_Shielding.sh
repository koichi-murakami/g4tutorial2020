#!/bin/sh
#########################################################################
# This is a script to build a tutorial application
#########################################################################

### Set variables
assumedDir="P07_PhysicsLists"
nameFileSource="./util/G4Codes/P04_Application_Main.cc_Shielding"

### Check whether in the right directory
currentDir=`basename $(pwd)`
if [ $currentDir != $assumedDir ] ; then
  echo "Error: The script is only allowed to execute under '$assumedDir'"
  exit 1
fi

### Copy the source file to the target
cp $nameFileSource ./source/Application_Main.cc

### Clean up work directories
if [ -d build ] ; then
  rm -r build
fi

if [ -d bin ] ; then
  rm -r bin
fi

### Build using cmake
mkdir build
cd build
cmake ../source
make
make install
