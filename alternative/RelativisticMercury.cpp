#include "celesBod.cpp"
#include "solver.cpp"
#include "testSystem.cpp"

void mercurySim(int n, double T){
    /*
    Calculates orbits for mercury with and without
    a relativistic gravity.
    Takes timesteps n and timespan T (years).
    */
    solver A(n, T);
    celestialBody sun(1,0,0,0,0);
    celestialBody mercia(3.3e23/solarmass, 0, 12.44, 0.3075, 0);
    A.addPlanet(sun);
    A.addPlanet(mercia);
    A.stationaryVelVerlet();

    double angle a1 = atan(A.returnPosition()[1]/A.returnPosition()[0]);

    solver B(n, T);
    celestialBody sun(1,0,0,0,0);
    celestialBody mercia(3.3e23/solarmass, 0, 12.44, 0.3075, 0);
    B.addPlanet(sun);
    B.addPlanet(mercia);
    B.stationaryVelVerlet();

}

int main(){
   if (not run_testfuncs()){
      std::cout << "error in testfunctions" <<std::endl;
      return 0;
   } else std::cout << "test passed" << '\n';

   //values are taken from november 29th 2019
   double solarmass = 1.989e30; //In kg
   double days = 365.24; // In days
   int n = 1e4; //Number of steps
   double T = 30;//Number of years you will plot

   return 0;
}
