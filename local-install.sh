#!/usr/bin/env bash

make -j
sudo mkdir -p /usr/local/include
sudo cp -v fromfile.h /usr/local/include/
sudo cp -v libfromfile.so /usr/lib/
rm -rf /tmp/libgaussian
