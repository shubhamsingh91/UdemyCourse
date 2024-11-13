#include <iostream>
#include <stdio.h>
#include "../utils.h"

using namespace std;

class Base{

 private: 
    int val1;

 public:
  Base(); 
  Base(int z);
  Base(const Base &obj); // copy constructor   
  ~Base();

   void increment_val(int z){
    print("incrementing val");
    val1+=z;};

   void get_val(){print("val1 = ",val1);};

 };

 Base::Base(){
    cout << "base no args constructor!" << endl;
 }

 Base::Base(const Base &obj): val1{obj.val1} {
    cout << "base copy constructor called!" << endl;
 }

 Base::Base(int z) : val1{z}
 {
    cout <<"base single arg constructor!" << endl;
 }

 Base::~Base(){}


class Derived : public Base
{
    private:
        int val2;

    public:

        Derived(): Base{0}, val2{0} {print("Derived no args constructor!");};
        
        Derived(const Derived &obj): val2{obj.val2}, Base{obj}
        {
            cout << "Derived copy constructor called!" << endl;
        }

        Derived(int z): Base{z+12}, val2{z}{ cout << "derived single args constructor!" << endl;};


        void increment_val(int z)
        {
            val2+=z;
            Base::increment_val(val2); // to call base class methods in derived class
        };

        void get_val(){
            print("val2 = ", val2);
            Base::get_val();
        }

        ~Derived(){};

};


int main()
{

    Base b1;
    Base b2 {34};

    b2.get_val();

    print("-----------------------------");

    Base b3{b2};
    print("b3 val = ");
    b3.get_val();
    b3.increment_val(12);
    b3.get_val();

    print("----Derived class test-----------");

    Derived d1;

    d1.get_val();
    d1.increment_val(13);
    d1.Base::increment_val(15);

    d1.get_val();

    print("d2 params");
    Derived d2{98};
    d2.get_val();

    print("----------- Second derived test----");
    print("d3 params");
    Derived d3{d2};
    d3.get_val();

    print("------------Deleting objects-------------------");

    //  d1.increment_val(4);

    // Derived d2{d1};

}
