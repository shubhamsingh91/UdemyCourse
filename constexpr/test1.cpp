#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdio.h>
using namespace std;

constexpr int getnum(){
    return 5;
}

constexpr int getnum1(int x){ // should be eval at compile time or will give a error
    return x;
}


int main()
{
 int t1 = 34;
 constexpr int x=1;
 constexpr int y{getnum()};
 constexpr int z{getnum1(t1)};

 cout << "x = " << x << endl;
 cout << "y = " << y << endl;
 cout << "z = " << z << endl;

    return 0;
}