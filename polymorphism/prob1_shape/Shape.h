#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <stdio.h>


class Shape{

public:
 Shape()= default;
 virtual ~Shape() =default;
 virtual double getArea()=0;
 virtual double getPerimeter()=0;

};



#endif