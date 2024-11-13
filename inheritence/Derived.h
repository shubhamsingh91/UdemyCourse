#ifndef _DERIVED_H_
#define _DERIVED_H_

#include "Base.h"
#include <iostream>

class Derived : public Base {
  // using Base::Base; // lets the special constructors from base class access here
                    // BUT makes them work like the derived class constructor

public:
  int num3;
  int num5;

public:
  Derived();
  Derived(int y, int z);
  Derived(Derived &obj);
  Derived(int x, int y, int z, int u, int p, int q, const std::string &name);
  double squared_fun(double &x);
  void get_derived_nums(){
    print("num1 = ", num1);
    print("num2 = ", num2);
    print("num3 base = ", Base::num3);
    print("num3 der = ", num3);
    print("num5 der =", num5);
  }
  ~Derived();
};

Derived::Derived() : num3(0), num5{0} {
  std::cout << "Derived no arg constructor" << std::endl;
}
// This constructor invokes the base 1 arg constructor and assigns num1 as z
Derived::Derived(int y, int z) : Base{y, z}, num3(y), num5(z) {
  std::cout << "Derived 2 arg constructor" << std::endl;
}
Derived::Derived(Derived &obj) : num3(obj.num3), num5(obj.num5), Base(obj) {
  std::cout << "Derived copy constructor" << std::endl;
}

Derived::Derived(int x, int y, int z, int u, int p, int q, const std::string &name):
    Base{x,y,z,u,name}, num3{p}, num5{q}{
      print("full base and derived arg constructor!");
    }


// over-ridden function here
double Derived::squared_fun(double &x) {
  x += 1.0;
  return Base::squared_fun(x);
}
Derived::~Derived(){}

#endif // _DERIVED_H_