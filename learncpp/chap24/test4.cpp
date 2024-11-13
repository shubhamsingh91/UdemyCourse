#include <iostream>
#include "../../utils.h"
#include <iostream>

class Base
{
protected:
	int m_x {};
public:
	Base(int x): m_x{ x }
	{
		std::cout << "Base()\n";
	}
	~Base()
	{
		std::cout << "~Base()\n";
	}

	void print() const { std::cout << "Base: " << m_x << '\n';  }
};

class Derived: public Base
{
public:
	Derived(int y):  Base{ y }
	{
		std::cout << "Derived()\n";
	}
	~Derived()
	{
		std::cout << "~Derived()\n";
	}

	void print() const { std::cout << "Derived: " << m_x << '\n'; }
};

class D2 : public Derived
{
public:
	D2(int z): Derived{ z }
	{
		std::cout << "D2()\n";
	}
	~D2()
	{
		std::cout << "~D2()\n";
	}
    void print_mx(){
        std::cout << m_x << std::endl;
    }

        // note: no print() function here
};


class Address{

    public:
     std::string str;
     ~Address(){};
};

class Age{

    public:
     uint age;
     ~Age(){};
};


class Height{

    public:
     float h;
     ~Height(){};
};

class Person: public Address, public Age, public Height{
     
};

int main() {

    Person p;
    p.Address::str = "home";
    p.Age::age = 43;
    p.Height::h = 167;

    D2 d{12};

}

