#!/bin/bash

mkdir -p build

g++ -std=c++17 src/main.cpp \
    -o build/Zynthezizer \
    $(pkg-config --cflags --libs raylib)
