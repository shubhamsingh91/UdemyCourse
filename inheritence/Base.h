#ifndef _BASE_H_
#define _BASE_H_
#include <iostream>
#include <string>

// header for base class

class Base {

  // private
public:
  int num2;
  int num1;
  std::string name;

 protected:
    int num3;

 private:
    int num4;   

public:
  Base();                        // constructor-1
  Base(int z);                   // constructor-2
  Base(int y, int z);            // constructor-3
  Base(int y, int z, std::string name);            // constructor-4
  //Base(const Base &obj);         // copy constructor
  double squared_fun(double &x); // returns the square of a double
  ~Base();                       // destructor

  // setter
  void set_num(int z);
  // getter
  int get_num();
  std::string get_name();
  int get_num2();
};

Base::Base() : num1(0), num2(0), name("No-Name") {
  std::cout << "Base no arg constructor" << std::endl;
}

Base::Base(int z) : num1(z), num2(0), name("No-Name") {
  std::cout << "Base 1 arg constructor" << std::endl;
}

Base::Base(int y, int z) : num1(y), num2(z), name("No-Name") {
  std::cout << "Base 2 arg constructor" << std::endl;
}

Base::Base(int y, int z, std::string name) : num1(y), num2(z), name(name) {
  std::cout << "Base 3 arg constructor" << std::endl;
}

// Base::Base(const Base &obj) : num2{obj.num2}, num1{obj.num1}, name{obj.name} {
//   std::cout << "Base copy constructor" << std::endl;
// }

void Base::set_num(int z) { num1 = z; }

int Base::get_num() { return num1; }

int Base::get_num2() { return num2; }

std::string Base::get_name() { return name; }

double Base::squared_fun(double &x) { return x * x; }

Base::~Base() { std::cout << "Base destructor" << std::endl; }
#endif // _BASE_H_