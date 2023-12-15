#ifndef _BASE1_H_
#define _BASE1_H_
#include "top.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Base1 : public top { // concrete class from Base1 class

private:
  int num;
  std::string name;

public:
  Base1();
  virtual void fun() override { cout << "fun in Base1 class!" << endl; }
  virtual void say_hello()  {
    cout << "Hello in base1!" << endl;
  }; // dynamically binded since virtual in base abstract class

  ~Base1(); // virtual destructor
};
Base1::Base1() {}

Base1::~Base1() { cout << "Base destructor" << endl; }

#endif // _BASE1_H_