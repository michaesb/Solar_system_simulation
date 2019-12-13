#include "celesBod.cpp"
#include "celesBod.h"
#include "solver.cpp"
//#include "solver.h"
#include <iostream>


int main(){
     solver B(1, 2);
     celestialBody planet;
     celestialBody planet2(1, 0, 0, 0, 0);
     B.addPlanet(planet);
     B.addPlanet(planet2);
     std::vector<double> grav;
     grav = B.gravity(0, 1);
     std::cout<<grav[0]<<std::endl;
     return 0;
}
