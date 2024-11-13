#include <iostream>
#include <stdio.h>
using namespace std;

template <typename T>
T fun(T var)
{
    std::cout << "templated function!" << std::endl;
    return var*var;
}

template <>
float fun<float>(float var)
{
    std::cout << "running float function" << std::endl;
    return var*var;
}

template int fun<int>(int var); // this is called as explicit specialized declaration to avoid bloat.
            // this will instantiate fun for int at this point.

int main()
{
 
 auto f = fun<float>(34.1);
 std::cout << "f = " << f << std::endl;

  int i = fun<int>(12);
  std::cout << " i = " << i << std::endl;

  auto j = fun(9);
  std::cout << " j = " << j << std::endl;



}