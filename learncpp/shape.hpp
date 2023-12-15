#ifndef _SHAPE_H_
#define _SHAPE_H_

#include<iostream>
#include<stdio.h>

class Shape{

public:
virtual std::ostream &print(std::ostream & rhs)=0;
friend std::ostream& operator<< (std::ostream& os, Shape & rhs){
    return rhs.print(os);
};
virtual ~Shape()= default;

};




#endif 