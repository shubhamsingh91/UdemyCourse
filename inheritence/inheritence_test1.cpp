#include<iostream>
#include<stdio.h>
#include "../utils.h"

using namespace std;

class Base{

public:
    
    int a{0};
    void display(){ std::cout<< "a =" << a <<" b= " <<b << " c=" << c << std::endl;}
    void set_a(int n){a = n;}
    void set_b(int n){b = n; print("base class set_b");}
    void set_c(int n){c = n;};

protected:
    int b{0};

private:
    int c{0};

};

class Derived : public Base{

public:
    int d{0};
    void access_base_numbers() {a = 150; b = 200; } // cannot access c here, since c is private in base, not accessible here
    
    void set_b(int n)
    {b=n;
        print("Using derived class set_b");
    };

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

    print("---------New set-----------------");

    Base b1;

    b1.set_a(34);
    b1.set_b(214);
    b1.display();

    Derived d1;

    d1.set_a(78);
    d1.display();
    d1.Base::set_b(914);
    d1.Base::display();

    d1.set_b(45);
    d1.display();
    d1.Base::set_b(67);
    d1.display();




}