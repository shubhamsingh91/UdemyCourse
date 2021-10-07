

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "dog.h"
#include "Account.h"
using namespace std;

class Deep
{
private:
    int *data;


public:
  Deep(int num_in);
  Deep(const Deep &source);
  Deep(Deep &&source) noexcept ; //Move constructor
  void set_data_value(int num_in);
  int get_data_value();
  ~Deep();

};

// constructors

Deep::Deep(int num_in)
{
    data = new int;
    *data = num_in;
    cout << "constructor called!" << endl;
}

// copy constructor

Deep::Deep(const Deep &source)
    :Deep {*source.data} // delegating construction to the original constructor
    {
        cout << "copy constructor - Deep copy!" << endl;
    }

// move constructor

Deep::Deep(Deep &&source) noexcept
    :data{source.data}{
        source.data = nullptr;
        cout << "Move constructor - Deep copy!" << endl;
    }

void Deep::set_data_value(int num_in)
{

    *data = num_in;
}

int Deep::get_data_value()
{
    return *data;
}

Deep::~Deep()
{
    delete data;
    cout << "Destructor called!" << endl;
}

void print_data_value(Deep a);


int main()
{

 Deep obj1 {100};
 vector <Deep> vec;

 vec.push_back(Deep{20}); // called rvalue directly here

 print_data_value(obj1);
 
 Deep obj2 {obj1};
 obj2.set_data_value(1000);

    
}

void print_data_value (Deep a)
{
    cout << "data: " << a.get_data_value() << endl;
}
