import matplotlib.pyplot as plt
import numpy as np
from filereader_module.csv_reader import csv_reader

def momentum(m, vx, vy, px, py):
    """
    Finds angular momentum
    """
    xmom = vx*m
    ymom = vy*m
    return xmom, ymom



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
    # days = 365.24
    # solarmass = 1.989e30
    #
    # earthx, earthy =  momentum(0.000003003, -1.602723439211851e-02*days, 6.882264719474028e-03*days, 3.983744251977597e-01, 9.025161878539018e-01)
    # jupiterx, jupitery =  momentum(0.0009543, days*7.452252471233350e-03, days*7.603499279291407e-04, 2.806426180901584e-01, -5.232008081884607)
    # mercuryx, mercuryy = momentum(3.3e23/solarmass, -1.927416352956285e-02*days, -2.350148494621872e-02*days, -3.053920471115882e-01, 1.669887871076899e-01)
    # marsx, marsy =  momentum(6.4171e23/solarmass, 4.935409489817506e-03*days, -1.208287844100836e-02*days, -1.539687230099815, -5.117081813732122e-01)
    # venusx, venusy = momentum(48.685e23/solarmass, 1.494114742824526e-02*days, 1.341363073826836e-02*days, 4.849822091423722e-01, -5.420468872336146e-01)
    # saturnx, saturny = momentum(5.6834e26/solarmass, 4.899996437554958e-03*days, 2.006400834137427e-03*days, 3.636150583043191, -9.355788660474625)
    # uranusx, uranusy = momentum(86.813e24/solarmass, -2.259745292235776e-03*days, 3.051765014003087e-03*days, 1.630040575228520e1, 1.127855557318932e1)
    # neptunex, neptuney = momentum(102.413e24/solarmass, 6.652990225832408e-04*days, 3.085677390122435e-03*days, 2.922102933897389e1, -6.469052215342025)
    # plutox, plutoy = momentum(1.307e22/solarmass, 2.973503675535460e-03*days, 5.186275321374038e-04*days, 1.287831056516992e1, -3.138764791245833e1)
    #
    # totalmomx = earthx + jupiterx + mercuryx + marsx + venusx + saturnx + uranusx + neptunex + plutox
    # totalmomy = earthy + jupitery + mercuryy + marsy + venusy + saturny + uranusy + neptuney + plutoy
    # print(totalmomx, totalmomy)



    nbody_plotter(3, path = "textfiles/")
