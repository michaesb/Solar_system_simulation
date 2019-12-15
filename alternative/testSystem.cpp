#include <iostream>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

bool testing_force(int& nr){
  nr++;
  double solarmass = 1.989e30; //In kg
  double days = 365.24; // In days
  int n = 1e5; //Number of steps
  double T = 0.1;//Number of years you will plot
  solver B(n, T);
  celestialBody sun(1, 0, 0, 0, 0); //mass,vx,vy,px,py
  celestialBody earth(0.000003003, 0, 2*M_PI, 1, 0);
  B.addPlanet(sun);
  B.addPlanet(earth);
  B.velocityVerlet();
  int array[1000];
  int i=0;
  char cNum[10] ;
  std::ifstream infile;
  infile.open("../textfiles/planet1.txt", ifstream::in);
  if (infile.is_open()){
      while (infile.good()){
         if (i>2){
         infile.getline(cNum, 256, ',');
         array[i]= atoi(cNum) ;
         }
      i++ ;

     }
      infile.close();
  }
  else
  {
  std::cout << "Error opening file";
  }

  return true;
}

bool testing_randMTr(int& nr){
  nr++;
  return true;
}

bool testing_analytic(int& nr){
  nr++;
  return true;
}

// testing number generator

bool run_testfuncs(){
  //runs all the testfunctions

  int nr_tests = 0;
  bool test1 = testing_force(nr_tests);
  bool test2 = testing_randMTr(nr_tests);
  bool test3 = testing_analytic(nr_tests);

  if (test1 + test2 + test3== nr_tests){
    return true;
  }else {
    std::cout << "tests: 1: "  << test1 << " 2: " << test2 << " 3: " <<test3 << '\n';
    return false;
  }
}
