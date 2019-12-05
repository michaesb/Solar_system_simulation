#include <iostream>
#include <vector>
#include <cmath>
#include "testSystem.cpp"
#include "c++FileWriter.cpp"

#define G 6.67e-11
#define MSUN 2e30
#define AU

double accel(double r, double P_norm){
  //d²X/dt²
  double acc = -(4 * M_PI * M_PI)*P_norm / (r*r);
  return acc;
}

struct storing_vectors{
  std::vector<double> Vx,Vy,Px,Py;
};

storing_vectors eulerForward(double initialVx, double initialVy, double Posx, double Posy, int n){
    double P_init = sqrt(Posx*Posx + Posy*Posy);
    double T = 1; //year
    double dt = T / (double) n;
    std::vector<double> Vx;
    std::vector<double> Vy;
    std::vector<double> Px;
    std::vector<double> Py;

    Vx.push_back(initialVx);
    Vy.push_back(initialVy);
    Px.push_back(Posx);
    Py.push_back(Posy);

    for(int i = 0; i < n; i++){

        // std::cout << accel(sqrt(Px[i]*Px[i]+Py[i]*Py[i]), (double)Px[i]/P_init) << '\n';
        // std::cout << accel(sqrt(Px[i]*Px[i]+Py[i]*Py[i]), (double)Py[i]/P_init) << '\n';
        // std::cout << "Position" << "(" << Px[i] << "," << Py[i] << ")" << '\n';
        // std::cout << "Velocity" << "(" << Vx[i] << "," << Vy[i] << ")" << '\n';
        // std::cout << "-----------------------------------------------" << '\n';
        Vx.push_back(Vx[i] + accel(sqrt(Px[i]*Px[i]+Py[i]*Py[i]), (double)Px[i]/P_init) *dt );
        Vy.push_back(Vy[i] + accel(sqrt(Px[i]*Px[i]+Py[i]*Py[i]), (double)Py[i]/P_init) *dt );
        Px.push_back(Px[i] + Vx[i] * dt);
        Py.push_back(Py[i] + Vy[i] * dt);
    }
    storing_vectors vec_vel_pos = {Vx,Vy,Px,Py};
    return vec_vel_pos;
}

int main(){

  if (not run_testfuncs){
    std::cout << "There is an error in the test functions" << '\n';
    return 0;}

    storing_vectors vec_vel_pos = eulerForward(0,6.284,1,0,1e+5);
    write_to_file_vector(vec_vel_pos.Vx,vec_vel_pos.Vy,
                         vec_vel_pos.Px,vec_vel_pos.Py,
                          1e+5, "euler_planet");

    std::cout << "Perfectly balanced as all things should be" << '\n';

}
