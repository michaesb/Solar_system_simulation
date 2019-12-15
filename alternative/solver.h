#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

class solver{
/*
Class for solving n-body problem.
Initializes with arguments n and T.
n is number of time steps. T is time in years.
*/
  friend class celestialBody;
  //define class variables
  int n;
  double T;
  double dt;
  int planetNr;
  std::vector<celestialBody> solarSystem;
  bool delta;

  void initializeVariables(int n_, double T_){
      //initializer. n_ is nr of timesteps, T_ is time in years.
      n = n_;
      T = T_;
      planetNr = 0;
      dt = T/(double)n;
      delta = 0;
  }

  void initializeVariables(int n_, double T_, bool delta_){
      /*
      Initializer for overloading constructor
      For use when relativity is relevant
      */
      n = n_;
      T = T_;
      planetNr = 0;
      dt = T/(double)n;
      delta = delta_;
  }

public:
    //constructor
    solver(int n_, double T_){
        initializeVariables(n_, T_);
    }
    solver(int n_, double T_, bool delta_){
        initializeVariables(n_, T_, delta_);
    }

    //functions
    void addPlanet(celestialBody planet);
    celestialBody returnPlanet(int index);
    double angularMom(int index);
    void fileInitializer(std::string filename);
    void fileWriter(int i, std::string filename);
    std::vector<double> gravity(int i, int j);
    std::vector<std::vector<double>> gravityVec();
    void velocityVerlet();
    void stationaryVelVerlet();

};
