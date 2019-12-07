#include "solver.h"


solver::data_vectors solver::velocityVerlet(int n, double T_){
    double distance = planet.distance(planet.Px0, planet.Py0);
    std::cout << distance << '\n';
    double dt = T_ / (double) n;

    data_vectors data;

    data.Px.push_back(planet.Px0);
    data.Py.push_back(planet.Py0);
    data.Vx.push_back(planet.Vx0);
    data.Vy.push_back(planet.Vy0);

    std::cout << data.Px[0]<<" " << data.Py[0]<<" " << data.Vx[0]<< " "<< data.Vy[0] << '\n';

    double ax;
    double ay;

    for(int i = 0; i < n; i++){
        ax = planet.accel(distance, planet.normOfP(data.Px[i],distance));
        ay = planet.accel(distance, planet.normOfP(data.Py[i],distance));
        data.Px.push_back(data.Px[i] + data.Vx[i] * dt + (dt*dt/2.) * ax);
        data.Py.push_back(data.Py[i] + data.Vy[i] * dt + (dt*dt/2.) * ay);
        data.Vx.push_back(data.Vx[i] + dt/2. * (planet.accel(sqrt(data.Px[i+1]*data.Px[i+1]+data.Py[i+1]*data.Py[i+1]), (double)data.Px[i+1]/distance) + ax));
        data.Vy.push_back(data.Vy[i] + dt/2. * (planet.accel(sqrt(data.Px[i+1]*data.Px[i+1]+data.Py[i+1]*data.Py[i+1]), (double)data.Py[i+1]/distance) + ay));
    }

    return data;
}
/*
data_vectors eulerForward(int n, double T_){
    double distance = planet.distance(planet.Px0, planet.Py0);
    double dt = T_ /(double) n;

    data_vectors data;

    data.Vx.push_back(planet.Vx0);
    data.Vy.push_back(planet.Vy0);
    data.Px.push_back(planet.Px0);
    data.Py.push_back(planet.Py0);

    for(int i = 0; i < n; i++){
        data.Vx.push_back(data.Vx[i] + planet.accel(distance, (double)data.Px[i]/P_init) *dt );
        data.Vy.push_back(data.Vy[i] + planet.accel(distance, (double)data.Py[i]/P_init) *dt );
        data.Px.push_back(data.Px[i] + data.Vx[i] * dt);
        data.Py.push_back(data.Py[i] + data.Vy[i] * dt);
    }

    return data;
}
*/
