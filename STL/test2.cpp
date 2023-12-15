#include "Array.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
// class template

template <typename T1, typename T2> struct my_pair {
  T1 first;
  T2 second;
};

int main() {

  my_pair<int, double> p1{45, 396.6}; // object initialized with two inputs

  cout << p1.first << ", " << p1.second << endl;

  int arr[4]{45, 4, 5, 6}; // initializing array of 4 integers
  cout << arr[0] << arr[1] << arr[2] << endl;

  cout << "----------1--------" << endl;

  Array<int, 5> a1(6);
  cout << a1 << endl;
  a1.fill(56);
  cout << a1 << endl;

  Array<int, 10> a2;
  cout << a2.get_size() << endl;
  a2.fill(12);
  cout << a2 << endl;

  cout << "----------2--------" << endl;

  std::array<int, 5> a3; // std::array
  a3.fill(12);
  cout << a3[0] << endl;

  std::array<int, 5> a6 = std::move(a3);
  cout << a3.size() << endl;
  cout << a6.size() << endl;
  cout << a3[0] << endl;
  cout << a6[0] << endl;

  cout << "----------3--------" << endl;

  Array<double, 20> a4(23.3);
  cout << a4 << endl;

  Array<std::string, 5> a5{"Hello!"};
  a5[3] = "X";
  cout << a5 << endl;
  a5.fill("Y");
  cout << a5 << endl;

  return 0;
}
