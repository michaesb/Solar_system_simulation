import sys
import numpy as np
import matplotlib.pyplot as plt
from filereader_module.file_reader import FileReader



obj = FileReader('textfiles/euler_planet.txt')
Vx,Vy,Px,Py = obj()
#print('y_analytical',y_actual); print('y_model',y_model)
# plt.plot(Px,Py)
plt.plot(Vx,Vy)

# plt.title('the actual values for u vs our model for u n =' +str(n))
# plt.legend(['analytical', 'model'])
plt.ylabel('y')
plt.xlabel('x')
plt.show()

"""
A script that read from textfile the values and plots the analytic solution
and the numerical model. run by a run_script
"""
