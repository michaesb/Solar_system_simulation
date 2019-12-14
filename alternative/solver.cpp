#include "solver.h"

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

std::vector<double> solver::gravity(int i, int j){
    /*
    Takes 2 indices and returns gravitational pull
    between the two planets of given index.
    Gives force from planet i to planet j
    */

    //finding planets and extracting values
    celestialBody planet1 = returnPlanet(i);
    celestialBody planet2 = returnPlanet(j);

    std::vector<double> P1pos = planet1.returnPosition();
    std::vector<double> P2pos = planet2.returnPosition();

    double P1x = P1pos[0];
    double P1y = P1pos[1];
    double P1mass = planet1.returnMass();
    double P2x = P2pos[0];
    double P2y = P2pos[1];
    double P2mass = planet2.returnMass();

    //creating vector from planet 1 to planet 2
    double r3x = P2x - P1x;
    double r3y = P2y - P1y;

    //finding unit vector
    double unitr3x = r3x /(sqrt(r3x*r3x + r3y*r3y));
    double unitr3y = r3y /(sqrt(r3x*r3x + r3y*r3y));

    double Gmark = 4*M_PI*M_PI*P1mass*P2mass/(r3x*r3x + r3y*r3y);
    double forcex = Gmark*unitr3x;
    double forcey = Gmark*unitr3y;

    std::vector<double> forces;
    forces.push_back(forcex);
    forces.push_back(forcey);
    return forces;
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
}
