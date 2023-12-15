#ifndef _BASE3H_
#define _BASE3H_

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class base3
{
 private:
  int num1;

 protected:
 int num2;
 std::string name;

 public:
 int num3;

 base3(){};
 base3(int x, const string &s):num1(x),num2{0},num3{0},name{s}{};
 base3(int x,int y, int z):num1{x},num2{y},num3{z}{};
 base3(int x,int y, int z, string s):num1{x},num2{y},num3{z},name{s}{};
 void set_num2(int x){num2=x;}
 virtual void set_num3(int y){num3=y;};
 virtual void print(){ // dynamically linkedm not statically
    cout << "num1,2,3 = " << num1 << ", "<< num2 << ", " << num3 <<endl;
 }
 std::string get_name(){return name;}
 ~base3(){};

};



#endif