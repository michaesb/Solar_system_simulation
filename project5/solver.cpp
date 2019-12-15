#include "solver.h"




void solver::addPlanet (celestialBody planet){
    planets.push_back(planet);
    totalPlanets++;
}



std::vector<double> solver::accel(double Px, double Py){
    /*Calculates the acceleration given the x and y positions
    The first argument given will be used to calculate the norm vector*/

    double r_sq = Px*Px+Py*Py;
    double normx = Px/sqrt(r_sq);
    double normy = Py/sqrt(r_sq);

    std::vector<double> acc;

    double accel = -(4 * M_PI * M_PI) / (r_sq);

    acc.push_back(accel*normx);
    acc.push_back(accel*normy);

    return acc;
}



std::vector<double> solver::accel(double P1x, double P1y,
     double P2x, double P2y, double m1, double m2){
/*Calculates the acceleration between two celestial bodies*/
    std::vector<double> acc;

    double x3 = P1x - P2x;
    double y3 = P1y - P2y;

    double length_3 = sqrt(x3*x3 + y3*y3);

    double x_norm3 = x3/length_3;
    double y_norm3 = y3/length_3;

    double acc_3 = (4 * M_PI * M_PI * m1 * m2)/(length_3*length_3);

    double x_acc = acc_3*x_norm3;
    double y_acc = acc_3*y_norm3;

    acc.push_back(x_acc);
    acc.push_back(y_acc);

    return acc;
}


void solver::writefile(){
    /*
    Adds a line of data to file.
    */
}

void solver::eulerForward(){
    /*
    Finds planet positions using the forward euler integration method
    */
}

/*

void solver::velocityVerlet(int n, double T_){
    double distance = planet.dist(planet.Px0, planet.Py0);
    double dt = T_ / (double) n;

    data_vectors data;


    double ax;
    double ay;
    std::vector<double> aksel;

    for(int i = 0; i < n; i++){
        for (int p = 0; p < totalPlanets; p++){
            data.Px.push_back(totalPlanets[p].Px0);
            data.Py.push_back(totalPlanets[p].Py0);
            data.Vx.push_back(planet.Vx0);
            data.Vy.push_back(planet.Vy0);

            aksel = accel(data.Px[i], data.Py[i]);
            ax = aksel[0];
            ay = aksel[1];

            data.Px.push_back(data.Px[i] + data.Vx[i] * dt + (dt*dt/2.) * ax);
            data.Py.push_back(data.Py[i] + data.Vy[i] * dt + (dt*dt/2.) * ay);

            aksel = planet.accel(data.Px[i+1], data.Py[i+1]);
            data.Vx.push_back(data.Vx[i] + dt/2. * (aksel[0] + ax));
            data.Vy.push_back(data.Vy[i] + dt/2. * (aksel[1] + ay));
        }
    }
    write_file(data.Vx, data.Vy, data.Px, data.Py, n, "verlet_planet_"+to_string(p));
}

solver::data_vectors solver::eulerForward(int n, double T_){
    double dt = T_ /(double) n;

    data_vectors data;
    std::vector<double> axel;

    data.Vx.push_back(planet.Vx0);
    data.Vy.push_back(planet.Vy0);
    data.Px.push_back(planet.Px0);
    data.Py.push_back(planet.Py0);

    for(int i = 0; i < n; i++){
        axel = accel(data.Px[i], data.Py[i]);
        data.Vx.push_back(data.Vx[i] + axel[0]*dt);
        data.Vy.push_back(data.Vy[i] + axel[1]*dt);
        data.Px.push_back(data.Px[i] + data.Vx[i] * dt);
        data.Py.push_back(data.Py[i] + data.Vy[i] * dt);
    }

    return data;
}
*/
