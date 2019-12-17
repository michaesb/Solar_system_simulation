#include "solver.h"

#define C 63198 //Speed of light in AU
#define GM 4*M_PI*M_PI

void solver::addPlanet(celestialBody planet){
    /*
    Adds a new planet to the solar system
    */
    planetNr ++;
    solarSystem.push_back(planet);
}

celestialBody solver::returnPlanet(int index){
    /*
    Returns planet from solarSystem
    */
    return solarSystem[index];
}

inline double solver::angularMom(int index){
    /*
    Returns angular momentum of planet with given index
    */
    celestialBody plany = solarSystem[index];
    return plany.mass*(plany.position[0]*plany.velocity[1]
                       -plany.position[1]*plany.velocity[0]);

}

void solver::fileInitializer(std::string filename){
    /*
    Writes the first line of a file with filename on csv format
    */
    std::string path = "../textfiles/" + filename + ".txt";
    std::ofstream file(path);
    file << "VelocityX" << "," << "VelocityY" << ",";
    file << "PositionX" << "," << "PositionY" << "\n";
}

void solver::fileWriter(int i, std::string filename){
    /*
    Adds info from planet i to file with name filename on csv format
    */

    std::ofstream file;
    file.open("../textfiles/" + filename + ".txt", std::ios::app);
    file << solarSystem[i].velocity[0] << ",";
    file << solarSystem[i].velocity[1] << ",";
    file << solarSystem[i].position[0] << ",";
    file << solarSystem[i].position[1] << "\n";
}


std::vector<double> solver::gravity(int i, int j){
    /*
    Takes 2 indices and returns gravitational pull
    between the two planets of given index.
    Gives force from planet i to planet j
    */

    //finding planets and extracting values
    celestialBody planet1 = returnPlanet(i);
    celestialBody planet2 = returnPlanet(j);



    double P1x = planet1.returnPosition()[0];
    double P1y = planet1.returnPosition()[1];
    double P1mass = planet1.returnMass();
    double P2x = planet2.returnPosition()[0];
    double P2y = planet2.returnPosition()[1];
    double P2mass = planet2.returnMass();

    //creating vector from planet 1 to planet 2
    double r3x = P2x - P1x;
    double r3y = P2y - P1y;

    //finding unit vector
    double unitr3x = r3x /(sqrt(r3x*r3x + r3y*r3y));
    double unitr3y = r3y /(sqrt(r3x*r3x + r3y*r3y));

    double Gmark = (GM*P1mass*P2mass/(r3x*r3x + r3y*r3y))
                    *relativityFactor(i, delta, P1x, P1y);


    double forcex = Gmark*unitr3x;
    double forcey = Gmark*unitr3y;

    std::vector<double> forces;
    forces.push_back(forcex);
    forces.push_back(forcey);
    return forces;
}

double solver::relativityFactor(int i, bool delta, double Px, double Py){
  /*
  If delta is true, relativity is taken into consideration for calculating the force
  */
  double angMom_sqr = angularMom(i)*angularMom(i);
  double r_sqr = sqrt(Px*Px+Py*Py);

  if(r_sqr > 1e-5){
      return (1 + (delta*3*angMom_sqr)/(r_sqr*C*C));
  }
  else{
      return 1;
  }
}

std::vector<std::vector<double>> solver::gravityVec(){
    /*
    Returns a vector with acceleration vectors for planets in solarSystem
    */
    std::vector<std::vector<double>> gravitatas;
    double gravtempx;
    double gravtempy;
    std::vector<double> gravtempvec;

    for(int i=0; i<planetNr; i++){
        gravtempx = 0;
        gravtempy = 0;

        for(int j=0; j<planetNr; j++){
            if(i != j){
                gravtempx += gravity(i, j)[0]/solarSystem[i].mass;
                gravtempy += gravity(i, j)[1]/solarSystem[i].mass;
            }
        }

        gravtempvec.push_back(gravtempx);
        gravtempvec.push_back(gravtempy);
        gravitatas.push_back(gravtempvec);
        gravtempvec.clear();
    }
    return gravitatas;
}


void solver::velocityVerlet(){
    /*
    Implementation of the velocity verlet integration method.
    finds the final position and velocity of planets in solver
    */
    std::vector<std::vector<double>> accel1;
    std::vector<std::vector<double>> accel2;

    //Initializes files
    for(int k = 0; k < planetNr; k++){
        fileInitializer("planet"+std::to_string(k));
        fileWriter(k, "planet"+std::to_string(k));
    }

    //loop through timesteps
    for(int i = 0; i < n; i++){
        //calculating initial gravitational acceleration
        accel1 = gravityVec();
        //loop for updating positions
        for (int k = 0; k < planetNr; k++){
            //x component of position
            solarSystem[k].position[0] = solarSystem[k].position[0]
                                       + solarSystem[k].velocity[0]*dt
                                       + (dt*dt/2.0)*accel1[k][0];
            //y component of position
            solarSystem[k].position[1] = solarSystem[k].position[1]
                                       + solarSystem[k].velocity[1]*dt
                                       + (dt*dt/2.0)*accel1[k][1];
        }
        //calculating secondary gravitational acceleration
        accel2 = gravityVec();
        //loop for updating velocities
        for(int k = 0; k<planetNr; k++){
            //x component of velocity
            solarSystem[k].velocity[0] = solarSystem[k].velocity[0]
                                       + (dt/2.0)*(accel2[k][0]+ accel1[k][0]);
            //y component of velocity
            solarSystem[k].velocity[1] = solarSystem[k].velocity[1]
                                       + (dt/2.0)*(accel2[k][1]+ accel1[k][1]);
        }
        //writing planet values to files

        if(n>1e4){
            if (i%(int)(1/((1e4)/n)) == 0){
                for(int k = 0; k<planetNr; k++){
                    fileWriter(k, "planet"+std::to_string(k));
                }
            }
        }
        else{
            for(int k = 0; k<planetNr; k++){
                fileWriter(k, "planet"+std::to_string(k));
            }
        }

    }
}

void solver::stationaryVelVerlet(){
    /*
    Implementation of the velocity verlet integration method.
    Finds the final position and velocity of planets in solarSystem.
    Does not update the first celestial body in solarSystem.
    If this is the sun, the system is centered on the sun.
    */
    std::vector<std::vector<double>> accel1;
    std::vector<std::vector<double>> accel2;

    //Initializes files
    for(int k = 0; k < planetNr; k++){
        fileInitializer("planet"+std::to_string(k));
        fileWriter(k, "planet"+std::to_string(k));
    }

    //loop through timesteps
    for(int i = 0; i < n; i++){
        //calculating initial gravitational acceleration
        accel1 = gravityVec();
        //loop for updating positions
        for (int k = 1; k < planetNr; k++){
            //x component of position
            solarSystem[k].position[0] = solarSystem[k].position[0]
                                       + solarSystem[k].velocity[0]*dt
                                       + (dt*dt/2.0)*accel1[k][0];
            //y component of position
            solarSystem[k].position[1] = solarSystem[k].position[1]
                                       + solarSystem[k].velocity[1]*dt
                                       + (dt*dt/2.0)*accel1[k][1];
        }
        //calculating secondary gravitational acceleration
        accel2 = gravityVec();
        //loop for updating velocities
        for(int k = 1; k<planetNr; k++){
            //x component of velocity
            solarSystem[k].velocity[0] = solarSystem[k].velocity[0]
                                       + (dt/2.0)*(accel2[k][0]+ accel1[k][0]);
            //y component of velocity
            solarSystem[k].velocity[1] = solarSystem[k].velocity[1]
                                       + (dt/2.0)*(accel2[k][1]+ accel1[k][1]);
        }
        //writing planet values to files

        if(n>1e4){
            if (i%(int)(1/((1e4)/n)) == 0){
                for(int k = 0; k<planetNr; k++){
                    fileWriter(k, "planet"+std::to_string(k));
                }
            }
        }
        else{
            for(int k = 0; k<planetNr; k++){
                fileWriter(k, "planet"+std::to_string(k));
            }
        }

    }
}
