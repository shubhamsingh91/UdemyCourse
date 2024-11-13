#include <iostream>
#include <stdio.h>
#include "base5.h"
#include "derived5.h"
#include "Base.h"
#include "Derived.h"
// #include "../utils.h"
using namespace std;

int main(){

    Base *ptrb3 = new Derived(); // base class ptr- can access only base class part of the derived object here


    printline();

    base5 *ptrb1 = new base5{12}; 
    ptrb1->print_nums();

    print("-------------------------------------");
    base5 *ptrb2 = new derived5{14};
    ptrb2->print_nums();
    print(ptrb2->num2);

    printline();
    base5 * ptrb4 = new derived5{16,17};
    ptrb4->print_nums();
    
    print(ptrb4->print_num3());
    print(ptrb4->num2);
    


    printline();


    // base5 b1;
    
    // base5 b2{45};
    // b2.print_nums();

    // b2.increment_num1();
    // b2.print_nums();

    // b1.print_nums();
    // b1.increment_num1();

    // b1.print_nums();
    // b2.print_nums();

    // std::cout << "--------------------1--------------" << std::endl;
    // derived5 d1{34};
    // derived5 d2{2,4};
    // d2.print_nums();
    // d2.increment_num1();
    // d2.print_nums();
    
    // d2.base5::print_nums(); // calling the print_nums from the base class function

    // std::cout << "--------------------2--------------" << std::endl;

    // base5 *b3 = new derived5(); // object of type base5
    // b3->print_nums();

    // base5 *b4 = new base5();
    // b4->print_nums();

    // std::cout << "--------------------3--------------" << std::endl;

}

