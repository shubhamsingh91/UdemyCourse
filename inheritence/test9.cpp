#include <iostream>
#include "../utils.h"

class Base{
 
 private:
  const int m {0};
 
 public:
  Base(){};
  Base(const int n):m{n}{};
  virtual void print_m(){print(m);};

  ~Base(){};

};

class Derived : public Base{
 
 private:
  float f {0.5};

 public:
  Derived():f{1.6}{};
  Derived(float g):f{g} {};
  void print_m() override {print(f);}
  virtual ~Derived(){};

};

int main() {

     Base b(45);
     b.print_m();

     Base c{56};
     c.print_m();

     Derived d1{65.6};
     d1.print_m();

     Derived d2;
     d2.print_m();

     Base *p1 = new Derived();
     p1->print_m();

    Derived *p2 = new Derived(67.2);
    p2->print_m();

    Base *p3 {dynamic_cast<Base*>(p2)};
    p3->print_m();

}