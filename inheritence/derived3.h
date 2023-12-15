#ifndef _DERIVED3H_
#define _DERIVED3H_

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class derived3 : public base3 
{
 private:
  int num1;

 public:
 int num3;

 derived3(){};
 derived3(int x, const string &s):base3(x,s){};
 derived3(int x, int y, int z, int u, int v, const string &s):base3(x,y,z,s),num1{u},num3{v}{};
 virtual void set_num3(int y){num3=y;};
 virtual void print(){
    cout << "num1,3 = " << num1 << ", " << num3 <<endl;
    cout << "base name = " << base3::get_name() << endl;
        cout << "num3 for base3 = " << base3::num2 << endl;

 }
 ~derived3(){};

};



#endif