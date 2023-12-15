#include <iostream>
#include <stdio.h>
#include "base4.h"
#include "derived4.h"
#include "main1.h"
using namespace std;

int main(){

base4 *p1 = new base4{};
p1->print();
p1->name = "shubham";
p1->num2 = 34;

p1->print();

derived4 p2{12,"shubham"};
p2.print();
cout << p2.base4::get_name() << endl;
p2.base4::print();

derived4 p3{1,2,3,4,"shubham","john"};
p3.print();
p3.base4::print();
cout << p3.add_num3(12) << endl;


base4 *ptr1 = new derived4{12,13,24,56,"shubham","john"};
ptr1->print(); 

main1 *ptr2 = new derived4{1,2,3,4,"h","c"};
ptr2->print();

auto ptr3 = dynamic_cast<derived4*>(ptr2);
cout << ptr3->add_num3(23) << endl;


}