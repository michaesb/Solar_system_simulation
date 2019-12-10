#include "celesBod.h"


double celestialBody::dist(double Px, double Py){
  return sqrt(Px*Px+Py*Py);
}

std::vector<double> celestialBody::accel(double Px, double Py){
    /*Calculates the acceleration given the x and y positions
    The first argument given will be used to calculate the norm vector*/

    double r_sq = Px*Px+Py*Py;
    double normx = Px/sqrt(r_sq);
    double normy = Py/sqrt(r_sq);

    std::vector<double> acc;

    double accel = -(4 * M_PI * M_PI) / (r_sq);

    acc.push_back(accel*normx);
    acc.push_back(accel*normy);

    return acc;
}

std::vector<double> celestialBody::accel(double P1x, double P1y,
     double P2x, double P2y, double m1, double m2){
/*Calculates the acceleration between two celestial bodies*/
    std::vector<double> acc;

    double x3 = P1x - P2x;
    double y3 = P1y - P2y;

    double length_3 = dist(x3, y3);

    double x_norm3 = x3/length_3;
    double y_norm3 = y3/length_3;

    double acc_3 = (4 * M_PI * M_PI * m1 * m2)/(length_3*length_3);

    double x_acc = acc_3*x_norm3;
    double y_acc = acc_3*y_norm3;

    acc.push_back(x_acc);
    acc.push_back(y_acc);

    return acc;
}

double celestialBody::normOfP(double P, double norm){
  return  P / norm;
}
