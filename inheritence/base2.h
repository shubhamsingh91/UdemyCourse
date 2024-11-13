#ifndef _BASE2H_
#define _BASE2H_
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


class base2
{
private:
    int num1;
protected:
    int num2;

public:
    int num3;
    std::string name;

    base2(std::string str="Nothing"):name{str},num1{0},num2{0},num3{0}{};
    base2(int x,int y, int z, std::string str="Nothing"):num1{x},num2{y},num3{z},name{str}{};
    base2(const base2& b2){ // copy constuctor
        num1=b2.num1;
        num2=b2.num2;
        num3=b2.num3;
        name=b2.name;
    }
    // base2 (base2&& b2){
    //     if
    // }
    virtual string get_name()  {
        std::cout << "base get_name-- ";
        return name;}
    int get_num1(){return num1;};
    int get_num2(){return num2;};
    int get_num3(){return num3;};
   
    virtual ~base2(){};
};












#endif