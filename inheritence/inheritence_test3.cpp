#include "Base.h"
#include "Derived.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

  Base b1;
  b1.set_num(45);
  cout << "num1 for b1 = " << b1.get_num() << endl;

  Base b2(23);
  cout << "num1 for b2 = " << b2.get_num() << endl;

  Base b3(b2);
  cout << "num1 for b3 = " << b3.get_num() << endl;
  cout << "name for b3 = " << b3.get_name() << endl;

  // changing the b2 num1
  b2.set_num(12);
  cout << "num1 for b2 changed to " << b2.get_num() << endl;
  cout << "num1 for b3 changed to " << b3.get_num() << endl;

  Base *b4 = new Base();
  cout << "num1 for b4 = " << b4->get_num() << endl;
  cout << "name for b4 = " << b4->get_name() << endl;

  // derived class
  cout << "--------------------------------------------" << endl;

  Derived d1;
  d1.set_num(45);
  cout << "num1 for d1 = " << d1.get_num() << endl;

  Derived *d2{nullptr};
  d2 = new Derived();
  d2->set_num(67);

  d2->change_num2(34);
  cout << "num2 for d2 = " << d2->get_num2() << endl;

  cout << "--------- d3----------------------------" << endl;

  Derived d3(23);
  cout << "num2 for d3 = " << d3.get_num2() << endl;
  cout << "num1 for d3 = " << d3.get_num() << endl;

  cout << "--------- d4--------------------------" << endl;
  Derived d4(91);
  cout << "num1 for d4 = " << d4.get_num() << endl;
  cout << "num2 for d4 = " << d4.get_num2() << endl;
  cout << "num3 for d4 = " << d4.num3 << endl;

  return 0;
}