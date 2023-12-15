#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <iostream>
#include <stdio.h>
#include "Shape.h"
#include <math.h>

class Rectangle : public Shape{

private:
  double width, height;
  bool halfHeight;

 public:
 Rectangle(double w, double h , bool b):width{w},height{h},halfHeight{b}{
    if(halfHeight)
    {height=height*0.5;}
    }
 ~Rectangle(){}

 virtual double getArea(){
    return width*height;
    
    
 }
 virtual double getPerimeter(){
    return 2*(width+height);
 }


};

#endif