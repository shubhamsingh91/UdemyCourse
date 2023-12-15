#include <iostream>
#include <stdio.h>
#include "base5.h"
#include "derived5.h"
using namespace std;

int main(){

    base5 b1;
    
    base5 b2{45};
    b2.print_nums();

    b2.increment_num1();
    b2.print_nums();

    b1.print_nums();
    b1.increment_num1();

    b1.print_nums();
    b2.print_nums();

    std::cout << "--------------------1--------------" << std::endl;
    derived5 d1{34};
    derived5 d2{2,4};
    d2.print_nums();
    d2.increment_num1();
    d2.print_nums();
    
    d2.base5::print_nums(); // calling the print_nums from the base class function

    std::cout << "--------------------2--------------" << std::endl;

    base5 *b3 = new derived5(); // object of type base5
    b3->print_nums();

    base5 *b4 = new base5();
    b4->print_nums();

    std::cout << "--------------------3--------------" << std::endl;

}

