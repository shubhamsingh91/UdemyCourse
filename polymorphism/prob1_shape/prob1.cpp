#include <stdio.h>
#include <iostream>
#include <string>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

int main(){

  Circle c1{3,false};
  cout << "c1.area = "  << c1.getArea() << endl;
  cout << "c1.perimeter = "  << c1.getPerimeter() << endl;

  Circle c2{3,true};
  cout << "c2.area = "  << c2.getArea() << endl;
  cout << "c2.perimeter = "  << c2.getPerimeter() << endl;


  Rectangle r1(4,5,false);
 
  cout << "r1.area = "  << r1.getArea() << endl;
  cout << "r1.perimeter = "  << r1.getPerimeter() << endl;

   Rectangle r2(4,5,true);

    cout << "r2.area = "  << r2.getArea() << endl;
  cout << "r2.perimeter = "  << r2.getPerimeter() << endl;

   Triangle t1(3,4,false);

    cout << "t1.area = "  << t1.getArea() << endl;
    cout << "t1.perimeter = "  << t1.getPerimeter() << endl;

  Triangle t2(3,4,true);

    cout << "t2.area = "  << t2.getArea() << endl;
    cout << "t2.perimeter = "  << t2.getPerimeter() << endl;


    return 0;
}