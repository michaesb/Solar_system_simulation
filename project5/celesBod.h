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
  std::vector<double> accel(double Px, double Py);
  std::vector<double> accel(double P1x, double P1y,double P2x, double P2y, double m1, double m2);
  double normOfP(double P, double norm);

public:
  celestialBody(double mass_, double Vx0, double Vy0, double Px0, double Py0){
    initializeVariables(mass_, Vx0, Vy0, Px0, Py0);
  }

};
