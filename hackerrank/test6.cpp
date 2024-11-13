#include <iostream>
#include "../utils.h"
#include <string>
#include <vector>

using namespace std;

class Base {

public:
  string m_name;
  Base(string n):m_name{n}{};
  virtual void get_name() { print("in Base");};
  ~Base(){};

};

class Derived : public Base{
  public:
   int num1;
   Derived(int n, string s):Base{s},num1{n}{};
   void get_name() override { print("in Derived");};
   ~Derived(){}; 

};

Base *get_ptr(bool check){
    if (check) {
        return new Derived{23,"test"};
    } else {
        return new Base{"test"};
    }
}

int main () {

    // std::string s {"1234"};

    // for (int i = 0; i < s.size(); i++) {
    //     print(s[i]);
    //     print(int(s[i])-int('0'));

    // }

    Base *ptr {get_ptr(true)};
    print(ptr->m_name);
    ptr->get_name();
    
    delete ptr;

    return 0;
}