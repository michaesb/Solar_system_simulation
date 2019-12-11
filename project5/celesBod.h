#pragma once

class celestialBody{

  friend class solver;

  double mass;
  double Px0, Py0, Vx0, Vy0;

  void initializeVariables(double mass_, double Vx0_, double Vy0_, double Px0_, double Py0_){
    mass = mass_;
    Px0 = Px0_;
    Py0 = Py0_;
    Vx0 = Vx0_;
    Vy0 = Vy0_;
  }

  double dist(double Px, double Py);
  double normOfP(double P, double norm);

public:
  celestialBody(double mass_, double Vx0, double Vy0, double Px0, double Py0){
    initializeVariables(mass_, Vx0, Vy0, Px0, Py0);
  }

};
