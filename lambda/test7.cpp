#include<iostream>
#include<stdio.h>
#include "displayer.h"
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

auto make_lambda(int x){
    return [](int x){return x+1;};
}

int main(){

 auto f = [](int x) {return x+5;};
 cout << f(4) << endl;

 int y=23;
 auto f1{ [y](int x){return x+y;}};
 cout << f1(2) << endl;
 
 int x=12;
 auto f2 = make_lambda(x);
cout << f2(15) << endl;



    return 0;
}