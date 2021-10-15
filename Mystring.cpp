#include <cstring>
#include <iostream>
#include "Mystring.hpp"

Mystring::Mystring()
	:str{nullptr}
{
str= new char[1];
*str ='\0';

}


// argument constuctor

Mystring::Mystring(const char*s)
	:str{nullptr}
	{
		if (s==nullptr)
		{
			str = new char[1];
			*str = '\0';
		} else {

			str = new char[std::strlen(s)+1];
			std::strcpy(str,s);
		}
	}

// Copy constructor

Mystring::Mystring(const Mystring &source)
	:str {nullptr}{

	 str = new char[std::strlen(source.str)+1];
	 std::strcpy(str,source.str);   

}

// Destructor

Mystring::~Mystring()
{
	delete str;

}

//Display

void Mystring::display() const{
	std::cout << str << std::endl;
}

// length getter

int Mystring::get_length() const {
	return std::strlen(str);
}
// string getter

const char *Mystring::get_str() const{
	return str;
}

// copy Overloaded assignment operator

Mystring &Mystring::operator=(const Mystring &rhs)
{
	std::cout << "copy assignment!" << std::endl;

	if(this==&rhs) // This is the pointer to the current object
	{
		return *this;
	}

	delete [] this->str;

	str = new char[std::strlen(rhs.str)+1];
	std::strcpy(this->str,rhs.str);
	return *this;


}

// move Overloaded assignment operator

Mystring &Mystring::operator=(Mystring &&rhs)
{
	std::cout << "move assignment!" << std::endl;

	if(this==&rhs) // This is the pointer to the current object
	{
		return *this;
	}

	delete [] this->str;

	str = rhs.str;
	rhs.str=nullptr;
	return *this;


}

// comparison string

bool Mystring::operator==(const Mystring &rhs) const{
	return(std::strcmp(str,rhs.str)==0)
}

// Make lowercase