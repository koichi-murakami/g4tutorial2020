#!/bin/sh
#########################################################################
# This is a script to build a tutorial application
#########################################################################

### Set variables
assumedDir="P06_PrimaryGenerator"
nameFileSource="./util/G4Codes/PrimaryGenerator.cc_MyGen"
nameFileHeader="./util/G4Codes/PrimaryGenerator.hh_MyGen"

### Check whether in the right directory
currentDir=`basename $(pwd)`
if [ $currentDir != $assumedDir ] ; then
  echo "Error: The script is only allowed to execute under '$assumedDir'"
  exit 1
fi

### Copy the source/header files to the target
cp $nameFileSource ./source/src/PrimaryGenerator.cc
cp $nameFileHeader ./source/include/PrimaryGenerator.hh

### Clean up work directories
if [ -d build ] ; then
  rm -r build
fi

if [ -d bin ] ;then
  rm -r bin
fi

### Build using cmake
mkdir build
cd build
cmake ../source
make
make install
