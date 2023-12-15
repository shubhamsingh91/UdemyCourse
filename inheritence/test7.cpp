#include "base3.h"
#include "derived3.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

 base3 b1(1,"Shubham");
  b1.print();
  base3  b2{12,"John"};
  b2.print();
  cout << "b2 name = " << b2.get_name() << endl;

  derived3 d1(10,"shubham");
  d1.print();
  d1.base3::print();
  cout << d1.base3::get_name() << endl;

  derived3 d2(1,2,3,4,5,"Hello");
  d2.print();
  d2.base3::print();
    cout << d2.base3::get_name() << endl;

 cout << "----------------1---------------------" << endl;

  base3* ptr = new base3{1,2,3,"shubham"};
  ptr->print();

  base3* ptr1 = new derived3{4,5,6,4,5,"hello"};
  ptr1->print();
  
  ptr1->set_num3(12);
  cout << "ptr1->num3 = " << ptr1->num3 << endl;


}

