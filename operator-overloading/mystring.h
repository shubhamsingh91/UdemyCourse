#ifndef _mystring_H_
#define _mystring_H_
#include <iostream>
#include <stdio.h>
using namespace std;

// mystring class

class Mystring {
private:
  char *str;

public:
  Mystring();
  Mystring(const char *s);
  Mystring(const Mystring &source);
  Mystring &operator=(const Mystring &rhs); // copy assignment
  Mystring &operator+(const Mystring &rhs); // not working
  Mystring &operator=(Mystring &&rhs);      // move assignment

  ~Mystring();
  void display() const;
  int get_length() const;
  const char *get_str() const;
};

#endif