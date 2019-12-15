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
      initializeVariables(1, 0, 6.28, 1, 0);
  }

public:
    //functions
    std::vector<double> returnVelocity();
    std::vector<double> returnPosition();
    double returnMass();
    void assignVelocity(double new_vx, double new_vy);
    void assignPosition(double new_px, double new_py);
  //constructor
  celestialBody(double mass_, double Vx0, double Vy0, double Px0, double Py0){
    initializeVariables(mass_, Vx0, Vy0, Px0, Py0);
  }
  celestialBody(){
      initializeVariables();
  }
};
