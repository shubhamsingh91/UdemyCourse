#ifndef _TEST4_H_
#define _TEST4_H_

#include <iostream>
using namespace std;

// Primary template declaration
template <typename T>
void fun(T var);

template<>
void fun<int>(int var)
{
    std::cout << "specialization for int" << std::endl;
}









#endif