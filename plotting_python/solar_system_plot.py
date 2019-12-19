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

    for i in range(len(datas)):
        plt.plot(datas[i][-2], datas[i][-1])
    plt.xlabel("Distance [AU]")
    plt.ylabel("Distance [AU]")
    plt.title("Planetary orbits for all the planets + the sun", size=24 )
    plt.legend(["Sun","Earth", "Jupiter", "mercury","mars", "Venus","Saturn",\
                "uranus", "Neptune", "Pluto"], prop={'size': 20})
    plt.show()

if __name__ == "__main__":
    nbody_plotter(10, path = "textfiles/")
