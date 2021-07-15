#!/usr/bin/env bash

mkdir -p deb/usr/include
mkdir -p deb/usr/lib
make
cp -v fromfile.h deb/usr/include
cp -v libfromfile.so deb/usr/lib

cd deb
cd -
dpkg -b deb libfromfile.deb