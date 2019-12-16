#include "celesBod.cpp"
#include "solver.cpp"
#include "testSystem.cpp"

void mercurySim(int n, double T){
    /*
    Calculates orbits for mercury with and without
    a relativistic gravity.
    Takes timesteps n and timespan T (years).
    */
    double solarmass = 1.989e30; //In kg
    double days = 365.24; // In days


    solver A(n, T, 1);
    celestialBody sun(1,0,0,0,0);
    celestialBody mercury(3.3e23/solarmass, 0, 12.44, 0.3075, 0);
    A.addPlanet(sun);
    A.addPlanet(mercury);
    A.stationaryVelVerlet();


}

int main(){
   if (not run_testfuncs()){
      std::cout << "error in testfunctions" <<std::endl;
      return 0;
   } else std::cout << "test passed" << '\n';

   int n = 1e6; //Number of steps
   double T = 100;//Number of years you will plot

   mercurySim(n, T);

   return 0;
}
