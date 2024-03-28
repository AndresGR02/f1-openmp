#!/usr/bin/bash

if [ ! -d build ]; then
    cmake -S . -B ./build
fi

cmake --build ./build

./build/f1kart -fopenmp
