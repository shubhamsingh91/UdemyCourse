#ifndef _PAIR1_H_
#define _PAIR1_H_

template<typename T>
class Pair1
{
public:
	T f;
	T s;
	Pair1(T x, T y)
		: f{ x }, s{ y }{}

T first() const {return f;} // getters should be const in general, or wont work with const object
T second()const {return s;}

	
};

#endif