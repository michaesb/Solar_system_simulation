#include "celesBod.cpp"
#include "celesBod.h"
#include "solver.cpp"
//#include "solver.h"
//#include <iostream>

int main(){
     double earthmass = 0.000003003; //earth mass in solar masses
     solver B(1e5, 1);
     celestialBody planet(earthmass, 0, 6.28, 1, 0);
     celestialBody planet2(1, 0, 0, 0, 0);
     B.addPlanet(planet);
     B.addPlanet(planet2);
     B.velocityVerlet();

     std::cout<<"x position of planet is "<<B.returnPlanet(0).returnPosition()[0]<<std::endl;
     std::cout<<"y position of planet is "<<B.returnPlanet(0).returnPosition()[1]<<std::endl;

     return 0;
}
