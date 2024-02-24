#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// Simple example demonstrating CRTP class template use
// derived class is used as a template, but not decided which derived class is used here

template <typename derived>
class Fruit{

  private:
   std::string name;

  public:

    Fruit(){};
    Fruit(string n):name{n}{};

    void eat(){
        static_cast<derived*>(this)->eat(); // here base class can access the derived class function eat
    };

    void print_name(){cout << name << endl;};
    void set_name(string s){name = s;};

    ~Fruit(){} ;
    

};

class Apple : public Fruit<Apple> {

public:
  void eat(){//cout << "Eating Apple!" << endl;}
    int num1=1;
    num1+=1;
  }
};

class Banana : public Fruit<Banana> {
 public:
   void eat(){cout << "Eating Banana! " << endl;}

};


int main(){
   
   Fruit<Apple> A;
   A.set_name("Jack!");
   A.print_name();
   A.eat();

   Fruit<Banana> B;
   B.set_name("Queen!");
   B.print_name();
   B.eat();

   vector<Fruit<Apple>* > v1;
   v1.resize(10000);

    auto start_time = std::chrono::high_resolution_clock::now();

   for (auto c: v1){
    c->eat();
   }

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> fp_ms =  end_time - start_time;
    
    std::cout << "duration = " << fp_ms.count() << std::endl;

}

