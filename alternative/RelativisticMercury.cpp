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
    solver A(n, T);
    celestialBody sun(1,0,0,0,0);
    celestialBody mercia(3.3e23/solarmass, 0, 12.44, 0.3075, 0);
    A.addPlanet(sun);
    A.addPlanet(mercia);
    A.stationaryVelVerlet();

    double angle_1 = atan(A.returnPlanet(1).returnPosition()[1]
                          /A.returnPlanet(1).returnPosition()[0])/3600;

    solver B(n, T, 1);
    B.addPlanet(sun);
    B.addPlanet(mercia);
    B.stationaryVelVerlet();

    double angle_2 = atan(B.returnPlanet(1).returnPosition()[1]
                         /B.returnPlanet(1).returnPosition()[0])/3600;

    // std::cout<<"non-relativistic perihelion precession is: "
    //          <<angle_1 << " degrees"<<std::endl;
    // std::cout<<"relativistic perihelion precession is: "
    //          <<angle_2 <<" degrees"<<std::endl;
}

int main(){
   if (not run_testfuncs()){
      std::cout << "error in testfunctions" <<std::endl;
      return 0;
   } else std::cout << "test passed" << '\n';

   int n = 1e4; //Number of steps
   double T = 100;//Number of years you will plot

   mercurySim(n, T);

   return 0;
}
