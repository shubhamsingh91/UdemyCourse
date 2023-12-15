#include "Array.h"
#include <algorithm>
#include <array>
#include <cctype>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
template <typename T> void display_any(const T &v) {
  cout << "[ ";
  for (auto c : v) {
    cout << c << " ";
  }
  cout << "]" << endl;
}

int main() {

  std::deque<int> d1{1, 2, 3, 4, 5};
  std::deque<int> d2(10, 100);

  std::cout << d1.front() << endl;
  std::cout << d1.back() << endl;
  d1.push_front(45); // adding to front
  d1.push_back(56);

  cout << d1.front() << endl;
  std::cout << d1.back() << endl;

  display_any(d1);
  display_any(d2);

  std::copy(d1.begin(), d1.end(), std::front_inserter(d2));

  display_any(d2);

  return 0;
}