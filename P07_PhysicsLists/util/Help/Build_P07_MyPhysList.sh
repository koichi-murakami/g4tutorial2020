#!/bin/sh
#########################################################################
# This is a script to build a tutorial application
#########################################################################

### Set variables
assumedDir="P07_PhysicsLists"
nameFileSource_1="./util/G4Codes/P04_Application_Main.cc_MyPhysList"
nameFileSource_2="./util/G4Codes/P04_MyPhysicsList.hh_MyPhysList"
nameFileSource_3="./util/G4Codes/P04_MyPhysicsList.cc_MyPhysList"

### Check whether in the right directory
currentDir=`basename $(pwd)`
if [ $currentDir != $assumedDir ] ; then
  echo "Error: The script is only allowed to execute under '$assumedDir'"
  exit 1
fi

### Copy the source file to the target
cp $nameFileSource_1 ./source/Application_Main.cc
cp $nameFileSource_2 ./source/include/MyPhysicsList.hh
cp $nameFileSource_3 ./source/src/MyPhysicsList.cc

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
