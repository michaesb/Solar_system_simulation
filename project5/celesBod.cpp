#include "celesBod.h"


double celestialBody::dist(double Px, double Py){
  return sqrt(Px*Px+Py*Py);
}

double celestialBody::normOfP(double P, double norm){
  return  P / norm;
}
