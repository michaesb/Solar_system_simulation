#include <vector>
#include <cmath>

class solver{

  friend class celestialBody;

  celestialBody& planet;

  struct data_vectors{
    /*vectors which store the initial velocities and initial positions
    of the celestial body*/
    std::vector<double> Px, Py, Vx, Vy;
  };

  solver(celestialBody& planet_){
    planet = planet_;
  }

};
