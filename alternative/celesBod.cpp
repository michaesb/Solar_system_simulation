#include "celesBod.h"

std::vector<double> celestialBody::returnVelocity(){
    return velocity;
}

std::vector<double> celestialBody::returnPosition(){
    return position;
}


double celestialBody::returnMass(){
    /*
    returns mass of celestial body
    */
    return mass;
}
