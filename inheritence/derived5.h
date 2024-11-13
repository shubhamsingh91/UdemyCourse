#ifndef _DERIVED5_H_
#define _DERIVED5_H_
#include <iostream>
#include <stdio.h>
#include "base5.h"
using namespace std;

class derived5: public base5{

 public:
    int num3;
   int num2;

 public:
  derived5(){cout << "derived5 const" << endl;};
  derived5(int n): num3{n}{ cout << "derived5 single arg const" << endl;};
  
  derived5(int m, int n):base5{m},num3{n}{};

  virtual inline void print_nums(){ // dynamically bound now
    this->base5::print_nums();
    cout << "print_nums in derived5" << endl;
    std::cout << "num3 = " << num3 << std::endl;
  }

  virtual int print_num3(){return num3;};

   ~derived5(){};


};














#endif