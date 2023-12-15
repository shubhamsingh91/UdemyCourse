#include "Array.h"
#include <algorithm>
#include <array>
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

  v_int v1{1, 2, 31, 4, 5};
  v_int::iterator it = v1.begin();
  v_int::iterator it_e = v1.end();
  display(v1);

  v_int::const_iterator it1 = v1.begin();
  cout << *it1 << endl;
  it1++;
  cout << *it1 << endl;
  cout << "-----------0----------" << endl;

  auto loc = std::find(v1.begin(), v1.end(), 17);

  cout << *loc << endl;

  cout << "-----------1-----------" << endl;

  auto it2 = v1.rbegin(); // reverse iterator

  while (it2 != v1.rend()) {
    cout << *it2 << endl;
    it2++;
  }

  cout << "-----------2-----------" << endl;
  std::set<char> suits{'A', 'B', 'C', 'D'};
  std::set<char>::iterator itc;

  for (itc = suits.begin(); itc != suits.end(); itc++) {
    cout << *itc << endl;
  }
  cout << "-----------3-----------" << endl;

  std::list<std::string> name{"Larry", "Moe", "Curly"};
  auto it3 = name.crbegin();

  while (it3 != name.crend()) {
    cout << *it3 << endl;
    it3++;
  }
  cout << "-----------4-----------" << endl;

  v_int v2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto start = v2.cbegin() + 2;
  auto finish = v2.cend() - 4;

  while (start != finish) {
    cout << *start << endl;
    start++;
  }
  cout << "-----------5-----------" << endl;
  display(v2);
  std::for_each(v2.begin(), v2.end(),
                [](int &x) { x = x * x; }); // using lambda function on for_each
  display(v2);
  std::for_each(v2.begin(), v2.end(), square); // using function pointer
  display(v2);

  cout << "-----------6-----------" << endl;

  std::list<Person> players{{"Larry", 19}, {"Moe", 50}, {"Xi", 100}};

  auto loc1 = std::find(players.begin(), players.end(), Person("Xi", 10));
  if (loc1 != players.end())
    cout << "player found!" << endl;

  return 0;
}
