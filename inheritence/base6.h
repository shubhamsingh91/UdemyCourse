#ifndef _BASE6_H_
#define _BASE6_H_

#include <iostream>

class base6
{

private:
    int num1;
    float num2;
    
public:
  int num3;  
  base6() = default;
  base6(int n1, float n2, int n3, int n4);  
  void print();
  virtual int fun(const int x);
  void bar();

protected:
  int num4;

};


class derived6 : public base6{

 public:
   derived6() = default;
   derived6(int n1, float n2, int n3, int n4);
   int fun(const int x) override;
   void bar();


 private:

};

#endif