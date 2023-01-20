#include <iostream>
#include <stdio.h>

using namespace std;

// Testing polymorphism- static binding 

class Base
{
    public:
    void say_hello() const{
        cout << "Hello! I am a base object!" << endl;
    }
};

class Derived : public Base{

    public:
    void say_hello() const{
       cout << "Hello! I am a derived object!" << endl;

    }

};

void greetings(const Base &obj){

    cout << "Greetings! :" << endl;
    obj.say_hello();
}

int main()
{

    Base base1;
    greetings(base1);

    Derived der1;
     greetings(der1);

     Base *ptr = new Derived();
     ptr->say_hello();   

    delete ptr;

}