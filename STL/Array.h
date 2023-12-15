#ifndef _ARRAY_H_
#define _ARRAY_H

#include <iostream>
#include <stdio.h>
#include <vector>

template <typename T, int N> class Array {

private:
  int size{N};
  T values[N];
  friend std::ostream &operator<<(
      std::ostream &os,
      const Array<T, N> &arr) { // this can access the private/protected members
    os << "[";
    for (const auto &val : arr.values) {
      os << val << " ";
    }
    os << "]" << std::endl;

    return os;
  }

public:
  Array() { std::cout << "default constructor!" << std::endl; }
  Array(T init_value) {
    for (auto &item : values) {
      item = init_value;
    }
  }
  void fill(T val) {
    for (auto &item : values) {
      item = val;
    }
  }
  int get_size() const { return size; }

  T &operator[](int index) { return values[index]; }
  ~Array() {}
};

#endif