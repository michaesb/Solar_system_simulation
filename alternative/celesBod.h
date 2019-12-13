#pragma once
#include<vector>

class celestialBody{

  friend class solver;

  //class variables
  double mass;
  std::vector<double> velocity;
  std::vector<double> position;

 //intializer function
  void initializeVariables(double mass_, double Vx0, double Vy0, double Px0, double Py0){
    mass = mass_;
    position.push_back(Px0);
    position.push_back(Py0);
    velocity.push_back(Vx0);
    velocity.push_back(Vy0);
  }

  void initializeVariables(){
      mass = 1;
      position.push_back(1);
      position.push_back(0);
      velocity.push_back(0);
      velocity.push_back(6.28);
  }
