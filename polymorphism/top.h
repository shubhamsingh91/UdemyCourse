#ifndef _TOP_H_
#define _TOP_H_
#include <iostream>
#include <stdio.h>

// abstract class- contains at-least one virtual function OR not an abstract
// class

class top {
public:
  virtual void fun() = 0;       // pure virtual function
  virtual void say_hello() = 0; // pure virtual function
  virtual void bar() {}       //  virtual function

  virtual ~top(){};
};

#endif // _TOP_H_