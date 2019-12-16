import matplotlib.pyplot as plt
import numpy as np
from filereader_module.csv_reader import csv_reader

def nbody_plotter(n, path = "textfiles/"):
    """
    reads planetary position data from textfiles
    and plots positions of n celestial bodies.
    """


    filenames = []
    for i in range(n):
        filenames.append(path + "planet" + str(i) + ".txt")

    datas = []
    for filename in filenames:
        datas.append(csv_reader(filename))


    plt.plot(datas[0][-2], datas[0][-1],"oy")
    plt.plot(datas[1][-2], datas[1][-1])
    plt.plot(datas[2][-2], datas[2][-1],)
    plt.xlabel("Distance [AU]")
    plt.ylabel("Distance [AU]")
    plt.title("Planetary orbits for %g bodies" % n)
    plt.legend(["sun","earth","jupyter"])
    plt.axis("equal")
    plt.show()

if __name__ == "__main__":
    nbody_plotter(3, path = "textfiles/")
