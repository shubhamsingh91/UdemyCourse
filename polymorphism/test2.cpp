#include<iostream>
#include <stdio.h>
#include "base2.h"
#include "derived2.h"

using namespace std;

int main(){

     derived2 d1;

     d1.say_hello();

     cout << "------1--------" << endl;
     base2 *p1 = new derived2();
     base2 *p2 = new base2();
    p1->say_hello();
    p2->say_hello();
    p1->fun();
    p2->fun();
    
    cout << "------2--------" << endl;
     
    derived2 d2;
    base2 & ref = d2;

    d2.say_hello(); 

    delete p1;
    delete p2;

    return 0;
}

