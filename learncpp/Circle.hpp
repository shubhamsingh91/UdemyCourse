#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include<iostream>
#include "shape.hpp"
#include "Point.hpp"
using namespace std;

class Circle : public Shape{

private:
  Point p;
  int radius;


 public:
 Circle(Point p, int r):p{p},radius{r}{}
 std::ostream &print(std::ostream & os){
   os << "Circle(  " << p << ", radius "<< radius << ")" << endl;  
    return os;}
int getRadius(){return radius;}

 ~Circle(){}
 


};



#endif