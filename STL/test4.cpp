#include "Array.h"
#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
// class template

void display(const std::vector<int> &vec) {
  cout << "[ ";
  for (auto v : vec) {
    cout << v << " ";
  }
  cout << "]" << endl;
}

void square(int &x) { x = x * x; }

class Person {

private:
  int age;
  string name;

public:
  Person() = default; // default cons
  Person(string name, int age) : name{name}, age{age} {}
  bool operator<(const Person &rhs) { return this->age < rhs.age; }
  bool operator==(const Person &rhs) {
    return (this->age == rhs.age && this->name == rhs.name);
  }
  ~Person(){};
};

int main() {

  typedef std::vector<int> v_int;

  v_int v1{1, 1, 2, 20, 1, 45, 2, 66, 8, 90};

  int num =
      std::count_if(v1.begin(), v1.end(), [](int x) { return x % 2 == 0; });
  cout << num << endl;

  cout << "-----------1-----------" << endl;
  display(v1);
  std::replace(v1.begin(), v1.end(), 1, 57);
  display(v1);

  cout << "-----------2-----------" << endl;

  return 0;
}
