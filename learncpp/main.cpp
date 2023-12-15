#include<iostream>
#include "Intpair.hpp"
#include "Point3d.hpp"
#include "stack.hpp"

using std::cout;
using std::endl;

int main(){

    cout << "------------13.2---------------------" << endl;
	IntPair p1;
	p1.set(1, 1,4); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();
   
   cout << "------------13.3-----------------" << endl;
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

  Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }

     cout << "------------13.3---stack-----------" << endl;
    Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
    cout << "----" << endl;
	stack.print();
	stack.pop();
    cout << "----" << endl;

    stack.print();

	stack.pop();
	stack.pop();
    cout << "----" << endl;

	stack.print();
	//stack.pop(); // causes assertion error here

    return 0;
}