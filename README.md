

##COMPUTATIONAL PHYSICS PROJECT 3

This is a computational project in FYS-3150/4150 at UIO. In this project, we test the efficacy of the Markov Chain Monte Carlo method Metropolis algorithm by computing the solutions for the Ising model of a ferromagnetic material. The program will calculate and print the numerical result of the methods used.

The program will print in the console the estimated values, temperature and number of Monte Carlo Cycles.
The number of Monte Carlo cycles is inbuilt and cannot be change by the user unless it is changed directly from the source code. Be careful when indicating MC, since the time of ths program increases quite rapidly.


## Getting Started

Download all files (or clone the branch) into your computer. If you have linux, it will be pretty straightforward to run.
If you have a C++ compiler in your Windows machine, we invite you to use it, but problems may arise. Check the file run_main.sh and check the compilation flags.
These are very important for the functioning of the program.
If you are using Linux terminal for running the program, just run the script run_main.sh and it will do the job for you.
´´´
./run_scripts/run_main.sh
´´´
There are different run_scripts that will create different kinds of data, but all of them will be written to a textfile in the textfiles folder. In order to aboid overwritting the data, we have had git ignore the texfiles, so they might not be seen by your editor. 
We have 4 run_scripts in this repository: 
run_main: uses one core and compute one system value. A function can be uncommented to run for different Mc-cycles
temp_run.sh uses all available cores to run the algorithm for multiple temperature for a constant MC-value
opt_run.sh uses all available cores to run the algorithm for multiple Mc_values for a constant temperaturs
begin_work.sh this is just a comfortable way of starting the atom editor and open the project description. 
### Prerequisites

Make sure you have OpenMP's library mpi.h installed in your computer, either is it windows or linux. We recommend a minimum of 4 core processor, but the more cores you have,the quicker the fastet the programs will run. A minimum of 2 GB of RAM will do.

### Installing

-Download all the files from the Master branch.
-Keep them all in the same folder and place them in a sensible place (ie. desktop)

FOR LINUX:
-Get some coffee and have fun

FOR WINDOWS:
-Install mpi.h library. (Or make sure you have it with a small test)
-Make a new project in the test editor or IDE of your choice. Set the compiler settings to have the flags you can find in run_main.sh (Open it as a text file or see below):
                                                  g++ -O3 project3.cpp -o run_code -std=c++11 -lgomp

-Try and see if it works.
-If a error pops out which says that the functions are being defined twice, comment or erase #include <x.cpp> (all of them) from project3.cpp.
-Good luck

## Running the tests

The tests are run automatically by the run_main.sh. You will know the tests passed if you get to see it printed in your console.


### Coding tests

The tests will check three things:

The random number generator.
-Checks the "randomness" of the generator. Generates a big number of random numbers, sums them and calculates the average. It should be approximately 0.5.
This is checked in this function.

The general Metropolis method.
-Compares the values of the metropolis algorithm for a 2x2 lattice with the analytical values which are known


At the moment of running the optimized code, you may see some warnings. This is normal, and it isnt a problem.


## Built With

* [OpenMP] Used to paralelize the code (https://www.openmp.org/resources/openmp-compilers-tools/)


## Authors

[Project4] https://github.uio.no/michaesb/project4_fys_MiSIAK

Silvia Morales     Michael Bitney        Aksel Graneng

## License

This project is licensed under Creative Commons waiver.

## Acknowledgments

* Morten Hjorth-jensen and group teachers in FYS3150/4150
