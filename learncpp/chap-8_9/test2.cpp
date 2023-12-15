#include <iostream>
#include <stdio.h>

using namespace std;

auto fun1(int x, int y){
    cout <<"fun1 first" << endl;
    return x+y;
}

auto fun1(int x, int y, int z){
    cout <<"fun1 second" << endl;
    return x+y+z;
}

// double fun1(double x, double y, double z){
//     cout <<"fun1 third" << endl;
//     return x+y+z;
// }

template<typename T>
auto fun2(T a, T b){
    return a+b;
}

template<typename T, int N>
auto fun3(T a, T b, T c){
    cout << "N = " << N << endl;
    return a+b+c;
}

int main(){
 using D= double; // type alias for the type double
 typedef int I;   // type alias for the type int 

  D y {5.5};
  
  cout << "y = " << y << endl;
  I x = static_cast<I>(y); // numeric conversion here from double to int

  // I d {5.4}; // brace initialization doesn't allow narrowing conversion- ERROR

  cout << "x = " << x << endl;
  
    //   cout << "type of x = " << typeid(x) << endl;

  D d1 {45.5};

  cout << "fun1(4,5) = " << fun1(4,5) << endl;
  cout << "fun1(4.5,5.1) = " << fun1(4.5,5.1) << endl; // does numeric conversion here
  cout << "fun1(4.5,5.1,5.3) = " << fun1(4.5,5.1,5.3) << endl; // does numeric conversion here

  cout << "fun1(4.5,5,5.3) = " << fun1(4.5,5,5.3) << endl; // does numeric conversion here

  cout << "fun2(23,1) = " << fun2<int>(23,1) << endl;

  cout << "fun3(5.4,45.2,34.1) = " << fun3<double,5>(5.4,45.2,34.1) << endl;

    return 0;
}