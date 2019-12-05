#!/usr/bin/env python
import numpy as np

class FileReader:
    def __init__(self,textfile):
        self.textfile =textfile

    def __call__(self):
        with open(self.textfile, 'r') as values:
            #reading the first line and getting info about the structure of the textfile
            first_line = values.readline()
            #print(first_line)
            info = first_line.split()
            length = int(info[0]) #checks the length of the arrays
            nr_lines = int(info[1]) #checks the number of arrays
            format = info[2] #checks the format of the textfile
            table_array = np.zeros((nr_lines,length))
            if format == "colon2":
                for line, i in zip(values,range(nr_lines)):
                    if line[0] !='#':
                        #print('line', line)
                        list = line.split(':')
                        #print('list', list)
                        array = np.array([float(j) for j in list])
                        table_array[i,:] = array
                        #print('table_array', table_array)
        return table_array
