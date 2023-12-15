#ifndef _PAIR_H_
#define _PAIR_H_

template<typename T1, typename T2>
class Pair
{
public:
	T1 f;
	T2 s;
	Pair(T1 x, T2 y)
		: f{ x }, s{ y }{}

T1 first() const {return f;} // getters should be const in general, or wont work with const object
T2 second()const {return s;}

	
};

#endif