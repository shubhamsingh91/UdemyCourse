#ifndef _derived2_h_
#define _derived2_h_

#include<iostream>
#include<stdio.h>
#include"base2.h"

using namespace std;

class derived2 final: public base2{
public:

derived2(){}
void say_hello() {cout<< "hello in der" << endl;}
void fun(){cout << "fun in der" << endl; }

~derived2(){}

};


#endif