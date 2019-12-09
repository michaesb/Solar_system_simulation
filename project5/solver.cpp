#include "solver.h"


solver::data_vectors solver::velocityVerlet(int n, double T_){
    double distance = planet.dist(planet.Px0, planet.Py0);
    double dt = T_ / (double) n;

    data_vectors data;

    data.Px.push_back(planet.Px0);
    data.Py.push_back(planet.Py0);
    data.Vx.push_back(planet.Vx0);
    data.Vy.push_back(planet.Vy0);

    double ax;
    double ay;
    std::vector<double> aksel;

    for(int i = 0; i < n; i++){
        aksel = planet.accel(data.Px[i], data.Py[i]);
        ax = aksel[0]; ay = aksel[1];
        //ax = planet.accel(data.Px[i], data.Py[i])[0];
        //ay = planet.accel(data.Px[i], data.Py[i])[1];

        data.Px.push_back(data.Px[i] + data.Vx[i] * dt + (dt*dt/2.) * ax);
        data.Py.push_back(data.Py[i] + data.Vy[i] * dt + (dt*dt/2.) * ay);

        aksel = planet.accel(data.Px[i+1], data.Py[i+1]);
        data.Vx.push_back(data.Vx[i] + dt/2. * (aksel[0] + ax));
        data.Vy.push_back(data.Vy[i] + dt/2. * (aksel[1] + ay));
    }

    return data;
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
        axel = planet.accel(data.Px[i], data.Py[i]);
        data.Vx.push_back(data.Vx[i] + axel[0]*dt);
        data.Vy.push_back(data.Vy[i] + axel[1]*dt);
        data.Px.push_back(data.Px[i] + data.Vx[i] * dt);
        data.Py.push_back(data.Py[i] + data.Vy[i] * dt);
    }

    return data;
}
