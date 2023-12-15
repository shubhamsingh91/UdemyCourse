#include <iostream>
#include <string>
#include "Apple.hpp"
#include "banana.hpp"
#include "GrannySmith.hpp"
#include "shape.hpp"
#include "triangle.hpp"
#include "Circle.hpp"
#include <vector>
#include "Pair1.hpp"
#include "Pair.hpp"
#include "StringValuePair.hpp"

using std::cout;
using std::endl;

int getlargestradius(vector<Shape*> &v){
 int rad=0;
   for (auto c:v){
    auto v1 = dynamic_cast<Circle*>(c);
    if (v1){
        cout << "Yes circle!" << endl;
        rad = v1->getRadius();
        cout << rad << endl;
    
    }
   }
   return rad;

}

int main(){

  cout << "------------17.4-----------" << endl;

  Apple ap("delicious","red",56);
  cout << ap << endl;

  cout << "------------17.7-----------" << endl;

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

    Apple a{ "red" };
	GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
 
 cout << "------- testing enumerator----------------" << endl;

    enum Gender { Male, Female, Nonbinary };
    Gender g = Nonbinary;
    cout << g << endl;

cout << "-----------18 final quiz------------------" << endl;
    Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
    std::cout << t << '\n';

 Circle c1{ Point{ 1, 2 }, 7 };
 std::cout << c1 << '\n';

cout << "-----------18 final quiz second part------------" << endl;

std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

  for(auto c:v){
    std::cout << *c << std::endl;
  }

  getlargestradius(v);
   
    for(auto c:v){
        delete c;
    }

cout << "-----------19 final quiz------------" << endl;
 
 Pair1<int> p1{5,8};
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

const Pair1<double> p2 { 2.3, 4.5 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

cout << "-----------19 final quiz--second part----------" << endl;
	Pair<int, double> p3 { 5, 6.7 };
	std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
const Pair<double, int> p4 { 2.3, 4 };
std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

}

