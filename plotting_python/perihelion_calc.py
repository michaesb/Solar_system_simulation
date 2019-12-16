import numpy as np
import matplotlib.pyplot as plt
from filereader_module.csv_reader import csv_reader as csv
from scipy.interpolate import interp1d

def perihelion_angle(data):
    """
    Finds the angle of mercury at perihelion.
    """


    T = 100
    n = len(data[0])
    dt = T/n
    T0 = 0.2411
    n0 = int(T0/dt)

    #define data arrays
    xpos = data[-2]; ypos = data[-1]
    times = np.arange(len(xpos))*dt
    distance = np.sqrt(xpos**2 + ypos**2)



    #cut data arrays
    xpos = xpos[-n0:]; ypos = ypos[-n0:]
    times = times[-n0:]
    distance = distance[-n0:]

    #interpolate
    xfunc = interp1d(times, xpos, "cubic")
    yfunc = interp1d(times, ypos, "cubic")

    #use interpolation
    int_time = np.linspace(times[0], times[-1], 10000)
    int_x = xfunc(int_time)
    int_y = yfunc(int_time)
    int_dist = np.sqrt(int_x**2 + int_y**2)

    #find perihelion
    int_index = np.where(int_dist == np.min(int_dist))
    int_xval = int_x[int_index]
    int_yval = int_y[int_index]

    index = np.where(distance == np.min(distance))
    x = xpos[index]
    y = ypos[index]


    #plot data
    plt.plot(xpos, ypos)
    plt.plot(int_x, int_y)
    plt.plot(int_xval, int_yval, "o")
    plt.plot(0, 0, "yo")
    plt.show()



    angle = np.arctan(int_yval/int_xval)
    angle = angle*360/2/np.pi
    return(angle)


def perihelion_comparison():
    """
    Finds and compares perihelion processions
    """

    data1 = csv("../textfiles/mercury_rel_1e7.txt")
    data2 = csv("../textfiles/mercury_norel_1e6.txt")

    angle1 = perihelion_angle(data1)
    angle2 = perihelion_angle(data2)

    print(angle1*3600)
    print(angle2*3600)









if __name__ == "__main__":
    perihelion_comparison()
