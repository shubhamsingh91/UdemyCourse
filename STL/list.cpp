#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

using namespace std;

class Person {

public:
  int age;
  string name;

public:
  Person() : name{"Unknown"}, age{0} {};
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

  std::list<int> l1{1, 2, 3, 4, 5};

  cout << l1.size() << endl;
  cout << l1.front() << endl;
  cout << l1.back() << endl;
  l1.push_front(34);
  l1.push_back(45);
  display_any(l1);

  cout << "---------1-----------" << endl;
  l1.resize(15);
  display_any(l1);
  l1.resize(5);
  display_any(l1);

  cout << "---------2-----------" << endl;

  std::list<Person> l2(5);
  display_any(l2);
  l2.resize(10);
  display_any(l2);

  cout << "---------3-----------" << endl;

  display_any(l1);
  auto it = std::find(l1.begin(), l1.end(), 2);
  cout << "*it = " << *it << endl;
  l1.insert(it, 100);
  display_any(l1);
  cout << "*it = " << *it << endl;

  std::advance(it, 1);
  // it++;
  cout << "*it = " << *it << endl;
  l1.erase(it);
  display_any(l1); // 3 is erased

  cout << "---------4-----------" << endl;
  std::list<Person> stooges;

  std::string name;
  int age;

  cout << "Enter the name:" << endl;
  getline(cin, name);
  cout << "Enter age:" << endl;
  cin >> age;

  stooges.emplace_back(name, age);
  display_any(stooges);

  auto it1 = std::find(stooges.begin(), stooges.end(), Person("mark", 23));
  stooges.emplace(it1, "John", 43);
  display_any(stooges);

  // std::sort(stooges.begin(), stooges.end()); // didnt work
  stooges.sort();

  display_any(stooges);

  return 0;
}
