#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>

using namespace std;

int calc_area(int l=10); // with default argument
double calc_area(double l, double w);

// testing overloading functions


int main()
{

    cout << "area of a square is " << calc_area() << endl;
    cout << "area of a square with side 4 is" << calc_area(4) << endl;
       cout << "area of a rectangle with l=2.3, w= 6.7 is" << calc_area(2.3,6.7) << endl;
 

}

int calc_area(int l)
{

    return l*l;

}


double calc_area(double l, double w)
{

    return l*w;

}
