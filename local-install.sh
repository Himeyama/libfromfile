#!/usr/bin/env bash

make
sudo mkdir -p /usr/include
sudo cp -v fromfile.h /usr/include/
sudo cp -v libfromfile.so /usr/lib/
