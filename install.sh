#!/usr/bin/env bash

git clone --depth 1 https://github.com/himeyama/libfromfile.git /tmp/libfromfile
cd /tmp/libfromfile
make -j
sudo mkdir -p /usr/include
sudo cp -v fromfile.h /usr/include/
sudo cp -v libfromfile.so /usr/lib/
rm -rf /tmp/libgaussian
