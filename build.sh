#!/bin/bash

mkdir -p build
cmake ./build
make -C ./build # or "cmake --build ./build", this is if your not sure if "make" or something else is being used.
