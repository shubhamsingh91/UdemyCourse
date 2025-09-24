#include <iostream>
#include <memory>
#include "../utils.h"
#include "Base.h"

// practicing smart pointers
int main(){
 
    float f = 21.0;
    std::cout << "f = " << f << std::endl;
    std::cout << "&f = " << &f << std::endl;
    float* raw_1 (&f); // raw pointer for f- stores the address of f

    std::cout << "raw1 = " << raw_1 << std::endl;
    print("*raw1",*raw_1);

    std::unique_ptr<float> ptr1 = std::make_unique<float>(f); // initialized with f- creates a new raw pointer and ptr1 manages that
    std::unique_ptr<float> ptr2 (raw_1); // initializes ptr2 with raw_1

    print("ptr1",*ptr1);
    print("ptr1.get", ptr1.get());
    print("ptr2.get() = ", ptr2.get());


    


}