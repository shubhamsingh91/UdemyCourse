#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// using virtual functions here
class Fruit{

private:
  std::string name;  

public:
 
 Fruit(){};
 Fruit(string n):name{n}{};

 virtual void eat(){};
 void print_name(){cout << name << endl;};
 void set_name(string s){name = s;};

 virtual ~Fruit(){} ;

};

class Apple : public Fruit{

 public:
 virtual void eat(){
    int num1=1;
    num1+=1;
 }

};

class Banana : public Fruit{
 public:
 virtual void eat(){cout << "Eating Banana! " << endl;}
};

int main(){
    string s1 {"Jack"};

    Fruit *A = new Apple();
    A->set_name(s1);
    A->print_name();
    A->eat();

    Fruit *B = new Banana();
    B->set_name("Queen");
    B->print_name();
    B->eat();

   vector<Fruit *> v1;
   v1.resize(10000);
   
   for (int i=0; i<10000;i++){
    v1.push_back(new Apple());
   }
    
   auto start_time = std::chrono::high_resolution_clock::now();

   for (auto c: v1){
  
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> fp_ms =  end_time - start_time;
    
    std::cout << "duration = " << fp_ms.count() << std::endl;



return 0;

}