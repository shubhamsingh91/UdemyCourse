#ifndef _BASE_H_
#define _BASE_H_
#include <iostream>
#include <string>

// header for base class

class base {

  // private
private:
  int m_x {};   

public:
  base(int x): m_x{x}{std::cout << "Base const"<< std::endl;};                        // constructor-1
  ~base(){std::cout << "base dest" << std::endl;};                       // destructor

void print() const {std::cout << "Base: " << m_x << std::endl;}
 
};

#endif // _BASE_H_