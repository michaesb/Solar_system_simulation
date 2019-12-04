#include <iostream>
#include <stdio.h>
#include <cmath>

bool testing_spin(int& nr){
  nr++;
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
  bool test1 = testing_spin(nr_tests);
  bool test2 = testing_randMTr(nr_tests);
  bool test3 = testing_analytic(nr_tests);

  if (test1 + test2 + test3== nr_tests){
    return true;
  }else {
    std::cout << "tests: 1: "  << test1 << " 2: " << test2 << " 3: " <<test3 << '\n';
    return false;
  }
}
