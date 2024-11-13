#include <iostream>
#include "base6.h"

using namespace std;

// base6::base6(){std::cout << "default constructor!" << std::endl;};

base6::base6(int n1, float n2, int n3, int n4):num1{n1}, 
        num2{n2}, num3{n3}, num4{n4}{};

int base6::fun(int x){
    std::cout << "inside base6 fun" << std::endl;
 return x + num1;
}

void base6::print(){
    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;
    std::cout << "num3 = " << num3 << std::endl;
    std::cout << "num4 = " << num4 << std::endl;
}

void base6::bar(){std::cout << " inside bar base6" << std::endl;};

derived6::derived6(int n1, float n2, int n3, int n4):base6(n1,n2,n3,n4){};

int derived6::fun(const int x){
    std::cout << "inside derived6 fun" << std::endl;
    return 2*x*num3;
}

void derived6::bar(){std::cout << " inside bar derived6" << std::endl;};
