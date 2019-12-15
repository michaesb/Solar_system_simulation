import sys
import numpy as np
import matplotlib.pyplot as plt
from filereader_module.file_reader import FileReader
import seaborn


obj = FileReader('textfiles/verlet_planet.txt')
Vx,Vy,Px,Py = obj()
#print('y_analytical',y_actual); print('y_model',y_model)
# plt.plot(Px,Py)
plt.plot(Px,Py)

plt.title('Verlet with a circular orbit. dt = '+str(1./len(Vx)))

plt.ylabel('y')
plt.xlabel('x')
plt.axis("equal")
plt.show()

"""
A script that read from textfile the values and plots the analytic solution
and the numerical model. run by a run_script
"""
