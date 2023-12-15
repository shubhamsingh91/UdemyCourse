#ifndef _displayer_H_
#define _displayer_H_
#include<iostream>
#include<stdio.h>
using namespace std;

template <typename T>
struct Displayer{

void operator() (const T &data){
    std::cout << data << "" << std::endl;
}

};



#endif