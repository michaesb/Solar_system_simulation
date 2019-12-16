#!/bin/bash
cd alternative
g++ -O3 SolarSystemSim.cpp -o run_code -std=c++11 -lgomp
time ./run_code
rm run_code
cd ..

python plotting_python/nbody_plotter.py
