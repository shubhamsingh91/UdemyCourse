#include "mystring.cpp"
#include <iostream>
//#include <stdio.h>

using namespace std;

int main() {

  char c1 = 'B';
  char *p1 = new char[2]; // pointer to a character
  char *p2 = &c1;         //& is used to get the address of something
  p1[0] = 'f';
  p1[1] = 'g';

  cout << "p1 strlen =" << std::strlen(p1) << endl;
  // cout << "c1 strlen =" << std::strlen(c1) << endl; // strlen works on
  // pointer to a character

  cout << "c1 = " << c1 << endl;
  cout << "p1 = " << p1[0] << endl;
  cout << "p1 = " << &p1 << endl; // address of p1
  cout << "p2= " << &p2 << endl;  // address of p2

  cout << "---------0------" << endl;

  Mystring s1("hello");
  Mystring s2(s1);
  s1.display();
  s2.display();
  const char *p3 = s2.get_str();
  cout << "p3 = " << p3 << endl;

  cout << "---------2------" << endl;
  Mystring s3, s4;
  s3 = s2; // shallow copy- default assignment(memberwise copy)
  s3.display();
  s4 = s2;

  cout << "---------3------" << endl;

  //   Mystring s5(" World!");
  //   s1.display();
  //   s5.display();

  //   s1 = s1 + s5;
  //   s1.display();

  cout << "---------4------" << endl;

  Mystring s5 = "Hello ";
  s5 = "world"; // uses copy assignment by default- but is a r-value reference

  cout << "---------5 -----" << endl;

  cout << "---------6 ------" << endl;

  return 0;
}
