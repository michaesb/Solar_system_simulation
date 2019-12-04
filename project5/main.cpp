#include <iostream>
#include <vector>
#include <cmath>
#include "testSystem.cpp"

#define G 6.67e-11
#define MSUN 2e30
#define AU

double accel(double r, double P_norm){
  //d²X/dt²
  double acc = -(4 * M_PI * M_PI)*P_norm / (r*r);
  return acc;
}

void eulerForward(double initialVx, double initialVy, double Posx, double Posy, int n){
  double P_init = sqrt(Posx*Posx + Posy*Posy);
  double T = 0.00001; //year
  double dt = T / (double) n ;
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
   std::cout << "Position" << "(" << Px[i] << "," << Py[i] << ")" << '\n';
   std::cout << "Velocity" << "(" << Vx[i] << "," << Vy[i] << ")" << '\n';
   std::cout << "-----------------------------------------------" << '\n';


   Vx.push_back(Vx[i] + accel(sqrt(Px[i]*Px[i]+Py[i]*Py[i]), (double)Px[i]/P_init) *dt );
   Vy.push_back(Vy[i] + accel(sqrt(Px[i]*Px[i]+Py[i]*Py[i]), (double)Py[i]/P_init) *dt );
   Px.push_back(Px[i] + Vx[i] * dt);
   Py.push_back(Py[i] + Vy[i] * dt);

  }

}

int main(){

if(run_testfuncs){
  eulerForward(0,6.284,1,0,1e+5);
}else{
  std::cout << "There is an error in the test functions" << '\n';
}

}

/*

def orbiting_planets(N, Nplanets):
    Planetposition = np.zeros((2,Nplanets,N))
    for n in range(Nplanets):
        vx = planetsvx0[n]
        vy = planetsvy0[n]
        Planetposition[:,n,0] = planetsx0[n], planetsy0[n]
        for i in range(N-1):
            ax = -Planetposition[0,n,i]*(G*starmass)/ ((np.sqrt(Planetposition[0,n,i]**2+ Planetposition[1,n,i]**2))**3)
            ay = -Planetposition[1,n,i]*(G*starmass)/ ((np.sqrt(Planetposition[0,n,i]**2+ Planetposition[1,n,i]**2))**3)
            vx, vy = vx + ax*dt, vy + ay*dt
            Planetposition[:,n,i+1] = Planetposition[0,n,i] + vx*dt, Planetposition[1,n,i] + vy*dt
    return Planetposition
*/
