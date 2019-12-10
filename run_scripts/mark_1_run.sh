#!/bin/bash
cd project5
g++ -O3 mark_1.cpp -o run_code -std=c++11 -lgomp
time ./run_code
rm run_code
