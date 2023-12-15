#include "base.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

  base<int> b1(56);
  cout << "b1.num1 = " << b1.get_num1() << endl;

  base<double> b2(23.1);
  cout << "b2.num1 = " << b2.get_num1() << endl;

  return 0;
}