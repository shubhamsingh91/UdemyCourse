#ifndef _GrannySmith_H_
#define _GrannySmith_H_

#include<iostream>
#include<stdio.h>
#include <string>
#include "Apple.hpp"

using namespace std;

class GrannySmith: public Apple{
  using Apple::Apple; // to get the fruit constructurs here

    public:
    
 
    GrannySmith():Apple("granny smith","green"){}
    ~GrannySmith(){}

};

  

#endif