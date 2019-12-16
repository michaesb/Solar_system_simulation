#!/bin/bash
cd alternative
g++ -O3 RelativisticMercury.cpp -o run_code -std=c++11 -lgomp
time ./run_code
rm run_code
cd ..
