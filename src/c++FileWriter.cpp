#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iostream>
#include <armadillo>
#include <vector>

using namespace std;


void write_to_file_vector(std::vector<double> a, std::vector<double> b,
	 												std::vector<double> c, std::vector<double> d,
	 														 int length, string textfile){
		//writes two arrays to a textdocument, with variable such as number of points
		//number of arrays and the format it is in.
		string path = "../textfiles/"+textfile+".txt" ;
		std::ofstream file(path);
		file << length << " "<< 4 << " " << "colon2"; //setting the length of the array, number of array
		file << "\n"; 						  // and the format
		for (int j=0; j<length; j++){
				file << a[j];
				if (length-1 != j){
						file << ':';
				}
		}
		file << "\n";
		for (int j=0; j<length; j++){
				file << b[j];
				if (length-1 != j){
						file << ':';
				}
		}
		file << "\n"; 						  // and the format
		for (int j=0; j<length; j++){
				file << c[j];
				if (length-1 != j){
						file << ':';
				}
		}
		file << "\n"; 						  // and the format
		for (int j=0; j<length; j++){
				file << d[j];
				if (length-1 != j){
						file << ':';
				}
		}

}



void write_to_file_comparing_y(double y_actual[], double y_model[],
	 														 int length, string textfile){
		//writes two arrays to a textdocument, with variable such as number of points
		//number of arrays and the format it is in.
		string path = "../textfiles/"+textfile+".txt" ;
		std::ofstream file(path);
		file << length << " "<< 2 << " " << "colon2"; //setting the length of the array, number of array
		file << "\n"; 						  // and the format
		for (int j=0; j<length; j++){
				file << y_actual[j];
				if (length-1 != j){
						file << ':';
				}
		}
		file << "\n";
		for (int j=0; j<length; j++){
				file << y_model[j];
				if (length-1 != j){
						file << ':';
				}
		}
}

void write_to_file_columns(double data_1[], double data_2[], double data_3[], int length, string textfile){
	string path = "../textfiles/"+textfile+".txt";
	std::ofstream file(path);
	file << length << " "<< 3 << " " << "colon2"; //setting the length of the array, number of array
	file << "\n";
	for (int j=0; j<length; j++){
			file << data_1[j];
			if (length-1 != j){
					file << ':';
			}
	}
	file << "\n";
	for (int j=0; j<length; j++){
			file << data_2[j];
			if (length-1 != j){
					file << ':';
			}
	}
	file << "\n";
	for (int j=0; j<length; j++){
			file << data_3[j];
			if (length-1 != j){
					file << ':';
			}
	}
	file.close();
}

void write_to_file_error_time(double log_error[],  double h[],
												  double time[], double n[],
											 		int length, int m, string textfile){
	 //writes two arrays to a textdocument, with variable such as number of points
	 //number of arrays and the format it is in.
   string path = "../textfiles/"+textfile+".txt";
	 std::ofstream file(path);
   file << length << " "<< m << " " << "colon2"; //setting the length of the array, number of array
	 file << "\n"; 						  // and the format
	 for (int j=0; j<length; j++){
	 		file << log_error[j];
			if (length-1 != j){
					file << ':';
			}
	 }
	 file << "\n";
	 for (int j=0; j<length; j++){
		 	file << h[j];
		  if (length-1 != j){
					file << ':';
			}
	 }
	 file << "\n";
	 for (int j=0; j<length; j++){
		 	file << time[j];
		  if (length-1 != j){
					file << ':';
			}
	 }

	 file << "\n";
	 for (int j=0; j<length; j++){
		 	file << n[j];
		  if (length-1 != j){
					file << ':';
			}
	 }

}
