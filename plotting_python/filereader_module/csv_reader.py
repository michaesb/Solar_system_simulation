import numpy as np
import matplotlib.pyplot as plt

def csv_reader(filename):
    """
    Reads a csv file and returns information in array form.
    """
    infile = open(filename)

    commacounter = 0
    for line in infile:
        for character in line:
            if character == ",":
                commacounter += 1
        break

    data_array = []
    for i in range(commacounter + 1):
        data_array.append([])

    counter = 0

    for line in infile:
        if counter != 0:
            line = line.rstrip()
            data_list = line.split(",")
            for i in range(len(data_list)):
                data_array[i].append(float(data_list[i]))
        else:
            pass
        counter += 1

    data_array = np.array(data_array)
    return data_array


if __name__ == "__main__":
    filename = "../../textfiles/planet0.txt"
    data_array = csv_reader(filename)
