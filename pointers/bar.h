#pragma once
#include <iostream>
#include <string>

class Bar{
 
 private:
   int num1, num2, num3;
   std::string name1, name2;

 public:
    Bar(int n1, int n2, int n3, std::string nm1):
    num1{n1}, num2{n2}, num3{n3}, name1{nm1}, name2{"test"}{}
  
    // return by ref
    int& get_n1(){return num1;}

    // return by const ref
    const int& get_n2(){return num2;}

    // return by const val
    const int get_n3(){return num3;}
    
    ~Bar(){}

};