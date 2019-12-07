#include <iostream>
#include <vector>
#include <cmath>
#include "testSystem.cpp"
#include "c++FileWriter.cpp"
#include "celesBod.cpp"
#include "celesBod.h"
#include "solver.cpp"


#define G 6.67e-11
#define MSUN 2e30
#define AU




int main(){

  if (not run_testfuncs){
    std::cout << "There is an error in the test functions" << '\n';
    return 0;}

  int n = 1e+5;
  double vx_in = 0;
  double vy_in = 6.248; //6.284
  double px_in = 1;
  double py_in = 0;

  celestialBody planet(10.0, vx_in, vy_in, px_in, py_in);
  solver A(planet);
  solver::data_vectors V;

  V = A.velocityVerlet(n, 100);
/*
  //storing_vectors eul_vel_pos = eulerForward(vx_initial,vy_initial,px_initial,py_initial,n);
  write_to_file_vector(V.Vx,V.Vy,
                       V.Px,V.Py,
                       n, "euler_planet");

                       */
  //storing_vectors vec_vel_pos = velocityVerlet(vx_initial,vy_initial,px_initial,py_initial,n); //6.284

  write_to_file_vector(V.Vx, V.Vy,
                       V.Px, V.Py,
                       n, "verlet_planet");

}