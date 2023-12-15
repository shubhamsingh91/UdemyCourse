#include "Array.h"
#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
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

class Person {

public:
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
ostream &operator<<(std::ostream &os, const Person &p) {
  os << p.name;
  return os;
}
template <typename T> void display_any(const T &v) {
  cout << "[ ";
  for (auto c : v) {
    cout << c << " ";
  }
  cout << "]" << endl;
}

int main() {

  typedef vector<int> v_int;

  v_int v1{1, 2, 3, 4};

  cout << "v1.front()" << v1.front() << endl; //
  cout << "v1.back()" << v1.back() << endl;   //

  v_int v2(50, 10);
  display(v2);

  cout << v2.capacity() << endl;
  cout << v2.size() << endl;

  v2.pop_back();
  cout << "removed last element" << endl;
  cout << v2.size() << endl;
  cout << v2.capacity() << endl;

  cout << "------1-------" << endl;

  auto it = std::find(v1.begin(), v1.end(), 3);
  v1.insert(it, v2.begin(), v2.end()); // inserting entIre v2 in v1
  display(v1);

  cout << "------2-------" << endl;
  std::vector<Person> vec_p{{"Larry", 50}, {"Moe", 56}, {"Harry", 34}};
  display_any(vec_p);

  cout << "------3-------" << endl;

  v_int v3{1, 2, 3, 4, 5, 6};
  v3.erase(v3.begin() + 3);
  display(v3);

  cout << "------4-------" << endl;
  v_int v4{3, 4, 5};

  display(v3);
  std::copy_if(v1.begin(), v1.end(), std::back_inserter(v3),
               [](int x) { return x % 2 == 0; });
  display(v3);

  cout << "------5-------" << endl;
  display(v3);
  display(v4);

  auto it1 = std::find(v3.begin(), v3.end(), 5);
  v3.insert(it1, v4.begin(), v4.end());
  display(v3);

  return 0;
}
