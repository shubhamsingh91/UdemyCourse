#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <iostream>
#include <stdio.h>
#include "Shape.h"
#include <math.h>

class Triangle : public Shape{

private:
  double base, height;
  bool doubleBase;

 public:
 Triangle(double b, double h , bool j):base{b},height{h},doubleBase{j}{
    if(doubleBase)
    {base=base*2.0;}
    }
 ~Triangle(){}

 virtual double getArea(){
    return base*height*0.5;
    
    
 }
 virtual double getPerimeter(){
    return sqrt(base*base+height*height)+base+height;
 }


};

#endif