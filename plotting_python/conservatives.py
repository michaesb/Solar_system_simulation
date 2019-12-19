import sys
import numpy as np
import matplotlib.pyplot as plt
from filereader_module.file_reader import FileReader

m_earth = 0.000003003 #solmasses

def energy(vx, vy, px, py):
    """
    Total mechanical energy
    """
    R = np.sqrt(px**2 + py**2)
    v = np.sqrt(vx**2 + vy**2)
    ep = m_earth*4*np.pi/R
    ek = 1./2*m_earth*v**2
    return(ep+ek)

def momentum(vx, vy, px, py):
    """
    Momentum vector size
    """
    return np.abs(m_earth*(px*vy - py*vx))


obj = FileReader('./textfiles/verlet_planet.txt')
Vx,Vy,Px,Py = obj()

def plot_energy():
    energies = np.zeros_like(Vx)

    for i in range(len(Vx)):
        energies[i] = energy(Vx[i], Vy[i], Px[i], Py[i])

    times = np.linspace(0, 100, len(Vx))
    # plt.xkcd()

    plt.plot(times, energies)
    plt.title("Mechanical energy of Verlet for 100 years", size=24)
    plt.xlabel("time [years]", size =20)
    plt.ylabel("Total Mechanical Energy [$M_O$ AU$^2$ Yr$^-2$] ", size =20)
    plt.show()

def plot_momentum():
    momentums = momentum(Vx, Vy, Px, Py)
    times = np.linspace(0, 100, len(Vx))

    plt.plot(times, momentums)
    plt.xlabel("Time [years]", size =20)
    plt.ylabel("Momentum [M$_O$ AU$^2$ years$^{-1}$]",size = 20)
    plt.title("Momentum of earth using Verlet for 100 years", size=24)
    plt.show()

plot_energy()
plot_momentum()
