#ifndef _base2_h_
#define _base2_h_

#include<iostream>
#include<stdio.h>
#include"top.h"
using namespace std;

class base2 : public top{

private:
 int num;

public:
  base2(){}
  void say_hello() {cout << "hello in base" << endl;} // virtual keyword for dynamic run-time binding
  void fun(){cout << "fun in base" << endl; }
  int get_num(){return num;}
  void set_num(int z){num=z;}
 
  ~base2(){} 

};


#endif