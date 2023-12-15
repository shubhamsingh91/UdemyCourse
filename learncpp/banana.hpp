#ifndef _BANANA_H_
#define _BANANA_H_

#include<iostream>
#include<stdio.h>
#include <string>
#include "fruit.hpp"

using namespace std;

class Banana: public fruit{
  using fruit::fruit; // to get the fruit constructurs here

    public:
    
  friend ostream &operator<<( ostream &output, const Banana &b ) { 
        output << "Banana(" << b.getName() << ", " << b.getColor()  << ")" << endl;
         return output;            
      }    
    Banana():fruit("banana","yellow"){}
    ~Banana(){}

};

  

#endif