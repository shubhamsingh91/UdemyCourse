#include<iostream>
#include<stdio.h>
#include "displayer.h"
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

auto make_lambda1(int x){
    return [](int x){cout << x+12 << endl;};
}

auto make_lambda2(const int x){
    return [=](){cout << x+12 << endl;};
}

int main(){

  auto f = [](int x){cout << "x  =" << x << endl;};
  auto l1 = [](){cout << "Hello world!" << endl;};

  f(12);
  l1();

  auto l2 = [](int x, int y){cout <<"x+y+100 = "<< x+y+100 << endl;};
 
  l2(12,2);

  auto l3 {make_lambda1(15)};
  l3(12);

  auto l4 {make_lambda2(15)};
  l4();

  {
    int y {34};
    auto l5 = [=](){return y;};
    cout << l5() << endl;
  }




}