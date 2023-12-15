#include <iostream>
#include <stdio.h>

using namespace std;

template <int N>
class list{

};

constexpr int sqr1(int arg){
    return arg*arg;
}

int sqr2(int arg){
    return arg*arg;
}

struct str1
{
float num2;
int num1;
};

int getnumber(){
   int y;
    cin >> y;
    return y;
}

constexpr int getCnumber(){// evaluated at compile time
   int y=51; 
    return y;
}

int main(){

    str1 s1{3.4,6};  // different kind of initialization here
    str1 s2{.num2=56.3,.num1=2}; // another kind of initialization here C++20

    cout << s1.num1 << endl;
    cout << s1.num2<< endl;

    cout << s2.num1 << endl;
    cout << s2.num2<< endl;

    constexpr int x=2;  // compile-time constant
    constexpr double y=5.6; // compile-time constant

    const int z {getnumber()}; // run-time const- initialized with non constant expressions- cant use constexpr here
    constexpr int z1 {getCnumber()}; // compile-time const- initialized with  constant expressions- can use constexpr here

     cout << "z+x= "<< z+x<< endl;
     cout << "z1+x= "<< z1+x<< endl;

     list<sqr1(4)> l1;   
     list<sqr1(16)> l2;   // won't compile since template arguments have to be constexprs












}