#!/usr/bin/env bash

git clone --depth 1 https://github.com/himeyama/libfromfile.git /tmp/libfromfile
cd /tmp/libfromfile
make -j
sudo mkdir -p /usr/local/include
sudo cp -v fromfile.h /usr/local/include/
sudo cp -v libfromfile.so /usr/lib/
rm -rf /tmp/libgaussian
