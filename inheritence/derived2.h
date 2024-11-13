#ifndef _DERIVED2_H_
#define _DERIVED2_H_
#include <iostream>
#include <stdio.h>
#include <string>
#include "base2.h"
using namespace std;


class derived2 : public base2{

private:
 int num1;

public:
 int num2;
 std::string name;
 derived2():num1{12},num2{13},name{"default"}{std::cout << "default constructor" << std::endl;};

 derived2(int x,int y,std::string n):num1{x},num2{y},name{n}{cout << "Overloaded constru" << endl;}
 derived2(int u, int v, int x, int y, int z):base2(u,v,x,"Lol"),num1{y},num2{z},name{"Hey"}{};
 derived2(const derived2& d2):base2{d2}{ // d2 "is a" base object as well
    num1=d2.num1;
    num2=d2.num2;
    name=d2.name;
 }
 int get_num1(){return num1;};
 virtual string get_name(){
    std::cout << "derived get_name--- ";
   return name;}
 int getbase_num2_m(){return base2::num2+69;}
 int getbase_num3_m(){return base2::num3+89;}
 string concate_names(){return name+" "+base2::name;}
 ~derived2(){};


};



#endif