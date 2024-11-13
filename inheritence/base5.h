#ifndef _BASE5_H_
#define _BASE5_H_

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class base5{

 public:
    
    static int num1;
    int num2;

 public: 
    base5():num2{0}{cout << "base5 default const." << endl;}; // default constructor
    base5(int m): num2{m}{cout << "base5 single arg const." << endl;};  // constructor with inputs

    void set_num2(int n){num2=n;};

    int  get_num2(){return num2;};

    void set_num1(int n){num1 = n;};

    void increment_num1(){num1++;} // global increment across all objects
    
    virtual inline void print_nums(){ // will be bound dynamically now
        cout << "print_nums in base5" << endl;
        cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    }

     virtual int print_num3() {return 0;}; // just added to access the derived5 function using a base-class ptr

     virtual ~base5(){}; // default destructor
};

int base5::num1 = 5; // to initialize non-const static int












#endif