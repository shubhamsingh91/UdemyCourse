// define your factorial() function template here
#include <iostream>
#include "../../utils.h"

template<int N>
constexpr int factorial() {
    static_assert(N >= 0);
    if constexpr (N > 0) {
        return N * factorial<N - 1>();
    } else {
        return 1;
    }
}

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    factorial<-3>(); // should fail to compile

    return 0;
}