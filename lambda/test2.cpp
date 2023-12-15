#include<iostream>
#include<stdio.h>
#include "displayer.h"
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func){

    std::cout <<"[";
    for (int i:vec){
      if (func(i))
         std::cout<< i << " ";
    }
   std::cout << "]" << std::endl;
}

// function for returning a lambda function

auto make_lambda(){
    return [](){std::cout << "lambda made using make_lambda function" << std::endl;};
}
int global_x{1000};  // cant be captured

int main()
{
    std::vector<int> nums{10,20,30,40,50,60,70,80,90,100};
     
    filter_vector(nums,[](int x){return x>50;});
    filter_vector(nums,[](int x){return x<30;});

    auto l1 = [](int x){return x>30;}; // returns boolean
    cout << "l1(20) = " << l1(40) << endl;

    cout << "-----1------" << endl; 

    auto l2 = make_lambda();  // making a lambda function
    l2();  // calling this made lambda
 
    cout << "-----2------" << endl; 

    auto l3 = [](auto x, auto y){std::cout << "x = " << x << " y = " << y << endl;};
    l3(56,3.1);
    l3(12,0.553);
    l3('a',56.4);
    l3("Hello world",45);

    cout << "-----3------" << endl; 
     int local_x {100};
     auto l4 = [local_x](){    // capture by value
        cout << local_x << endl;
        cout << global_x << endl;
     };
      l4();

    cout << "-----4------" << endl; 
    
    int x{100};
    auto l5 = [x]() mutable{  // allows to change x inside
        x+=100;
        std::cout << x << std::endl;
    };
     l5();
     std::cout << x << std::endl;
     l5();


    cout << "-----5------" << endl; 

   {

    int x{100};
    auto l6 = [&x] () mutable{
        x+=100;
        std::cout << x << std::endl;
    };
        l6();
        std::cout << x << std::endl;

   }

    cout << "-----6------" << endl; 
   
   {
   int x{100};
   int y{200};
   int z{300};

   auto l1 = [&]() mutable{
    x+=100;
    y+=100;
    std::cout <<x << std::endl;
    std::cout <<y << std::endl;
  
   };
   l1();
     std::cout <<x << std::endl;
    std::cout <<y << std::endl; 


   }


 return 0;
}