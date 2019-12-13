#pragma once

class celestialBody{

  friend class solver;

  double mass;
  std::vector<double> velocity;
  std::vector<double> position;

  void initializeVariables(double mass_, double Vx0, double Vy0, double Px0, double Py0){
    mass = mass_;
    position.push_back(Px0);
    position.push_back(Py0);
    velocity.push_back(Vx0);
    velocity.push_back(Vy0);
  }

  double dist(double Px, double Py);
  double normOfP(double P, double norm);

public:
  celestialBody(double mass_, double Vx0, double Vy0, double Px0, double Py0){
    initializeVariables(mass_, Vx0, Vy0, Px0, Py0);
  }

};
