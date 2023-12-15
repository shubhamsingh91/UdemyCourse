#include <iostream>
#include "stdio.h"
#include "parkinglot.hpp"

using namespace std;

int main(){


Parkinglot p;

cout << "remaining spots are = " << p.getspots() << endl;
cout << "car spots are = " << p.getcarspots() << endl;

}