#!/bin/bash
cd project5
g++ -O3 mark_1.cpp -o run_code -std=c++11 -lgomp
time ./run_code
rm run_code
cd ..

xterm -T "Euler_plot " -geometry 80x24--11+360 -hold -e 'python plotting_python/euler_plot.py;' &
xterm -T "Verlet_plot " -geometry 80x24--11+0 -hold -e 'python plotting_python/verlet_plot.py;' &
sleep 10
rm textfiles/euler_planet.txt
rm textfiles/verlet_planet.txt
