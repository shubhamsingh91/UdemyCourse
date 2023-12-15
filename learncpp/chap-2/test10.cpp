#include<iostream>
#include <stdio.h>

/*
contents-
1. tried a namespace implementation
2. tried static variables, global variables
3. tried nested namespaces
4. 

*/ 

extern int num8; // need the extern here for forward dec
extern const int num9; // need the extern here for forward dec

int num2 = 12; // global var

int fun3(int x); // declared in some other file can be accessed here by providing declaration
static int fun4(int x); // declared in some other file NOT accessible here since static function
extern constexpr int fun5(int x); // declared in some other file NOT accessible here since constexpr function (becomes internal to that file)- extern doesnt help here since for constexpr, the compiler has to know everything at compile time- need declaration here
int fun6(int x);

namespace t1{
 
int fun1(int x)
{
    return x+1;
}
int fun1(int x, int y){
    return x+y+1;
}

struct c1{
  static int numc1; // non-const static cant be initialized here
  const static int numc2 {97};  // constant static var has to be initialized at the first point
};

 namespace  t2 {
   static int num1=2;
 }
}
int t1::c1::numc1 = 34; // has to be initialized outside the class

inline int fun1(int x){ // gives a hint to the compiler that this can be made inline
    return x+2;
}
int main(){

  std::cout << ::fun1(45) << std::endl;
  std::cout << t1::fun1(45) << std::endl;
  std::cout << t1::fun1(45,47) << std::endl;

  std::cout << (4,5) << std::endl; // evaluates and prints the expression on the right

  std::cout << t1::t2::num1 << std::endl;
  int x=1;
  {
  std::cout << x << std::endl; // x available in this scope
    int y=2;  // y available only in this scope
  }

  t1::c1 c;

  std::cout << "c.numc2 = " <<c.numc2 << std::endl;
  std::cout << "c.numc1 = " <<c.numc1 << std::endl;
   
   int num2 = 78; // shadows the global var num2
 
  std::cout << "num2 = " << num2<< std::endl;
  std::cout << "::num2 = " << ::num2<< std::endl; // to call the num2 in the global namespace

   std::cout << "fun3(12) = " << fun3(12) << std::endl;
   //std::cout << "fun4(12) = " << fun4(12) << std::endl; // not accessible here since internal to the fun file
   // std::cout << "fun5(12) = " << fun5(16) << std::endl; // not accessible here, since internal to fun file
   // std::cout << "fun6(16) = " << fun6(16) << std::endl; // not accessible here, since internal to fun file
   
   std::cout << "num8 = " << num8 << std::endl;
   std::cout << "num9 = " << num9 << std::endl;


    return 0;


}