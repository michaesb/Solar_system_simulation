#include "celesBod.cpp"
#include "celesBod.h"
#include "solver.cpp"
//#include "solver.h"
//#include <iostream>

int main(){
     solver B(1, 2);
     celestialBody planet;
     celestialBody planet2(1, 0, 0, 0, 0);
     celestialBody planet3(1, 0, 0, 2, 0);
     B.addPlanet(planet);
     B.addPlanet(planet2);
     B.addPlanet(planet3);
     std::vector<std::vector<double>> testaccel;
     testaccel = B.gravityVec();
     std::cout<<testaccel[0][0]<<std::endl;
     return 0;
}
