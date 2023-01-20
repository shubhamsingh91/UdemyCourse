#include<stdio.h>
#include<iostream>
using namespace std;

class Dog
{

 private:

    string name;
    int age;

 public:

    Dog(); // original constructor
    Dog(string name_val, int age_val); // 2 arg constructor
    Dog(const Dog &source); // copy constructor
    void set_name(string str_name);
    string get_name();
    void set_age(int age_in);
    int get_age();
    int get_human_years();
    void speak();

};

    Dog::Dog()
        : name {"None"}, age {0}   
    {
        cout << "Default dog constructor called! " << endl;
    }

    Dog::Dog(string name_val, int age_val)
     : name {name_val}, age {age_val}
    { 
        cout << "2 args Dog constructor called! " << endl;
    }

    // copy- constructor
    Dog::Dog(const Dog &source)
        :name {source.name}, age{source.age}
        {
            cout << "copy constructor called!" << endl;
        }

    void Dog::set_name(string str_name)
    {
        name = str_name;
    }

    string Dog::get_name()
    {
        return name;
    }

    void Dog::set_age(int age_in)
    {
        age = age_in;
    }
    
    int Dog:: get_age()
    {
        return age;
    }

    int Dog::get_human_years()
    {
        return age*7;
    }

    void Dog::speak()
    {
        cout << "Woof" << endl;
    }