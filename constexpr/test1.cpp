#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdio.h>
#include "../utils.h"

using namespace std;

constexpr int getnum(){
    return 5;
}

constexpr int getnum1(int x){ // should be eval at compile time or will give a error
    return x;
}

// constexpr function- can be evaluated at run-time or compile-time, dpeending on the inputs
constexpr int get_num2(int x){
    return x;
}


int main()
{
 const int t1 = 34;
 constexpr int x=1;
 constexpr int y{getnum()};
 constexpr int z{getnum1(t1)};

 cout << "x = " << x << endl;
 cout << "y = " << y << endl;
 cout << "z = " << z << endl;

 int w {4};
 int u{get_num2(w)};
//  print("u = ", u);

constexpr int t2 {get_num2(23)}; 

    return 0;
}