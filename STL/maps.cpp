#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

template <typename T1, typename T2>
void display_any(const std::map<T1, T2> &m) {
  cout << "[ ";
  for (const auto &c : m) {
    cout << c.first << " " << c.second << " ";
  }
  cout << "]" << endl;
}

int main() {

  std::map<std::string, int> m1{{"Moe", 3}, {"Larry", 2}, {"Moe", 1}};
  display_any(m1);

  m1.insert(std::make_pair("Frank", 32));
  display_any(m1);

  cout << m1["Frank"] << endl;
  m1["Moe"] = 56;
  display_any(m1);
  m1.erase("Frank");
  display_any(m1);

  auto it = m1.find("Moe");
  cout << it->first << it->second << endl;

  cout << "------1------------" << endl;

  std::map<std::string, std::set<int>> grades{
      {"Moe", {100, 90}}, {"Frank", {56, 78}}, {"James", {90, 100}}};

  grades["Moe"].insert(67);

  return 0;
}