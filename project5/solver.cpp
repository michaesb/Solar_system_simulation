#include "solver.h"


void solver::velocityVerlet(int n, double T_){
    double distance = planet.distance(planet.Px0, planet.Py0);
    double dt = T_ / (double) n;

    data_vectors data;

    data.Px.push_back(planet.Px0);
    data.Py.push_back(planet.Py0);
    data.Vx.push_back(planet.Vx0);
    data.Vy.push_back(planet.Vy0);

    double ax;
    double ay;

    for(int i = 0; i < n; i++){
        ax = accel(distance, planet.normOfP(data.Px[i]/P_init));
        ay = accel(distance, planet.normOfP(data.Py[i]/P_init));
        data.Px.push_back(data.Px[i] + data.Vx[i] * dt + (dt*dt/2.) * ax);
        data.Py.push_back(data.Py[i] + data.Vy[i] * dt + (dt*dt/2.) * ay);
        data.Vx.push_back(data.Vx[i] + dt/2. * (accel(sqrt(data.Px[i+1]*data.Px[i+1]+data.Py[i+1]*data.Py[i+1]), (double)data.Px[i+1]/distance) + ax));
        data.Vy.push_back(data.Vy[i] + dt/2. * (accel(sqrt(data.Px[i+1]*data.Px[i+1]+data.Py[i+1]*data.Py[i+1]), (double)data.Py[i+1]/distance) + ay));
    }

    //return data;
}
