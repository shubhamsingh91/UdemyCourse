#include <stdio.h>
#include <iostream>
#include "base.h"
#include "templatebase.h"

using namespace std;

int main(){

    base1<float> b1;
    b1.set_nums(12.1,4.3);
    b1.print_nums();

    base1<int> b2;
    b2.set_nums(3,4);
    b2.print_nums();

    cout << "-------------------1-----------------" << endl;

    templatebase<int,float,base1> t1(12);
    t1.printnum();
    t1.b1.set_nums(12.3,42.1);
    t1.b1.print_nums();

    return 0;
}