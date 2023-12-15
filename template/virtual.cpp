#include <stdio.h>
#include <iostream>
#include <string>

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
 virtual void eat(){cout << "Eating Apple! " << endl;}

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




return 0;

}