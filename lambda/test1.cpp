#include<iostream>
#include<stdio.h>
#include "displayer.h"
#include <string>
#include <vector>
#include<algorithm>
#include "../utils.h"

using namespace std;

struct Square_functor{
    void operator()(int x){
        std::cout << x*x << endl <<" ";
    }
};

 auto foo(){
    return [] (int x){std::cout << x;};
 }


int main()
{
 // testing displayer class
  Displayer <int>d1;
  d1(100);  // function object- using it like a function

  Displayer<std::string> d2;
  d2("hello world!");

  std::vector<int> vec1{1,2,3};

  std::for_each(vec1.begin(),vec1.end(),d1); // d1 is used here as a function object

 // lambda expression 
 std::for_each(vec1.begin(),vec1.end(),[](int x){std::cout << x << "" << std::endl;});

 // functor
 Square_functor s1;
 s1(45); // a function-object, basically a class object function here, but looks like a function "object"

 cout << "-----4------" << endl; 
 std::for_each(vec1.begin(),vec1.end(),[](int x){std::cout << x*x << "";});

 cout << "-----5------" << endl; 
 auto l= [](){std::cout << "Hi" << std::endl;}; // can define function objects using lambda expressions
 auto m= [](int x, int y) {std::cout << x+y << std::endl;};
 l();
 m(3,5); // function objects called with inputs
 m(5,6);

 cout << "-----6------" << endl; 

 auto n= [](int x, int y)-> int {return x+y;}; // can get rid of the arrow and return type, compiler can figure out
 cout << "n(4,5) = " << n(4,5) << std::endl;

 cout << "-----7------" << endl; 
 int x=5;
  
 auto p = [](int *x){cout << "x = " <<*x << endl;};
 p(&x); 

 cout << "-----8------" << endl; 
 auto q = [](auto x){cout << "x = " << x << endl;} ; // can use auto for parameter type specifier too

 q(56.7);

 cout << "-----9------" << endl; 
 // this function foo returns a lambda expression- deduced by auto

 auto k=foo(); // k is a lambda expression
 k(14);

 cout << "-----10------" << endl; 

 auto lamb1 = []() -> void{print("lambda1");};
 lamb1();

 print("------------11-------------");
 auto lamb2 = [x](int y) {return (x+y);}; // -> and reeturn type are optional
 
 print(lamb2(45));



 return 0;
}