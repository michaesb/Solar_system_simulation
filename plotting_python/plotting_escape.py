import sys
import numpy as np
import matplotlib.pyplot as plt
from filereader_module.file_reader import FileReader



orbit = FileReader('./textfiles/verlet_planet_orbit.txt')
escape = FileReader('./textfiles/verlet_planet_near_escape.txt')
beyond = FileReader('./textfiles/verlet_planet_escape.txt')

Vx,Vy,Pxo,Pyo = orbit()
Vx,Vy,Pxe,Pye = escape()
Vx,Vy,Pxb,Pyb = beyond()

plt.plot(Pxo,Pyo, "red")
plt.plot(Pxe,Pye, "blue")
plt.plot(Pxb,Pyb, "green")
plt.plot(0,0,"oy")
plt.title("Plotting different orbits of earth around the sun")
plt.legend(["circular orbit velocity = 2*pi","near escape velocity = 1.41*2*pi*0.99","escape velocity = 1.41*2*pi"])
plt.ylabel('y')
plt.xlabel('x')
plt.show()
