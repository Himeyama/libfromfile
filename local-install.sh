#!/usr/bin/env bash

make -j
sudo mkdir -p /usr/include
sudo cp -v fromfile.h /usr/include/
sudo cp -v libfromfile.so /usr/lib/
rm -rf /tmp/libgaussian
