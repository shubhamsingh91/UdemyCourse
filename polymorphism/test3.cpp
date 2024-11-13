#include "../utils.h"
#include <iostream>
#include <stdio.h>
#include "master.h"


int main(){

    slave1 s1;
    s1.fun();
    
    printline();

    master* ptr1 = new slave1();
    ptr1->fun();
    ptr1->fun2();


}
