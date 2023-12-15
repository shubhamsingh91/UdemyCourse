#ifndef _BASE1_H_
#define _BASE1_H_
#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T>
class base1{
 
 private:
    T num1;

 public:
   T num2;

   base1(){};
   base1(T n):num1{n}{};
   void print_nums(){
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
   }
   void set_nums(T n, T m){
     num1=n; num2=m;
   };

   ~base1(){};


};









#endif