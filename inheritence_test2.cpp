#include <iostream>
#include <stdio.h>

using namespace std;

class Base{

private: 
    int val1;

public:
  Base(); 
  Base(int z);
  Base(const Base &obj); // copy constructor   
  ~Base();

   void increment_val(int z){val1+=z;};

};

 Base::Base()
{cout << "base no args constructor!" << endl;}

 Base::Base(const Base &obj)
 {val1 = obj.val1;
 cout << "base copy constructor called!" << endl;}



 Base::Base(int z)
{val1 = z; cout <<"base single arg constructor!" << endl;}

 Base::~Base()
{
    cout << "base class destructor!" << endl;
}


class Derived : public Base
{
  
    private:

        int val2;

    public:

    Derived():
        Base{}, val2{0}{cout<< "derived no args constructor!" << endl;}; // initializing val2 here, also calling Base class constructors here

    Derived(const Derived &obj):
        Base(obj) 
        {
            val2 = obj.val2;
            cout << "Derived copy constructor called!" << endl;
        }

    Derived(int z):
        Base{z}{val2 = z; cout << "derived single args constructor!" << endl;};

    ~Derived(){cout << "Derived destuctor!"<< endl;};

    void increment_val(int z)
    {
        val2+=z;
        Base::increment_val(val2);
    };



};


int main()
{

    Base b1 {100};
    b1.increment_val(5);

    Base b2{b1};

     Derived d1{56};

     d1.increment_val(4);

    Derived d2{d1};

}
