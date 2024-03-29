#include "celesBod.cpp"
#include "solver.cpp"
#include "testSystem.cpp"

void nbodySim(int n, double T){
    /*
    takes timesteps n and timespan T and calculates orbits
    for the solar system.
    Uses data taken for november 29th 2019 from NASA
    */
    double solarmass = 1.989e30; //In kg
    double days = 365.24; // In days
    solver problemSolver(n, T);
    //celestialBody sun(1, -0.003080543390131623, -0.0005977882238506849, 0, 0);
    celestialBody sun(1, 0, 0, 0, 0);
    celestialBody earth(0.000003003, -1.602723439211851e-02*days, 6.882264719474028e-03*days, 3.983744251977597e-01, 9.025161878539018e-01); //mass, vx, vy, px, py
    celestialBody jupiter(0.0009543, days*7.452252471233350e-03, days*7.603499279291407e-04, 2.806426180901584e-01, -5.232008081884607);
    celestialBody mercury(3.3e23/solarmass, -1.927416352956285e-02*days, -2.350148494621872e-02*days, -3.053920471115882e-01, 1.669887871076899e-01);
    celestialBody mars(6.4171e23/solarmass, 4.935409489817506e-03*days, -1.208287844100836e-02*days, -1.539687230099815, -5.117081813732122e-01);
    celestialBody venus(48.685e23/solarmass, 1.494114742824526e-02*days, 1.341363073826836e-02*days, 4.849822091423722e-01, -5.420468872336146e-01);
    celestialBody saturn(5.6834e26/solarmass, 4.899996437554958e-03*days, 2.006400834137427e-03*days, 3.636150583043191, -9.355788660474625);
    celestialBody uranus(86.813e24/solarmass, -2.259745292235776e-03*days, 3.051765014003087e-03*days, 1.630040575228520e1, 1.127855557318932e1);
    celestialBody neptune(102.413e24/solarmass, 6.652990225832408e-04*days, 3.085677390122435e-03*days, 2.922102933897389e1, -6.469052215342025);
    celestialBody pluto(1.307e22/solarmass, 2.973503675535460e-03*days, 5.186275321374038e-04*days, 1.287831056516992e1, -3.138764791245833e1);
    problemSolver.addPlanet(sun);
    problemSolver.addPlanet(earth);
    problemSolver.addPlanet(jupiter);
    problemSolver.addPlanet(mercury);
    problemSolver.addPlanet(mars);
    problemSolver.addPlanet(venus);
    problemSolver.addPlanet(saturn);
    problemSolver.addPlanet(uranus);
    problemSolver.addPlanet(neptune);
    problemSolver.addPlanet(pluto);
    problemSolver.velocityVerlet();


}

int main(){
   if (not run_testfuncs()){
      std::cout << "error in testfunctions" <<std::endl;
      return 0;
   } else std::cout << "test passed" << '\n';

   //values are taken from november 29th 2019
   int n = 1e6; //Number of steps
   double T = 100;//Number of years you will plot

   nbodySim(n, T);

   return 0;
}
