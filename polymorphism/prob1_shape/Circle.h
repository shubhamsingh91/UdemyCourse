#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <iostream>
#include <stdio.h>
#include "Shape.h"
#include <math.h>

class Circle : public Shape{

private:
  double radius;
  bool doubledRadius;

 public:
 Circle(double r, bool b):radius{r},doubledRadius{b}{
    if(doubledRadius)
    {radius=radius*2.0;}
    }
 ~Circle(){}

 virtual double getArea(){
    return M_PI*(radius*radius);
    
    
 }
 virtual double getPerimeter(){
    return 2*M_PI*radius;
 }


};

#endif