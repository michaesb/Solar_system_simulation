import numpy as np
import matplotlib.pyplot as plt
from filereader_module.file_reader import FileReader


obj = FileReader("../textfiles/mean_values_beta=1.txt")
obj2 = FileReader("../textfiles/calc_values_beta=1.txt")

a, b, c = obj()
MCs, Cvs, chis = obj2()

MCs = a
mean_Es = c
mean_Ms = b


plt.plot(np.log10(MCs), mean_Ms/3.995, "-o")
plt.plot(np.log10(MCs), mean_Es/(-7.984), "-o")
plt.xlabel("log10(MC)")
plt.ylabel("Normalized observables")
plt.title("evolution of observables <E> and <$\mathcal{M}$> as MC increases")
plt.legend(["<$\mathcal{M}$>","<E>"])
plt.savefig("../figures/figure1.pdf")
plt.show()

plt.plot(np.log10(MCs), Cvs/0.128, "-o")
plt.plot(np.log10(MCs), chis/0.016, "-o")
plt.title("evolution of observables C$_V$ and $\chi$ as MC increases")
plt.legend(["C$_V$", "$\chi$"])
plt.xlabel("log10(MC)")
plt.ylabel("Normalized observables")
plt.savefig("../figures/figure2.pdf")
plt.show()
