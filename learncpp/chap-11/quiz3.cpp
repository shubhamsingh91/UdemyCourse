#include <iostream>
using namespace std;
// templates

template <typename T>
class Triad{
    public:
      T first;
      T second;
      T third;
};

template <typename T>
void print(const Triad<T> &t){
    std::cout << "[" << t.first << ", " << t.second << ", "<< t.third << "]";
}

int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}