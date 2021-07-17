#!/usr/bin/env bash

rm -rf deb/usr
mkdir -p deb/usr/include
mkdir -p deb/usr/lib
make
cp -v fromfile.h deb/usr/include
cp -v libfromfile.so deb/usr/lib

cd deb
cd -
dpkg -b deb libfromfile.deb