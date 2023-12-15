#include "base.h"
#include "base1.h"
#include "derived.h"
#include "top.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

  Base b1;
  b1.display();
  b1.say_hello();

  cout << "----0---" << endl;

  Base *p1 = new Derived(); // is technically a derived object, not base, this 
  p1->say_hello();
  p1->fun();

  cout << "----1---" << endl;

  Derived *p2 = new Derived();
  p2->say_hello();
  p2->fun();

  cout << "----2---" << endl;

  top *p3 = new Base(); // using top abstract class to create a base class
  p3->say_hello();
  p3->fun();

  cout << "----3---" << endl;

  top *p4 = new Derived();
  p4->say_hello();
  p4->fun();
  cout << "----4---" << endl;

  top *p5 = new Base1();
  p5->fun();
  cout << "----5---" << endl;

  std::vector<top *> tops{p1, p2, p3, p4, p5};
  for (const auto p : tops)
    p->fun();
  cout << "----6---" << endl;

  // Base *p3 = new Derived();
  // p3->say_hello();

  // cout << "----0-" << endl;
  // Derived d1;
  // Base &r1 = d1;
  // d1.say_hello(); // calls the derived say hello since it's a virtual
  // function

  // cout << "---1--" << endl;
  // top *p4 = new Derived();
  // p4->fun();
  // p4->say_hello();

  // delete p1, p2, p3, p4;

  return 0;
}