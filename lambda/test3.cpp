#include<iostream>
#include<stdio.h>
#include "displayer.h"
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

auto make_lambda(){

    return [](){cout << "This lambda function is made through make_lambda" << endl;};
}


int main()
{
 
 auto l1 =  [](int z){std::cout << "z = " <<  z << std::endl;};
 l1(34);

 Displayer<int> d1;
 d1(12);
 
 Displayer<std::string> s1;
 s1("Hello!");


 auto l2 = [](int x, int y){return x+y;};
 cout << l2(68,2.0) << endl;

 auto l3 = make_lambda();
 l3();

 cout<< "-----------1--------------" << endl;
 {
   int x=100;  int y=12; string z="Hello";

   auto l4 =[=]()  {
    cout << z << endl;
    return x+y; };

   std::cout << l4() << std::endl;
   
   auto l5 = [&](){x+=12; 
    z="Hello World!";
    cout << z << endl;
     return x+y;};
   cout << l5() << endl;
 }


return 0;
}