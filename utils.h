#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
void print(const T &var){
  std::cout << var << std::endl;
}

template <typename T1, typename T2>
void print(const T1 &var1, const T2& var2){
  std::cout << var1 << " " << var2 << std::endl;
}
