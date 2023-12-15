#ifndef _DERIVED1_H_
#define _DERIVED1_H_

#include "base1.h"
#include <iostream>
#include <string_view>
#include <string>

class derived1 : public base1 {
protected:
  std::string m_name {}; 

public:
  derived1(int value,std::string_view name):base1{value},m_name{name}{std::cout << "Derived const" << std::endl;};
  
  const std::string& getName() const {return m_name;}

  ~derived1(){std::cout << "Derived destructor" << std::endl;};
};

#endif // _DERIVED1_H_