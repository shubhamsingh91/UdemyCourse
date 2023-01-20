#ifndef _DERIVED_H_
#define _DERIVED_H_

#include "base.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Derived : public Base {

private:
public:
  Derived();
  virtual void display(); // dont need virtual keyword in the derived account,
  // but good practice, ONLY virtual here wont do
  // dynamic binding- NEED it in base
  virtual void say_hello(); // no const here, re-definition and statically bound
  virtual void fun();
  virtual ~Derived();
};

Derived::Derived() {}
void Derived::display() { cout << "displaying Derived class!" << endl; }
void Derived::say_hello() { cout << "Hello in Derived!" << endl; }
void Derived::fun() { cout << "fun in Derived class!" << endl; }
Derived::~Derived() { cout << "Derived destructor" << endl; }

#endif // _DERIVED_H_