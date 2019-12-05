import numpy as np
import matplotlib.pyplot as plt
from filereader_module.file_reader import FileReader
import sys

obj = FileReader("../textfiles/magnetization_random_T=2_4.txt")
obj2 = FileReader("../textfiles/energy_random_T=2_4.txt")
obj3 = FileReader("../textfiles/accepted_cycles_random_T=2_4.txt")
MCs, mean_Ms, = obj()
mean_Es = obj2()[1]
accepted = obj3()[1]

plt.plot(MCs, mean_Es, "-o")
plt.xlabel("Mc")
plt.ylabel("<E>")
plt.grid("on")
plt.title("Evolution of mean energy as MC increases")
# plt.savefig("../figures/L=20_EnergyT=1.pdf")
plt.show()

plt.plot(MCs, mean_Ms, "-o")
plt.xlabel("Mc")
plt.ylabel("<$\mathcal{M}$>")
plt.title("Evolution of mean absolute magnetic moment as MC increases")
# plt.savefig("../figures/L=20_magnetT=1")
plt.show()

plt.plot(MCs, accepted, "-o")
plt.xlabel("Mc")
plt.ylabel("<$\mathcal{accepted}$>")
plt.title("Evolution of number of accepted transistions as MC increases")
# plt.savefig("../figures/L=20_magnetT=1")
plt.show()


plt.plot(np.log10(MCs), mean_Ms, "-o")
plt.plot(np.log10(MCs), mean_Es, "-o")
plt.xlabel("log10(MC)")
plt.ylabel("Normalized observables")
plt.title("evolution of observables <E>, <$\mathcal{M}$> and # of accepted as MC increases")
plt.legend(["<$\mathcal{M}$>","<E>", "<accepted>"])
#plt.savefig("../figures/L=20_E_M_T=1")
plt.show()
