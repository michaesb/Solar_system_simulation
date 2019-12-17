#include <iostream>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

bool testing_orbit(int& nr){
    /*
    Tests for stable orbits with inital conditions that
    cause a perfect circular orbit.
    Tests position, energy conservation and momentum conservation.
    */
  nr++;
  double solarmass = 1.989e30; //In kg
  double days = 365.24; // In days
  int n = 1e3; //Number of steps
  double T = 1;//Number of years you will plot
  double tol = 1e-8;//tolerance value
  double earthmass = 0.000003003;//In solar masses

  solver B(n, T);
  celestialBody sun(1, 0, 0, 0, 0); //mass,vx,vy,px,py
  celestialBody earth(earthmass, 0, 2*M_PI, 1, 0);
  B.addPlanet(sun);
  B.addPlanet(earth);
  B.velocityVerlet();
  celestialBody earth_future = B.returnPlanet(1);
  double xpos = earth_future.returnPosition()[0];
  double ypos = earth_future.returnPosition()[1];


  //speed of planet at the end of simulation
  double endspeed = sqrt(earth_future.returnVelocity()[0]
                         *earth_future.returnVelocity()[0]
                         + earth_future.returnVelocity()[1]
                         *earth_future.returnVelocity()[1]);

  //distance from sun to planet at the end of simulation
  double endDist = sqrt(xpos*xpos + ypos*ypos);

  //initial mechanical energy
  double init_energy = (0.5*earthmass*4*M_PI*M_PI
                        + 4*M_PI*M_PI*earthmass);
 //mechanical energy at the end of simulation
  double end_energy = (0.5*earthmass*endspeed*endspeed
                       + 4*M_PI*M_PI*earthmass/endDist);
  //initual momentum
  double init_momentum = fabs(earthmass*(2*M_PI));

  //momentum at the end of the simulation
  double end_momentum = fabs(earthmass*(xpos*earth_future.returnVelocity()[1]
                                       -ypos*earth_future.returnVelocity()[0]));

  //defining boolean variables that test the simulation
  bool positionVar = (fabs(xpos - 1) < tol);
  bool energyVar = (fabs(init_energy - end_energy) < tol);
  bool momentumVar = (fabs(init_momentum - end_momentum) < tol);

  //asserting the boolean variables
  if(positionVar && energyVar && momentumVar){
      return true;
  }
  else{
      return false;
  }


}

bool testing_gravity(int& nr){
    /*
    tests function gravity in solver
    */
    nr++;
    double earthmass = 0.000003003;//solar masses
    int n = 0; //Number of steps
    double T = 0;//Number of years you will plot
    bool tol = 1e-10;


    //initializing solver
    solver testGrav(n, T);
    celestialBody sun;
    celestialBody earth(earthmass, 0, 0, 1, 0);
    testGrav.addPlanet(sun);
    testGrav.addPlanet(earth);

    //finding computed gravity
    std::vector<double> grav = testGrav.gravity(1, 0);
    double xgrav = grav[0]; double ygrav = grav[1];

    //setting expected gravity
    double expected_xgrav = -4*M_PI*M_PI*earthmass;
    double expected_ygrav = 0;

    //defining bools that test computed values
    bool xVar = (fabs(xgrav - expected_xgrav) < tol);
    bool yVar = (fabs(ygrav - expected_ygrav) < tol);

    //asserting bools
    if(xVar && yVar){
        return true;
    }
    else{
        return false;
    }

}



bool run_testfuncs(){
  //runs all the testfunctions

  int nr_tests = 0;
  bool test1 = testing_orbit(nr_tests);
  bool test2 = testing_gravity(nr_tests);

  if (test1 + test2 == nr_tests){
    return true;
  }else {
    std::cout << "tests: 1: "  << test1 << " 2: " << test2 << '\n';
    return false;
  }
}
