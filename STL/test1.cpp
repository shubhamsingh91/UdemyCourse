#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

// function templates

using namespace std;

template <typename T> T max_fun(const T a, const T b) {
  return (a > b) ? a : b;
}

struct Person {
  std::string name;
  int age;

  bool operator<(const Person &rhs) const { return (this->age < rhs.age); }
};

template <typename T1, typename T2> void func(T1 a, T2 b) {
  std::cout << a << " " << b << std::endl;
}
std::ostream &operator<<(std::ostream &os, const Person &p) {
  os << p.name;
  return os;
}

template <typename T> void my_swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

int main() {
  typedef vector<int> v; // alias
  v v1{1, 6, 5};
  sort(v1.begin(), v1.end());
  for (auto c : v1)
    cout << c << endl;

  cout << "max(5,6) = " << max(5, 6) << endl;
  cout << "max(12.1,648.1) = " << max(12.1, -648.1) << endl;
  cout << "max(A,C) = " << max('A', 'C') << endl;
  func(45, 2);

  Person p1{"Curly", 30};
  Person p2{"Moe", 40};
  cout << "p1<p2 = " << (p1 < p2) << endl;

  func(p1, p2);
  int x = 100;
  int y = 200;
  my_swap(x, y);

  cout << x << " " << y << endl;

  return 0;
}