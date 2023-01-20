#ifndef _DERIVED_H_
#define _DERIVED_H_

#include "Base.h"
#include <iostream>

class Derived : public Base {
  using Base::Base; // lets the special constructors from base class access here
                    // BUT makes them work like the derived class constructor

public:
  int num3;
  int num5;

public:
  Derived();
  Derived(int y, int z);
  Derived(Derived &obj);
  double squared_fun(double &x);
  ~Derived();
};

Derived::Derived() : num3(0) {
  std::cout << "Derived no arg constructor" << std::endl;
}
// This constructor invokes the base 1 arg constructor and assigns num1 as z
Derived::Derived(int y, int z) : Base{y, z}, num3(y), num5(z) {
  std::cout << "Derived 1 arg constructor" << std::endl;
}
Derived::Derived(Derived &obj) : num3(obj.num3), num5(obj.num5), Base(obj) {
  std::cout << "Derived copy constructor" << std::endl;
}
// over-ridden function here
double Derived::squared_fun(double &x) {
  x += 1.0;
  return Base::squared_fun(x);
}
Derived::~Derived() { std::cout << "Derived destructor" << std::endl; }

#endif // _DERIVED_H_