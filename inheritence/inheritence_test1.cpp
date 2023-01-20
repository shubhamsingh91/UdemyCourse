#include<iostream>
#include<stdio.h>

using namespace std;

class Base{

public:

int a{0};
void display(){ std::cout<< "a =" << a <<" b= " <<b << " c=" << c << std::endl;}

protected:

int b{0};

private:

int c{0};

};

class Derived : public Base{

public:
int d{0};

    void access_base_numbers() {a = 150; b = 200; } // cannot access c here, since c is private in base, not accessible here

private:

};

int main()
{

Base base;

base.a = 100;
base.display();
//base.b = 60;

Derived derived;
derived.access_base_numbers();
derived.display();


}