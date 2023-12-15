#ifndef _base_H_
#define _base_H_

#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T> class base {

private:
  T num1;

public:
  base() {}
  base(T z) : num1{z} {}
  T get_num1() { return num1; }
  ~base() {}
};

#endif