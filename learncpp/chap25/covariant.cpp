#include <iostream>
#include <stdio.h>
#include "../../utils.h"

class Base {

 public:
   virtual Base* getThis() {std::cout << "running base class getThis" << std::endl;
                    return this;}

   virtual void print() {std::cout << "print in base class" << std::endl;} 

};

class Derived : public Base {
  public:
  Derived *getThis() override {std::cout << "running derived class getThis" << std::endl;
            return this;};

   void print() override {std::cout << "print in derived class" << std::endl;} 

};

int main() {

    Derived d{};
    d.getThis()->print();

    Base *ptr{&d};
    ptr->getThis()->print();

}


