import numpy as np
import matplotlib.pyplot as plt
from ast2000solarsystem_36_v4 import AST2000SolarSystem as as3
import Astlib as asl
import time
start1 = time.time()
seed = 8055
MSS = as3(seed)
N = MSS.number_of_planets
n = int(5e5)
planetpos = np.zeros((2, N, n)); planetvels = np.zeros((2, N, 2))
planetpos[0,:,0] = MSS.x0; planetpos[1,:,0] = MSS.y0
planetvels[0,:,0] = MSS.vx0;planetvels[1,:,0] = MSS.vy0
t = 15
dt = t/n

sunpos = np.zeros((2,n))
bigplanpos = np.zeros((2,n))
sunvelo = np.zeros((2,n))
bigplanvelo = np.zeros((2,n))


vels = planetvels[:,:,0]
initpos = planetpos[:,:,0]
sm = MSS.star_mass
T = MSS.period/365

p = 4
rad = np.pi/2


massvec = MSS.mass

bigplanpos[:,0] = planetpos[:,p,0]


def gravity(r,sm):
    G = 4*np.pi**2
    R = np.linalg.norm(r,axis = 0)
    unitr = r/R
    g = -G*(sm/R**2)*unitr
    return g

def sungrav(r1,r2,m):
    G = 4*np.pi**2
    R = np.linalg.norm(r1-r2,axis = 0)
    unitr = (r1-r2)/R
    g = -G*(m/R**2)*unitr
    return g


bigplanvels0 = vels[:,p] + sungrav(bigplanpos[:,0],sunpos[:,0],sm)*dt/2
sunvels0 = sungrav(sunpos[:,0],bigplanpos[:,0],massvec[p])*dt/2
vels0 = vels + gravity(planetpos[:,:,0],sm) * dt/2

for i in range(n-1):
    vels0 += gravity(planetpos[:,:,i],sm)*dt
    planetpos[:,:,i+1] = planetpos[:,:,i] + vels0 * dt


    
def inter(bigplanpos,sunpos,bigplanvels0,sunvels0,n,dt):
    for i in range(n-1):
         sunvels0 += sungrav(sunpos[:,i],bigplanpos[:,i],massvec[p])*dt
         sunpos[:,i+1] = sunpos[:,i] + sunvels0*dt
         sunvelo[:,i+1] = sunvelo[:,i] + sungrav(sunpos[:,i], bigplanpos[:,i], massvec[p])*dt
    
         bigplanvels0 += sungrav(bigplanpos[:,i],sunpos[:,i],sm)*dt
         bigplanpos[:,i+1] = bigplanpos[:,i] + bigplanvels0 * dt
         bigplanvelo[:,i+1] = bigplanvelo[:,i] + sungrav(bigplanpos[:,i],sunpos[:,i],sm)*dt
        
    return bigplanpos,sunpos,bigplanvelo,sunvelo
         
endloop = time.time()

timearray = np.linspace(0,t,n)
legend = ["Midgard","Aasgard","Vanaheim","Alfheim","Jotunheim","Svartalfheim","Helheim"]
#plt.xkcd()

for i in range(N):
    xpos = planetpos[0,i,:]
    ypos = planetpos[1,i,:]
    plt.plot(xpos,ypos)
    plt.xlabel("Astronomical units")
    plt.ylabel("Astronomical units")

plt.legend(legend)
plt.plot(0,0,"oy")

plt.savefig("Planetbaner.png")
plt.show()


plt.plot(timearray,planetpos[1,0,:])
plt.title("Homeplanet y coord as a function of time")
plt.show()


stop = time.time()

def datasaver(planetpos,timearray,filename):
    outfile = open(filename,"wb")
    np.save(outfile,[planetpos,timearray])
datasaver(planetpos,timearray,"positionFile.npy")

finalstop = time.time()

#MSS.orbit_xml(planetpos,timearray)
#MSS.check_planet_positions(planetpos,10,n/10)
bigplanpos, sunpos, bigplanvelo, sunvelo = inter(bigplanpos,sunpos,bigplanvels0,sunvels0,n,dt)

#plt.plot(timearray,np.linalg.norm(bigplanpos,axis=0))
#print(sunvels0)

plt.plot(bigplanpos[0,:],bigplanpos[1,:])
plt.plot(sunpos[0,:],sunpos[1,:])
plt.title("Plot of sun and planet zero")
plt.legend(["planet","sun"])
plt.xlabel("Astronomical units")
plt.ylabel("Astronomical units")
plt.show()


radvelo = bigplanvelo[0,:]*np.sin(rad)
sigma = np.max(radvelo)/5
noise = np.random.normal(0,sigma,size = n)
radvelo = radvelo + noise
radvelo = radvelo[0::500]
timearray = timearray[0::500]
plt.plot(timearray,radvelo)
plt.title("The radial velocity of planet %g" % p)
plt.xlabel("yr")
plt.ylabel("Au/yr")
plt.show()

def energytest(m1,m2,bigplanpos,sunpos,bigplanvelo,sunvelo):
    prb = asl.Rocket()
    m1 = prb.massconverter(m1)
    m2 = prb.massconverter(m2)
    mu = m1*m2/(m1+m2)
    G = 6.67e-11
    planspeedvec = np.linalg.norm(bigplanvelo,axis = 0)
    sunspeedvec = np.linalg.norm(sunvelo,axis = 0)
    relativespeed = np.abs(sunspeedvec - planspeedvec)
    relapos = np.abs(np.linalg.norm(sunpos - bigplanpos,axis = 0))
    relapos = relapos * 1.496e11
    relativespeed = relativespeed * 4740.57172
    realE = 0.5*mu*relativespeed[0]**2 - G*(m1+m2)*mu/relapos[0]
    lastE = 0.5*mu*relativespeed[-1]**2 - G*(m1+m2)*mu/relapos[-1]
    eps = 1e16
    test = np.abs(realE - lastE) > eps
    print(np.abs(realE - lastE))
    print("E1 = %g" % realE)
    print("E2 = %g" % lastE)
    msg = "test failed, energy was not kept"
    assert test, msg
    
    

#energytest(sm,massvec[p],bigplanpos,sunpos,bigplanvelo,sunvelo)

print(bigplanvels0)
print(vels[:,0])

print(endloop-start1)
print(stop-endloop)
print("saving data took %g seconds" % (finalstop - stop))
