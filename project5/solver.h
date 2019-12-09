#include <vector>
#include <cmath>

class solver{

  friend class celestialBody;

  celestialBody planet;

public:

  struct data_vectors{
    /*vectors which store the initial velocities and initial positions
    of the celestial body*/
    std::vector<double> Px, Py, Vx, Vy;
  };

  solver::data_vectors velocityVerlet(int n, double T_);
  solver::data_vectors eulerForward(int n, double T_);

  solver(celestialBody planet_):planet(planet_){

  }

};
