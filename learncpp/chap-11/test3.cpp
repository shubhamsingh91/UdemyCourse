#include <iostream>
#include "../../utils.h"
using namespace std;
// templates

template <typename T, typename U>
struct Pair
{
    T first;
    U second;
};
//template deduction guide needed in C++17,not in C++20
template <typename T, typename U>
Pair(T,U) ->Pair<T,U>;

template <typename T, typename U>
using Coord = Pair<T,U>;

int main(){

    std::pair p1{1,2};
    print(p1.first);
    print(p1.second);

    Pair p2{45,2.6};
    print(p2.first);
    print(p2.second);
    

    print("-----------------------------------\n");
    typedef Pair<int,int> point;
    point p3{34,12};
    print(p3.first,p3.second);

    print("-----------------------------------\n");
    Coord<int,double> cord1{12,67.2};

    return 0;
}