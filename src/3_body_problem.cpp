#include "celesBod.cpp"
#include "solver.cpp"
#include "testSystem.cpp"

void Jupiter_bodySim(int n, double T){
    /*
    takes timesteps n and timespan T and calculates orbits
    for the solar system.
    Uses data taken for november 29th 2019 from NASA
    */
    double solarmass = 1.989e30; //In kg
    double days = 365.24; // In days
    solver problemSolver(n, T);
    celestialBody sun(1, 0, 0, 0, 0);
    celestialBody earth(0.000003003, -1.602723439211851e-02*days, 6.882264719474028e-03*days, 3.983744251977597e-01, 9.025161878539018e-01); //mass, vx, vy, px, py
    celestialBody jupiter(0.0009543*1000, days*7.452252471233350e-03, days*7.603499279291407e-04, 2.806426180901584e-01, -5.232008081884607);
    problemSolver.addPlanet(sun);
    problemSolver.addPlanet(earth);
    problemSolver.addPlanet(jupiter);
    problemSolver.stationaryVelVerlet();
}

int main(){
   if (not run_testfuncs()){
      std::cout << "error in testfunctions" <<std::endl;
      return 0;
   } else std::cout << "test passed" << '\n';

   //values are taken from november 29th 2019
   int n = 12*1e6; //Number of steps
   double T = 12;//Number of years you will plot
   std::cout << "dt = " << T/(double)n << '\n';
   Jupiter_bodySim(n, T);

   return 0;
}
