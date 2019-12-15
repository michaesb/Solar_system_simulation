#!/bin/bash
cd alternative
g++ -O3 main.cpp -o run_code -std=c++11 -lgomp
time ./run_code
rm run_code
cd ..

xterm -T "Verlet_plot " -geometry 80x24--11+0 -hold -e 'python plotting_python/nbody_plotter.py;' &
