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
  virtual void display(); // dynamically binded now due to the virtual keyword
  virtual void fun() override;
  virtual void
  say_hello() override; // dynamically binded now due to the virtual keyword

  virtual ~Base(); // virtual destructor
};
Base::Base() {}

void Base::display() { cout << "displaying base class!" << endl; }
void Base::say_hello() { cout << "Hello in base!" << endl; }
void Base::fun() { cout << "fun in Base class!" << endl; }
Base::~Base() { cout << "Base destructor" << endl; }

#endif // _BASE_H_