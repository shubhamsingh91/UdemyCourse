#ifndef _BASE1_H_
#define _BASE1_H_
#include <iostream>
#include <string>

// header for base class

class base1 {

protected:
  int m_value {};   

public:
  base1(int value): m_value{value}{std::cout << "Base1 constr"<< std::endl;};                        // constructor-1
  virtual ~base1()=default;                       // destructor

void print() const {std::cout << "Base: " << m_value << std::endl;}
 
};

#endif // _BASE1_H_