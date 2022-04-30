#!/bin/bash

mkdir -p build
cmake ./build
make -C ./build # or "cmake --build ./build", this is if your not sure if "make" or something else is being used.

# This is not really needed since the CMake plugin automatically build and runs AND the VS Code debugger builds and runs the applications.
# This is just for reference on how to manually build and run from CMake.
