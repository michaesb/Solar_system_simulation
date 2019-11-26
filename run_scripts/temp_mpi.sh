cd algorithm_c++
mpic++ -Ofast -o run_code temperature_optimized.cpp -std=c++11 -lgomp -Wall -fopenmp
mpirun --use-hwthread-cpus ./run_code
rm run_code
