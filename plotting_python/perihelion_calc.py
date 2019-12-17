import numpy as np
import matplotlib.pyplot as plt
from filereader_module.csv_reader import csv_reader as csv
from scipy.interpolate import interp1d

def perihelion_angle(data):
    """
    Finds the angle of mercury at perihelion.
    """


    T = 5
    n = len(data[0])
    dt = T/n
    T0 = 0.2411
    n0 = int(T0/dt)

    #define data arrays
    xpos = data[-2]; ypos = data[-1]
    times = np.arange(len(xpos))*dt
    distance = np.sqrt(xpos**2 + ypos**2)

    timebins = []
    xposbins = []
    yposbins = []
    distancebins = []

    binNr = int(T/T0)
    for i in range(binNr):
        timebins.append(times[n0*i:n0*(i+1)])
        xposbins.append(xpos[n0*i:n0*(i+1)])
        yposbins.append(ypos[n0*i:n0*(i+1)])
        distancebins.append(distance[n0*i:n0*(i+1)])

    indices = []
    x_possies = []
    y_possies = []
    t_possies = []
    for i in range(binNr):
        indices.append(np.where(distancebins[i] == np.min(distancebins[i])))
        x_possies.append(float(xposbins[i][indices[i]]))
        y_possies.append(float(yposbins[i][indices[i]]))
        t_possies.append(float(timebins[i][indices[i]]))

    t_possies = np.asarray(t_possies)
    x_possies = np.asarray(x_possies)
    y_possies = np.asarray(y_possies)

    angles = np.rad2deg(np.arctan2(y_possies, x_possies))

    #angle = np.polyfit(t_possies, angles, deg = 1)[0]

    countr1 = 0
    countr2 = 0

    positiveSum = 0
    negativeSum = 0

    for i in range(len(angles)):
        if angles[i]>0:
            countr1 += 1
            positiveSum += angles[i]
        elif angles[i]<0:
            countr2 += 1
            negativeSum += angles[i]

    angle = (positiveSum/countr1 + negativeSum/countr2)/2*3600



    plt.plot(t_possies+95, angles*3600)
    plt.title("mean precession = %g arceconds" % angle)
    plt.ylabel("precession angle [arcseconds] ")
    plt.xlabel("Time since simulation start [years]")
    plt.show()



    return angle



def perihelion_comparison():
    """
    Finds and compares perihelion processions
    """

    data1 = csv("../textfiles/mercury_lastyear_1e8_norel.txt")
    data2 = csv("../textfiles/mercury_lastyear_1e8_rel.txt")

    angle1 = perihelion_angle(data1)
    angle2 = perihelion_angle(data2)

    print("non-relativistic")
    print(angle1)
    print("relativistic")
    print(angle2)









if __name__ == "__main__":
    perihelion_comparison()
