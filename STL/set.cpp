#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
class Person {

public:
  int age;
  string name;

public:
  Person() : name{"Unknown"}, age{0} {};
  Person(string name, int age) : name{name}, age{age} {}
  bool operator<(const Person &rhs) const { return this->age < rhs.age; }
  bool operator==(const Person &rhs) {
    return (this->age == rhs.age && this->name == rhs.name);
  }

  ~Person(){};
};
ostream &operator<<(std::ostream &os, const Person &p) {
  os << p.name << " " << p.age;
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

  std::set<int> s1{1, 1, 1, 1, 2,  3, 4,
                   5, 6, 2, 3, 67, 8}; // automatically sorted
  display_any(s1);

  s1.insert(0);
  display_any(s1);

  cout << s1.size() << endl;

  cout << s1.count(8) << endl;

  auto it = s1.find(4);
  cout << *it << endl;

  s1.clear();
  display_any(s1);

  cout << "---------1-----------" << endl;

  std::set<Person> s2{{"Moe", 45}, {"Larry", 23}, {"Frank", 78}};
  s2.emplace("Moe", 34);
  display_any(s2);

  auto it1 = s2.find(Person{"Frank", 78});
  s2.erase(it1);
  display_any(s2);

  auto result = s2.insert(Person{"Frank", 56});
  cout << *(result.first) << endl;
  cout << result.second << endl;

  return 0;
}