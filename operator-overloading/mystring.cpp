#include "mystring.h"
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;

Mystring::Mystring() : str{nullptr} {
  str = new char[1];
  str[0] = '\0'; // this is same as *str
}

Mystring::Mystring(const char *s) : str{nullptr} {
  if (s == nullptr) {
    str = new char[1];
    str[0] = '\0';
  } else {
    str = new char[std::strlen(s) + 1];
    std::strcpy(str, s);
  }
}
Mystring::Mystring(const Mystring &source) : str{nullptr} {
  if (source.str == nullptr) {
    str = new char[1];
    str[0] = '\0';
  } else {
    str = new char[std::strlen(source.str) + 1];
    str = source.str;
  }
}

void Mystring::display() const {
  std::cout << str << ":" << get_length() << std::endl;
}

Mystring &Mystring::operator=(const Mystring &rhs) {
  cout << "copy assignment" << endl;
  if (this == &rhs) // this is a pointer to the local class object
    return *this;   // returns the 'value' of this

  delete[] this->str;
  str = new char[std::strlen(rhs.str) + 1];
  std::strcpy(str, rhs.str);
  return *this;
}

Mystring &Mystring::opeartor = (Mystring && rhs) {
  cout << "move assignment" << endl;
  if (this == &rhs) // this is a pointer to the local class object
    return *this;   // returns the 'value' of this

  str = rhs.str;
}

// buggy- NOT WORKING- need to be fixed
Mystring &Mystring::operator+(const Mystring &rhs) {
  if (rhs.str == nullptr) // if adding nothing
    return *this;

  Mystring *temp = new Mystring();
  temp = this;

  delete[] this->str;
  int l1 = this->get_length();
  int l2 = rhs.get_length();
  cout << "l1 = " << l1 << endl;
  cout << "l2 = " << l2 << endl;

  str = new char[l1 + l2 + 1];
  for (int ii = 0; ii < l1 + l2; ii++) {
    if (ii <= l1) {
      str[ii] = temp->str[ii];
    } else {
      str[ii] = rhs.str[ii];
    }
  }

  return *this;
}

int Mystring::get_length() const { return std::strlen(str); }

const char *Mystring::get_str() const { return str; };

Mystring::~Mystring() {}