
// This code is error prone- Trying to show the shallow copy is an issue here



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "dog.h"
#include "Account.h"
using namespace std;

class Shallow
{
private:
    int *data;


public:
  Shallow(int num_in);
  Shallow(const Shallow &source);
  void set_data_value(int num_in);
  int get_data_value();
  ~Shallow();

};


// constructors

Shallow::Shallow(int num_in)
{
    data = new int;
    *data = num_in;
    cout << "constructor called!" << endl;
}

// copy constructor

Shallow::Shallow(const Shallow &source)
    :data {source.data}
    {
        cout << "copy constructor called!" << endl;
    }

void Shallow::set_data_value(int num_in)
{

    *data = num_in;
}

int Shallow::get_data_value()
{
    return *data;
}

Shallow::~Shallow()
{
    delete data;
    cout << "Destructor called!" << endl;
}

void print_data_value(Shallow a);


int main()
{

 Shallow obj1 {100};
 
 print_data_value(obj1);
 
 Shallow obj2 {obj1};
 obj2.set_data_value(1000);

    
}

void print_data_value (Shallow a)
{
    cout << "data: " << a.get_data_value() << endl;
}
