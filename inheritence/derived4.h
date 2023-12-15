#ifndef _DERIVED4_H_
#define _DERIVED4_H_
#include <iostream>
#include <string>
#include "base4.h"

using namespace std;

class derived4 : public base4{

private:
string name;

public:
int num1;

 derived4(){};
 derived4(int x, string n):name{n},num1{x}{};
 derived4(int x1,int x2,int x3, int x4, string n1, string n2):base4{x1,x2,x3,n1},num1{x4},name{n2}{};
virtual void print() {cout << "num1 = " << num1 <<  " name = " << name << endl;} // wont be over-ridden dynamically if the signature of this function doesnt match the signature in derived class
int add_num3(int x){return base4::num3+x;};
virtual  ~derived4(){};

};

#endif