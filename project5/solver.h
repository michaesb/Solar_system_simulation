#include <vector>
#include <cmath>
#include <string>

class solver{

  friend class celestialBody;

  vector <celestialBody> planets;
  int totalPlanets;
  int n;
  double T;

  void initializeVariables(int n_, double T_ ){
      totalPlanets = 0;
      n = n_;
      T = T_;
      vector<double> positions;
      vector<double> velocities;
  }

public:
  void velocityVerlet(int n, double T_);
  void eulerForward(int n, double T_);
  std::vector<double> accel(double Px, double Py);
  std::vector<double> accel(double P1x, double P1y,double P2x, double P2y,
                            double m1, double m2);
  void addPlanet(celestialBody planet);

  solver(int n_, double T_){
      initializeVariables(n_, T_);
  }

};
