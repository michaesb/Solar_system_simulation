#!/bin/bash
cd alternative
g++ -O3 3_body_problem.cpp -o ./3_body -std=c++11 -lgomp
time ./3_body
rm 3_body
cd ..

python plotting_python/3_body_plotter.py
