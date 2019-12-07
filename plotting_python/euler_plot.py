import sys
import numpy as np
import matplotlib.pyplot as plt
from filereader_module.file_reader import FileReader



obj = FileReader('textfiles/euler_planet.txt')
Vx,Vy,Px,Py = obj()
#print('y_analytical',y_actual); print('y_model',y_model)
# plt.plot(Px,Py)
plt.plot(Px,Py)

plt.title('Euler. n = '+str(len(Vx)))
plt.ylabel('y')
plt.xlabel('x')
plt.show()
