#include <iostream>
#include <stdio.h>
#include "base1.h"
#include "derived1.h"

using namespace std;

base1* getObject(bool returnderived){
    if (returnderived){
        return new derived1{1,"Apple"};
    }
    else{
        return new base1{2};
    }
}

int main(){

 base1* b{getObject(true)};
 derived1* d {dynamic_cast<derived1*>(b)}; // dynamic casting to down-cast from a base to a derived pointer

if (d){
 cout<< d->getName() << endl;}



}
