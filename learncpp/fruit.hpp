#ifndef _FRUIT_H_
#define _FRUIT_H_

#include<iostream>
#include<stdio.h>
#include <string>

using namespace std;

class fruit{
    private:

std::string name;
std::string color;

    public:

fruit(){}
fruit(string n):name{n}{}
fruit(string n, string c):name{n},color{c}{} // overloaded constr
string getName() const {return name;}
string getColor() const {return color;}


      
~fruit(){}

};



#endif