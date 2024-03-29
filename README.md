

# Solar system Simulation

This is a computational project in FYS-3150/4150 at UIO. In this project we will look at a model of the solar system using Velocity Verlet algorithm. The data used in the initial condition of planet objects was been taken from the NASA site http://ssd.jpl.nasa.gov/horizons.cgi#top the 29th of November of 2019. Changes in data are possible

## Getting Started

Download all files (or clone the branch) into your computer. If you have linux, it will be pretty straightforward to run.
If you have a C++ compiler in your Windows machine, we invite you to use it, but problems may arise. Check the file run_main.sh and check the compilation flags.
These are very important for the functioning of the program.
If you are using Linux terminal for running the program, just run the script run_main.sh and it will do the job for you.

##### ./run_scripts/run_main.sh

There are different run_scripts that will create different kinds of data, but all of them will be written to a textfile in the textfiles folder. In order to avoid overwritting the data, we have had git ignore the texfiles, so they might not be seen by your editor.
We have 4 run_scripts in this repository:
###### run_main: Uses one core and compute one system value. A function can be uncommented to run for different Mc-cycles.
###### mark_1_run.sh: Runs the functions and returns text files with the data.
###### 3_body_problem: Plots the orbits of a 3 body system made up by Earth, Sun (static) and Jupiter.
###### begin_work.sh: This is just a comfortable way of starting the atom editor and open the project description.
###### plotting.sh: Runs and plots the orbit of the Earth with Euler Forward and Velocity Verlet.
###### solar_system_sim.sh: Simulates all major celestial bodies in the solar system with a dynamic sun.
###### perihelion_run.sh: Generates 2 txt files containing position and velocity of mercury and the sun using a relativistic gravity. In its current state, it will generate 2 txt files of size 4 Gb.

### Prerequisites

We recommend a minimum of 4 core processor, but the more cores you have, the quicker the programs will run. A minimum of 2 GB of RAM will do.

### Installing

-Download all the files from the Master branch.
-Keep them all in the same folder and place them in a sensible place (ie. desktop)

FOR LINUX:
-Get some coffee and have fun

FOR WINDOWS:
-Make a new project in the test editor or IDE of your choice. Set the compiler settings to have the flags you can find in run_main.sh (Open it as a text file or see below):
#### g++ -O3 project3.cpp -o run_code -std=c++11 -lgomp

-Try and see if it works.
-If a error pops out which says that the functions are being defined twice, comment or erase #include <x.cpp> (all of them) from main.cpp.
-Good luck

## Running the tests

The tests are run automatically by the run_main.sh. You will know the tests passed if you get to see it printed in your console.

### Coding tests

The tests will check two things:

Circular orbit test
-Checks that a celestial body which we know has a circular orbit returns (aproximately) to the starting point after one period.
-Checks that for a celestial body, the momentum and potential energy of the celestial body are conserved (aproximately since the numerical methods do have a "loss" in energy)
Both parameters will ensure a stability of the orbits.

Gravity function
-Checks that the gravity function returns expected values for a celestial body
This will ensure we get reasonable results for gravity between bodies

## Report

[FYS_Project5_Report.pdf](https://github.com/michaesb/Solar_system_simulation/FYS_Project5_Report.pdf) - Our report for the project





## Authors

[Project5] https://github.com/michaesb/Solar_system_simulation

Silvia Morales     Michael Bitney        Aksel Graneng

## License

This project is licensed under Creative Commons waiver.

## Acknowledgments

* Morten Hjorth-jensen and group teachers in FYS3150/4150
