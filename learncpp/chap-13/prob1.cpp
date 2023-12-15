#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;


class Point2d{

private:
 double m_x, m_y;

public:

 Point2d():m_x{0},m_y{0}{};
 Point2d(double x, double y):m_x {x}, m_y{y}{};
 void print(){ cout << "Point2d( "<< m_x << ", " << m_y << ")" << endl;}
 double getx(){return m_x;};
 double gety(){return m_y;};
 double distanceTo(Point2d &p2){

    return sqrt( (p2.getx()-m_x)*(p2.getx()-m_x)+(p2.gety()-m_y)*(p2.gety()-m_y) );
 }
 friend double distanceFrom(Point2d &p1, Point2d &p2);

 ~Point2d(){};

};
  double distanceFrom(Point2d &p1, Point2d &p2)
 {
    return sqrt( (p2.getx()-p1.getx())*(p2.getx()-p1.getx())+(p2.gety()-p1.gety())*(p2.gety()-p1.gety())) ;

 }
int main(){

    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

}