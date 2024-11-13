#include <iostream>
#include "../utils.h"

auto create_lam(int x) {
    
    return [x]() mutable-> void{
        x = 546;
        print("x = ",x);};
}

auto create_lam2(int &x) {
    
    return [&x]() { // capture by reference allows changing the variable
        x = 34;
        print("x = ",x);};
}

int main() {

int x {78};
auto lam1 = [x](int y){print("x+y = ",x+y);};

lam1(23);

auto lam2 {create_lam(34)};
lam2();


auto lam3 {create_lam2(x)};
lam3();


{
 float f{23.5};
 double d{56.2};
 int x{67};

 auto lam = [=](){
                // f = 67.1;   // only reading allowed. not changing
                print("f = ",f);
                print("d = ",d);};
  
  lam();

 auto lam1 = [&](){
                f = 67.1;  d = 87.1;
                print("f = ",f);
                print("d = ",d);};
  
  lam1();

 auto lam2 = [=,&d,&f](){ // f and d pass by ref, others pass by value (can't be changed)
                f = 56.1;  
                d = 12.1;
                print("f = ",f);
                print("d = ",d);
                print("x = ",x);};
  
  lam2();


}


}