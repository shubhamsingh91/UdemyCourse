#ifndef _DERIVED_H_
#define _DERIVED_H_

#include "base.h"
#include <iostream>

class derived : public base {
  //using Base::Base; // lets the special constructors from base class access here
                    // BUT makes them work like the derived class constructor

public:
  derived(int y):base{y}{std::cout << "Derived const" << std::endl;};
  ~derived(){std::cout << "Derived destructor" << std::endl;};
};

#endif // _DERIVED_H_