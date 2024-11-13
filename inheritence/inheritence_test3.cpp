#include "Base.h"
#include "Derived.h"
#include <iostream>
#include <stdio.h>
// #include "../utils.h"

using namespace std;

int main() {


  print("------------ Testing Base and derived object------------");

  Base b1;
  b1.get_all_nums();

  Base b2{1,2,3,4,"Shubham"};
  b2.get_all_nums();

  Base b3{b2};
  b3.get_all_nums();
  b3.get_name();

  print("-----------------------------------");
 
  Base b4{Base{3,4,5,6,"John"}}; // copy  elision, try with -fno-elide-constructors flag to see the copy constructor call
  b4.get_all_nums();
  print("double of 45 = ", b4.squared_fun(45));

  print("-----------------------------------------");
  Base *ptr1 = new Base{1,2,"Rock"};
  ptr1->get_all_nums();
  ptr1->get_name();

  Base *ptr2 {&b4};

  ptr2->get_all_nums();
  ptr2->get_name();

  // derived class
  cout << "\n --------------------------------------------" << endl;

   Derived d1 {23,41};
   d1.get_derived_nums();

  cout << "\n --------------------------------------------" << endl;

   Derived d2{d1};
   d2.get_derived_nums();

   Derived d3{1,2,3,4,5,6,"Bob"};
   d3.get_all_nums();
   d3.get_derived_nums();

   Base *ptr3 = new Derived(); // basically a base object ptr- uses static (compile-time binding)
   ptr3->get_derived_nums();

  // d1.set_num(45);
  // cout << "num1 for d1 = " << d1.get_num() << endl;

  // Derived *d2{nullptr};
  // d2 = new Derived();
  // d2->set_num(67);

  // d2->change_num2(34);
  // cout << "num2 for d2 = " << d2->get_num2() << endl;

  // cout << "--------- d3----------------------------" << endl;

  // Derived d3(23);
  // cout << "num2 for d3 = " << d3.get_num2() << endl;
  // cout << "num1 for d3 = " << d3.get_num() << endl;

  // cout << "--------- d4--------------------------" << endl;
  // Derived d4(91);
  // cout << "num1 for d4 = " << d4.get_num() << endl;
  // cout << "num2 for d4 = " << d4.get_num2() << endl;
  // cout << "num3 for d4 = " << d4.num3 << endl;

  return 0;
}