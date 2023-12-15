#ifndef _BASE_H_
#define _BASE_H_
#include "top.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Base : public top {

private:
  int num;
  std::string name;

public:
  Base();
  void display() { cout << "displaying base class!" << endl; } //
  void fun(); // dynamically binded since virtual in base abstract class
  void say_hello() {
    cout << "Hello in base!" << endl;
  }; // dynamically binded since virtual in base abstract class

  ~Base(); // virtual destructor
};
Base::Base() {}

void Base::fun() { cout << "fun in Base class!" << endl; }
Base::~Base() { cout << "Base destructor" << endl; }

#endif // _BASE_H_