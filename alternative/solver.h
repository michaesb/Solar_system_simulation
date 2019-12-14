#include <vector>
#include <cmath>
#include <string>
#include <iostream>

class solver{
/*
Class for solving n-body problem.
Initializes with arguments n and T.
n is number of time steps. T is time in years.
*/
  friend class celestialBody;
  //define global variable
  int n;
  double T;
  double dt;
  int planetNr;
  std::vector<celestialBody> solarSystem;

  void initializeVariables(int n_, double T_){
      //initializer. n_ is nr of timesteps, T_ is time in years.
      n = n_;
      T = T_;
      planetNr = 0;
      dt = T/(double)n;
  }

public:
    //constructor
    solver(int n_, double T_){
        initializeVariables(n_, T_);
    }

    //functions
    void addPlanet(celestialBody planet);
    celestialBody returnPlanet(int index);
    std::vector<double> gravity(int i, int j);
    std::vector<std::vector<double>> gravityVec();
    void velocityVerlet();

};
