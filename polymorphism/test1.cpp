#include "base.h"
#include "derived.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

  Base b1;
  b1.display();

  Base *p1 = new Base();
  p1->say_hello();
  p1->fun();

  Derived *p2 = new Derived();
  p2->say_hello();
  p2->fun();

  Base *p3 = new Derived();
  p3->say_hello();

  cout << "----0-" << endl;
  Derived d1;
  Base &r1 = d1;
  d1.say_hello(); // calls the derived say hello since it's a virtual function

  cout << "---1--" << endl;
  top *p4 = new Derived();
  p4->fun();
  p4->say_hello();

  delete p1, p2, p3, p4;

  return 0;
}