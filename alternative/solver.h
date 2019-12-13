#include <vector>
#include <cmath>
#include <string>

class solver{

  friend class celestialBody;
  int n;
  double T;
  std::vector<celestialBody> solarSystem;

  void initializeVariables(int n_, double T_){
      n = n_;
      T = T_;
  }

public:

    solver(int n_, double T_){
    }

    //functions
    void addPlanet(celestialBody planet);
    celestialBody returnPlanet(int index);
    std::vector<double> gravity(int i, int j);
};
