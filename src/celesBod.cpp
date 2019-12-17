#include "celesBod.h"

std::vector<double> celestialBody::returnVelocity(){
    /*
    Returns velocity vector of the celestial body
    */
    return velocity;
}

std::vector<double> celestialBody::returnPosition(){
    /*
    Returns position vector of the celestial body
    */
    return position;
}


double celestialBody::returnMass(){
    /*
    returns mass of celestial body
    */
    return mass;
}
