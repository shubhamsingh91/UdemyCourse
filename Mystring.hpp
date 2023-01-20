#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring{

private:
    char *str;

public:
    Mystring(); // no args constructor
    Mystring(const char*s); // one arg constructor
    Mystring(const Mystring &source); // copy constructor
    ~Mystring();
    void display() const; // constant function, cannot change the elements
    int get_length() const; //constant function, cannot change the elements
    const char* get_str() const; // returns the str
    
    // copy assignment operator
    Mystring &operator=(const Mystring &rhs); // overloaded assignment operator for Mystring class
    
    // move assignment operator
    Mystring &operator=(Mystring &&rhs); 

    // - operator unary operator
    Mystring operator-() const; // make lowercase version
    Mystring operator+(const Mystring &rhs) const; // concatenate strings here
    bool operator==(const Mystring &rhs) const; // 

};  

#endif