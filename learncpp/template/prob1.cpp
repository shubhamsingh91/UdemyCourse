#include <iostream>
#include "../../utils.h"
#include <string>

template <typename T>
class Pair1 {
  private:
   T f,s;
  
  public:
   Pair1(T f, T s):f{f},s{s}{};
   T first()const {return f;};
   T second()const {return s;}

   ~Pair1(){};

};

template <typename T, typename U>
class Pair {
  private:
   T f;
   U s;
  
  public:
   Pair(T f, U s):f{f},s{s}{};
   T first()const {return f;};
   U second()const {return s;}

   ~Pair(){};

};

template <typename T>
class StringValuePair : public Pair<std::string,T> {
  private:

  public:
    StringValuePair(std::string str, T s):Pair<std::string,T>{str,s}{};
    ~StringValuePair(){};


};

int main() {
    
	Pair1<int> p1 { 5, 8 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2 { 2.3, 4.5 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	Pair<int, double> p3 { 5, 6.7 };
	std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

	const Pair<double, int> p4 { 2.3, 4 };
	std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

  StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}