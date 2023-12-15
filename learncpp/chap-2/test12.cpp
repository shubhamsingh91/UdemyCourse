#include <stdio.h>
#include <iostream>
using namespace std;

extern int num;
extern const int num3;

 void fun1(){  // internal function here with static
    cout << "fun1 here" << endl;
    cout << "num = " << num << endl;
}