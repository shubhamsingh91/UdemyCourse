#ifndef _INTPAIR_H_
#define _INTPAIR_H_

class IntPair{

private:
 int num1,num2;
 protected:
 int num3;

public:

IntPair(){}  // default constructor
IntPair(int n1, int n2): num1{n1},num2{n2}{}
void set(int n1, int n2,int n3){num1=n1;num2=n2; num3=n3;}
void print(){std::cout << "num1 =" << num1 << std::endl;
std::cout << "num2 = " << num2 << std::endl; 
std::cout << "num3 = " << num3 << std::endl;}
~IntPair(){}

};



#endif