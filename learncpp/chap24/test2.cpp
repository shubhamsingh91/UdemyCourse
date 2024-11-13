#include <iostream>
#include "../../utils.h"
#include <string>
#include <string_view>

using namespace std;

class Base{
 private:
    int id;

 public:
    Base(int n = 0):id{n}{};
    int get_id(){return id;};

};

class Derived : public Base{
 
  private:
    double cost;
  
  public:
    Derived(double d = 0.0):cost{d}{};
    Derived(double d,int id):Base{id},cost{d}{};
    double get_cost(){return cost;};
};

int main(){

    Derived d1{34.1};
    print(d1.get_id());

    Derived d2{56.1,23};
    print(d2.get_id());


  return 0;
}