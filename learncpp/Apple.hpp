#ifndef _APPLE_H_
#define _APPLE_H_

#include<iostream>
#include<stdio.h>
#include <string>
#include "fruit.hpp"

using namespace std;

class Apple: public fruit{

    private:
    double fibre;

    public:
    
  friend ostream &operator<<( ostream &output, const Apple &a ) { 
        output << "Apple(" << a.getName() << ", " << a.getColor() << ", "<< a.get_fibre() << ")" << endl;
         return output;            
      }    
    Apple(){}
    Apple(string n):fruit(n){}
    Apple(string n, string c):fruit(n,c){}
    Apple(string n, string c, double f):fruit(n,c),fibre{f}{} // overloaded constr- base part of the construc called then derived part
    double get_fibre()const {return fibre;}
    ~Apple(){}

};

  

#endif