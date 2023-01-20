#ifndef _TOP_H_
#define _TOP_H_
#include <iostream>
#include <stdio.h>

// abstract class

class top {
public:
  virtual void fun() = 0;       // virtual fnction
  virtual void say_hello() = 0; // virtual fnction

  virtual ~top(){};
};

#endif // _TOP_H_