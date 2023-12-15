#include<iostream>
#include<stdio.h>
#include "displayer.h"
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
 
 auto p =[](){return 5;}; // without type specifier
 cout << p() << endl; // calling a lambda function here

 auto l1 = [](int x)->int{return 7+x;}; // with type specifier and parameter list
 cout << l1(34) << endl;

 {

    int x{12};
    auto l1= [x](int y){return x+y;};
    cout << l1(2) << endl;

 }


    return 0;
}