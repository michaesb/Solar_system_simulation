import sys
import numpy as np
import matplotlib.pyplot as plt
from filereader_module.file_reader import FileReader
import seaborn


obj = FileReader('textfiles/euler_planet.txt')
Vx,Vy,Px,Py = obj()
#print('y_analytical',y_actual); print('y_model',y_model)
# plt.plot(Px,Py)
plt.plot(Px,Py)
plt.title('Euler with a circular orbit. dt = '+str(1./len(Vx)))
plt.axis("equal")
plt.ylabel('y')
plt.xlabel('x')
plt.show()
