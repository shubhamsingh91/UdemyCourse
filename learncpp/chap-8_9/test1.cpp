#include <iostream>
#include <stdio.h>

using namespace std;

// chapter 8/9 practice learncpp

auto fun1(int x, int y){
    cout <<"fun1 first" << endl;
    return x+y;
}

auto fun1(int x, int y, int z)->int // trailing return type, auto is not here for type-deduction, but only for syntax, if z=a (providing default) then compiler gets confused if only 2 args are provided which one to call
{    cout <<"fun1 sec" << endl;

    return x+y+z;
}

int main(){

 float f1 {3}; // impicit compiler coversion
 cout << "f1 = " << f1 << endl;
  float f2 {3.5}; 

 int n2 = 5.6; //narrowing conversion (data lost) from float to int- ALLOWED
 //int n1 {3.5}; // brace initialization doesnt allow narrowing conversin

 //cout << "n1 = " << n1 << endl;
 cout << "n2 = " << n2 << endl;

 cout << static_cast<int>(f2) << endl;

 cout << fun1(56,3) << endl;
 cout << fun1(56,3,45) << endl;

 //int &num2 {5}; // references cant be for r-values
 const int &num3 {56};// rvalues can have const references- rvalue reference (has to be const)
 
  //cout << "num2 = " << num2 << endl;
  cout << "num3 = " << num3 << endl;
 
 int num4 {67};
 int &num5 {num4};// lvalue reference is initialized to num4, cant be re-setted

  cout << "num5 = " << num5 << endl;
  num5 = num3;  // now num4 changed essentially- since num5 is an alias and is changed
    cout << "num5 = " << num5 << endl; 
    cout << "num4 = " << num4 << endl; // now num4 changed

    
}