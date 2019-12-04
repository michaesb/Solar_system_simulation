#-*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

from ast2000solarsystemviewer_v2 import AST2000SolarSystemViewer
from ast2000solarsystemviewer_v2 import *
seed = 28424
system = AST2000SolarSystemViewer(seed)

planetsRadius = system.radius #[km]
planetsMass = system.mass #[solar masses] .
print (planetsMass)
planetsx0 = system.x0 #[AU] .
planetsy0 = system.y0 #[AU] .
planetsvx0 = system.vx0 #[AU] .
planetsvy0 = system.vy0 #[AU] .
rho0 = system.rho0 #[kg/m^3] .

# Data about the system .
G = 4*np.pi*np.pi # Gravitational constantint astronomical units .
Nplanets = system.number_of_planets # Number of planets in the system. 8 planets
starradius = system.star_radius # Radius of star,[km]
starmass = system.star_mass # Mass of the star, [solarmasses] .
startemperature = system.temperature # Surfacetemperature of the star,[K]

dt = 0.01 #år
N = 10000

t= np.linspace(0,dt*N,N)

def orbiting_planets(N, Nplanets):
    Planetposition = np.zeros((2,Nplanets,N))
    for n in range(Nplanets):
        vx = planetsvx0[n]
        vy = planetsvy0[n]
        Planetposition[:,n,0] = planetsx0[n], planetsy0[n]
        for i in range(N-1):
            ax = -Planetposition[0,n,i]*(G*starmass)/ ((np.sqrt(Planetposition[0,n,i]**2+ Planetposition[1,n,i]**2))**3)
            ay = -Planetposition[1,n,i]*(G*starmass)/ ((np.sqrt(Planetposition[0,n,i]**2+ Planetposition[1,n,i]**2))**3)
            vx, vy = vx + ax*dt, vy + ay*dt
            Planetposition[:,n,i+1] = Planetposition[0,n,i] + vx*dt, Planetposition[1,n,i] + vy*dt
    return Planetposition

#system.orbit_xml(orbiting_planets(N,Nplanets),t)
Planetposition = orbiting_planets(N,Nplanets)
plt.plot(Planetposition[0,0,:], Planetposition[1,0,:])
#plt.plot(Planetposition[0,1,:], Planetposition[1,1,:])
plt.plot(Planetposition[0,2,:], Planetposition[1,2,:])
#plt.plot(Planetposition[0,3,:], Planetposition[1,3,:])
plt.plot(Planetposition[0,4,:], Planetposition[1,4,:])
#plt.plot(Planetposition[0,5,:], Planetposition[1,5,:])
#plt.plot(Planetposition[0,6,:], Planetposition[1,6,:])
plt.plot(Planetposition[0,7,:], Planetposition[1,7,:])
plt.scatter([0],[0])
plt.title('planets orbit the sun')
plt.legend(['1 planet','2 planet', '3 planet', '4 planet', 'sun'])
plt.xlabel('distance [m]')
plt.axis('equal')
plt.grid()
plt.show()
