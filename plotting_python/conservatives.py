import sys
import numpy as np
import matplotlib.pyplot as plt
from filereader_module.file_reader import FileReader


def energy(vx, vy, px, py):
    """
    Total mechanical energy
    """
    R = np.sqrt(px**2 + py**2)
    v = np.sqrt(vx**2 + vy**2)
    ep = 1/R
    ek = 1/2*v**2
    return(ep+ek)


obj = FileReader('../textfiles/verlet_planet.txt')
Vx,Vy,Px,Py = obj()


energies = np.zeros_like(Vx)

for i in range(len(Vx)):
    energies[i] = energy(Vx[i], Vy[i], Px[i], Py[i])

times = np.linspace(0, 100, len(Vx))

plt.plot(times, energies)
plt.show()
