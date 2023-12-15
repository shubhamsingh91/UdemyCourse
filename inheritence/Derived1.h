#ifndef _DERIVED1_H_
#define _DERIVED1_H_

#include <iostream>
#include "Base.h"
using namespace std;

class Derived1 : public Base{
    // -- this Base::Base not to be used often-- avoid
using Base::Base; // allows base class constructors access here, then derived objects can be called with base class constructor signature and the corresponding base class object will be formed

private:
int num1;
 
public:
Derived1(){cout << "Derived1 class default constructor called!"<< endl;};
Derived1(int z,int y):Base(z,y), num1(z) {cout << "Derived 1 arg constructor called!" << endl;} // base 2 arg constructor called here
Derived1(int x,int y, int z, string name):Base(y,z,name), num1(x) {cout << "Derived 1 arg constructor called!" << endl;} // base 2 arg constructor called here
//Derived1(const Derived1& obj):Base(obj),num1{obj.num1}{cout << "Derived1 copy constructor called"<< endl;}

void set_num(int z){ num1=z;}
int get_num(){return num1;}
void print_num3(){cout<< Base::num3 << endl; }
void set_num3(int z){
    Base::num3 = z;
}

~Derived1(){cout << "Derived1 class default destructor called!"<< endl;};

};





#endif