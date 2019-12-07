#include "celesBod.h"


double celestialBody::distance(double Px, double Py){
  return sqrt(Px*Px+Py*Py);
}

double celestialBody::accel(double dist, double Pnorm){
    return -(4 * M_PI * M_PI)*Pnorm / (dist);
}

double celestialBody::normOfP(double P, double norm){
  return  P / norm;
}
