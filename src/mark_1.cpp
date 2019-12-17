#include <iostream>
#include <vector>
#include <cmath>

#include "c++FileWriter.cpp"
// #include "celesBod.cpp"
// #include "celesBod.h"
// #include "solver.cpp"
// #include "solver.h"

#define G 6.67e-11
#define MSUN 2e30
#define AU


double accel(double r, double Pos){
  //d²X/dt²
  return -(4 * M_PI * M_PI)*Pos/ (r*r*r);
}

struct storing_vectors{
  std::vector<double> Vx,Vy,Px,Py;
};

storing_vectors velocityVerlet(double initialVx, double initialVy, double Posx, double Posy, int n, double Time){
    double P_init = sqrt(Posx*Posx + Posy*Posy);
    double dt = Time / (double) n;
    std::cout << "dt = " << dt << '\n';
    std::vector<double> Vx,Vy,Px,Py;
    Vx.push_back(initialVx);
    Vy.push_back(initialVy);
    Px.push_back(Posx);
    Py.push_back(Posy);
    double ax;
    double ay;

    for(int i = 0; i < n; i++){
        ax = accel(sqrt(Px[i]*Px[i]+Py[i]*Py[i]), Px[i]);
        ay = accel(sqrt(Px[i]*Px[i]+Py[i]*Py[i]), Py[i]);

        Px.push_back(Px[i] + Vx[i] * dt + (dt*dt/2.) * ax);
        Py.push_back(Py[i] + Vy[i] * dt + (dt*dt/2.) * ay);
        Vx.push_back(Vx[i] + dt/2. * (accel(sqrt(Px[i+1]*Px[i+1]+Py[i+1]*Py[i+1]), (double)Px[i+1]/P_init) + ax));
        Vy.push_back(Vy[i] + dt/2. * (accel(sqrt(Px[i+1]*Px[i+1]+Py[i+1]*Py[i+1]), (double)Py[i+1]/P_init) + ay));
    }
    storing_vectors vec_vel_pos = {Vx,Vy,Px,Py};
    return vec_vel_pos;
}

storing_vectors eulerForward(double initialVx, double initialVy, double Posx, double Posy, int n, double Time){
    double P_init = sqrt(Posx*Posx + Posy*Posy);
    double dt = Time /(double) n;
    std::vector<double> Vx,Vy,Px,Py;
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

  int n = 1e4;
  double Time = 1; //year
  double vx_initial = 0;
  double vy_initial = 2*M_PI; //escape
  // double vy_initial = 2*M_PI; //orbit
  double px_initial = 1;
  double py_initial = 0;


  storing_vectors eul_vel_pos = eulerForward(vx_initial,vy_initial,
                                             px_initial,py_initial,n,Time);
  write_to_file_vector(eul_vel_pos.Vx,eul_vel_pos.Vy,
                       eul_vel_pos.Px,eul_vel_pos.Py,
                       n, "euler_planet");
  storing_vectors vec_vel_pos = velocityVerlet(vx_initial,vy_initial,
                                              px_initial,py_initial,n,Time);
  write_to_file_vector(vec_vel_pos.Vx,vec_vel_pos.Vy,
                       vec_vel_pos.Px,vec_vel_pos.Py,
                       n, "verlet_planet");


}
