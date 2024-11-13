#include <iostream>
#include "../../utils.h"
using namespace std;
// templates

template <typename T>
T max1(const T a,const  T b) {
    
    return ((a > b) ? a : b);
}

template <>
std::string max1(const string a, const string b) = delete;

auto fun(auto x, auto y){
  return (x+y);
}


int main() {
 
  print(max1<int>(23,4));
  print(max1<double> (23.1,34.5));

  print(fun<double>(23.1,34.5));
  
  // print(max1<string>("a","b"));
    // int num1;
    // num1 = max1<int>(12,6);
    // print(num1);

    return 0;
}