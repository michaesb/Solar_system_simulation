#pragma once
#include <vector>

class celesBod{

    //physical properties
    double mass;
    std::vector<double> position; //x,y
    std::vector<double> velocity; //x,y

public:
     celesBod(){
        /*
        If no inital conditions are given, sets them to standard ones.
        */
        mass = 1;
        velocity.push_back(0);
        velocity.push_back(6.28);
        position.push_back(1);
        position.push_back(0);

    }

    celesBod(double m0, double vx0,
                                 double vy0, double px0, double py0){
        /*
        initializes the class with inital variables
        */
        mass = m0;
        velocity.push_back(vx0);
        velocity.push_back(vy0);
        position.push_back(px0);
        position.push_back(py0);
    }


    double returnPos();


        //initalizing
        //celesBod();
        //celesBod(double m0, double vx0, double vy0,
        //              double px0, double py0);

};




/*
#ifndef PLANET_H
#define PLANET_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
using std::vector;


class planet
{
public:
    // Properties
    double mass;
    double position[3];
    double velocity[3];
    double potential;
    double kinetic;

    // Initializers
    planet();
    planet(double M,double x,double y,double z,double vx, double vy,double vz);

    // Functions
    double distance(planet otherPlanet);
    double GravitationalForce(planet otherPlanet, double Gconst);
    double Acceleration(planet otherPlanet, double Gconst);
    double KineticEnergy();
    double PotentialEnergy(planet &otherPlanet, double Gconst, double epsilon);

};

#endif // PLANET_H


*/
