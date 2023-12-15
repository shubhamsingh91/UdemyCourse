#ifndef _BASE4H_
#define _BASE4H_

#include <iostream>
#include <stdio.h>
#include <string>
#include "main1.h"
using namespace std;

class base4 : public main1{

private:
 int num1;

public:
 int num2;
 string name;

  base4(){};
  base4(int x,int y, int z, string n):num1{x},num2{y},num3{z},name{n}{};
  string get_name(){return name;}
  virtual void print(){cout << "num1 = " << num1 <<
  " num2 = " << num2 << " num3 = " << num3 << " name ="<<
  name << endl;}
  ~base4(){};

protected:
 int num3;

};


#endif