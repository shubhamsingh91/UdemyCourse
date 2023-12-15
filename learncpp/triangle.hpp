#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include<iostream>
#include "shape.hpp"
#include "Point.hpp"
using namespace std;

class Triangle : public Shape{

private:
  Point p1,p2,p3;


 public:
 Triangle(Point p1, Point p2, Point p3):p1{p1},p2{p2},p3{p3}{}
 std::ostream &print(std::ostream & os){
   os << "Triangle(  " << p1 << ", " << p2 << ", " << p3 << ")" << endl;  
    return os;}
 ~Triangle(){}
 


};



#endif