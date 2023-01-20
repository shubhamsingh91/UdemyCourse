#include "Base.h"
#include "Derived.h"
#include <iostream>
#include <stdio.h>
using namespace std;

// testing copy and move constructors for base, derived classes

int main() {

  Base b1(3, 4);
  Base b2(b1);
  double n1 = 12.0;
  double n2 = 12.0;
  double n3 = 4.0;

  cout << "num1 for b2 = " << b2.get_num() << endl;
  cout << "num2 for b2 = " << b2.get_num2() << endl;
  cout << "double of n1 = " << b2.squared_fun(n1) << endl;
  cout << "----------- d1----------------------" << endl;

  Derived d1(12, 15);
  cout << "double of n2 = " << d1.squared_fun(n2) << endl;

  cout << "----------- d2----------------------" << endl;

  Derived d2(d1);
  cout << "num3 for d2 = " << d2.num3 << endl;
  cout << "num1 for d2 = " << d2.get_num() << endl;
  cout << "num2 for d2 = " << d2.get_num2() << endl;

  cout << "----------- static binding example-----" << endl;

  Base *p = new Derived();
  cout << "squared of n3 = " << p->squared_fun(n3)
       << endl; // calls the squared_fun of base class- not derived class-
                // static binding

  return 0;
}