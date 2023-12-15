#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

template <typename T> T *create_array(size_t size, T init_value) {
  T *p1 = new T[size];
  for (int i = 0; i < size; i++) {
    *(p1 + i) = init_value;
  }
  return p1;
}

int main() {

  int *p = create_array<int>(10, 2);

  cout << *p << endl;
  cout << *(p + 1) << endl;

  double *p2 = create_array(100, 23.1);
  cout << *(p2 + 23) << endl;

  delete[] p2;
  delete[] p;

  return 0;
}