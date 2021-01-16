#!/bin/bash
cd "`dirname "$0"`"
export PATH=$PATH:"`pwd`"
xattr -rc .
clear
echo 'wd:' `pwd`
./ampl -v
