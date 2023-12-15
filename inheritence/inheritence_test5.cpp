#include "Base.h"
#include "Derived1.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

  Base b1(4,5,"Shubham");
  cout << b1.get_num() << endl;
  cout << b1.get_num2() << endl;
  cout << b1.get_name() << endl;

  cout << "----------1---------" << endl;

  Derived1 d1(89,78);
  //d1.Base::set_num(12); // sets base one

  cout << d1.get_num() << endl;      // gets derived one
  cout << d1.Base::get_num() << endl;// gets base one  - to access the method from the Base part of the derived class
  d1.Base::num1 = 45;
  cout << d1.Base::get_num() << endl;// gets base one  
  d1.set_num3(32);
  d1.print_num3() ;
  cout << d1.Base::num1 << endl;

  
  // cout << "---------2----------" << endl;
  // Derived1 d2(12,45,11,"Shubham");

  // cout << d2.get_name() << endl;
  // cout << d2.get_num() << endl;
  // cout << d2.Base::get_num() << endl;
  // cout << d2.get_num2() << endl;

  // cout << "---------3---------" << endl;

  // Derived1 d3(d2);
  // cout << d3.get_name() << endl;
  // cout << d3.get_num() << endl;
  // cout << d3.Base::get_num() << endl;
  // cout << d3.get_num2() << endl;

  
    return 0;
}