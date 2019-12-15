#pragma once

class celestialBody{

  friend class solver;

  double mass;
  vector<double> P, V;

  void initializeVariables(double mass_, double Vx0, double Vy0, double Px0, double Py0){
    mass = mass_;
    P.push_back(Px0);
    P.push_back(Py0);
    V.push_back(Vx0);
    V.push_back(Vy0);
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
