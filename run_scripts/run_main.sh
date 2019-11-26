#!/bin/bash
cd algorithm_c++
g++ -O3 project4.cpp -o run_code -std=c++11 -lgomp
time ./run_code
rm run_code
