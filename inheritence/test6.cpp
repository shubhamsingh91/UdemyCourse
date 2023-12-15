#include "base2.h"
#include "derived2.h"
#include "Derived.h"
#include <iostream>
#include <stdio.h>
using namespace std;


int main(){

  base2 b1(34,2,1,"shubham");
  cout << "b1.name= "<< b1.get_name() << endl;
  cout << "b1.num1= "<< b1.get_num1() << endl;
  cout << "b1.num2= "<< b1.get_num2() << endl;
  cout << "b1.num3= "<< b1.get_num3() << endl;

 derived2 d1(11,2,"hiya");

    cout << "d1.num1 = " << d1.get_num1() << endl;
    cout << "d1.base2.num1 = " << d1.base2::get_num1() << endl;

 derived2 d3(1,2,3,4,5);
    cout << "d3.num1 = " << d3.get_num1() << endl;
    cout << "d3.base2.num1 = " << d3.base2::get_num1() << endl;

    cout << "d3.num2 = " << d3.num2 << endl;
    cout << "d3.base2.num2 = " << d3.base2::get_num2() << endl;
    cout << "d3.base2.num2 = " << d3.getbase_num2_m() << endl;

    cout << "d3.base2.num3 = " << d3.base2::get_num3() << endl;
    cout << "d3.base2.num3 = " << d3.getbase_num3_m() << endl;

    cout << "d3.name = " << d3.name << endl;
    cout << "d3.base2.name = " << d3.base2::name << endl;

    cout << "d3 all names =" << d3.concate_names() << endl;

 //    derived2 d2(); // this is wrong- read Most Vexing Parse error, this declares d2 as a function prototypet that returns an object of Derived2 class
  derived2 d2;

    cout << "d2.num1 = " << d2.get_num1() << endl;
    cout << "d2.name = " << d2.name << endl;

 cout << "--------------1---------------------" << endl;
 
 base2 b2(1,2,3,"Hola");

 cout << b2.name << endl;
 base2 b3{b2};

  cout << "b3.num1 = " << b3.get_num1() << endl;
  cout << "b3.num2 = " << b3.get_num2() << endl;
  cout << "b3.num3 = " << b3.get_num3() << endl;
  cout << "b3.name = " << b3.name << endl;

  derived2 d4{d3};

  cout << "d4.num1 = " << d4.get_num1() << endl;
  cout << "d4.base2.num1 = " << d4.base2::get_num1() << endl;

    cout << "d4 all names =" << d4.concate_names() << endl;

  cout << "-----------------2-----------------------" << endl;

  base2* p =  new base2(1,2,3,"shubham");

  cout << "p.name = " << p->get_name() << endl;

  base2* p1 = new derived2(); // p1 is a pointer of type base
  cout << "p1 name = " << p1->get_name() << endl;




    return 0;
}
