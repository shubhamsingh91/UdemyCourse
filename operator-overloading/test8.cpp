#include <iostream>
#include "../utils.h"


class Base{
  
  private:
   int m;
   float f;

  public:
   Base(int n, float a): m{n}, f{a}{::print("2 arg cons!");};
   Base(Base &obj){ // copy constructor
      ::print("copy cons!");
      if (&obj != this) {
        this->m = obj.m;
        this->f = obj.f;
      }  
   }
   Base (Base && obj) noexcept :m{obj.m},f{obj.f}{ // move constructor
      ::print("move cons!");
      obj.m = 0;
      obj.f = 0.0;
   }

   friend std::ostream & operator<< (std::ostream& out, const Base& obj);
    Base operator+(const Base& obj) {
        return Base(this->m + obj.m,this->f + obj.f);
    }
    Base operator-(const Base& obj) {
        return Base(this->m - obj.m,this->f - obj.f);
    }
    Base& operator=(const Base& obj) {
        if (this != &obj) {
          this->m = obj.m;
          this->f = obj.f;
        }
        return *this;
    }
    Base operator*(const Base& obj) {
        return Base(this->m*obj.m, this->f*obj.f);
    }
    bool operator==(const Base& obj) {
        return ((this->m == obj.m) && (this->f == obj.f));
    }

    bool operator!=(const Base& obj) {
        return !((this->m == obj.m) && (this->f == obj.f));
    }

    void print() {
        ::print("m = ", this->m);
        ::print("f = ", this->f);
    }

   ~Base(){}; 

};

std::ostream & operator<< (std::ostream& out, const Base& obj) {
    out << "m = " << obj.m << ": f = " << obj.f << std::endl;
    return out;
}

Base createBase(int m, float f) {
    return Base(m,f);
}

int main() {

    Base b1{23,45.1};
    b1.print();

    Base b2{b1};
    b2.print();

    Base b3 {b1+b2};
    b3.print();

    Base b4 = b2;
    print("&b4 = ", &b4);
    print("&b2 = ", &b2);
    print("&b1 = ", &b1);

    print(b1);

    Base b5{b1-b3};
    print(b5);

    Base b6 {b1*b3*b5};
    print(b6);

    print(b1 == b2);
    print(b2 != b6);

    Base {Base(4,5.6)};

    Base b7 {std::move(b6)};
    
    print("-----------------------------");

    Base b8 =createBase(23,1.5);

    return 0;
}