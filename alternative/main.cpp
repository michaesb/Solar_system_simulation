#include "celesBod.cpp"
#include "celesBod.h"
#include "solver.cpp"
//#include "solver.h"
//#include <iostream>

int main(){
     double earthmass = 0.000003003; //earth mass in solar masses
     solver B(1e6, 36);
     celestialBody sun(1, 0, 0, 0, 0);
     celestialBody planet2(earthmass, -1.602723439211851e-02*365.24, 6.882264719474028e-03*365.24, 3.983744251977597e-01, 9.025161878539018e-01); //mass, vx, vy, px, py
     celestialBody planet3(0.0009543*1000, 365.24*7.452252471233350e-03, 365.24*7.603499279291407e-04, 2.806426180901584e-01, -5.232008081884607);
     B.addPlanet(sun);
     B.addPlanet(planet2);
     B.addPlanet(planet3);
     B.stationaryVelVerlet();

     std::cout<<"x position of planet is "<<B.returnPlanet(0).returnPosition()[0]<<std::endl;
     std::cout<<"y position of planet is "<<B.returnPlanet(0).returnPosition()[1]<<std::endl;

     return 0;
}
