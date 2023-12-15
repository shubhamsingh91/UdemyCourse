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

void display(const std::array<int, 5> &arr) {
  cout << "[ ";
  for (auto &c : arr) {
    cout << c << " ";
  }
  cout << "]" << endl;
}

int main() {

  typedef std::array<int, 5> arr_int;

  arr_int arr1{1, 2, 3, 4, 5};
  arr_int arr2;

  display(arr1);
  display(arr2);

  arr2 = {10, 20, 30, 40, 50};
  display(arr2);
  arr1[0] = 45;
  arr1.at(3) = 78;
  display(arr1);

  cout << "front of arr1 = " << arr1.front() << endl;
  cout << "back of arr2 = " << arr2.back() << endl;
  cout << "swapping arrays" << endl;
  arr1.swap(arr2);
  display(arr1);
  display(arr2);

  if (arr1.empty())
    cout << "arr1 empty!" << endl;

  cout << "-------1-------------" << endl;
  int *ptr = arr1.data();

  cout << "ptr = " << ptr << endl;
  cout << "ptr = " << *ptr << endl;
  cout << "ptr = " << ptr[2] << endl;

  cout << "-------2-------------" << endl;

  std::sort(arr2.begin(), arr2.end());
  display(arr2);

  cout << "min of arr2 = " << *(std::min_element(arr2.begin(), arr2.end()))
       << endl;
  cout << "max of arr2 = " << *(std::max_element(arr2.begin(), arr2.end()))
       << endl;

  cout << "accumulate of arr2 = "
       << std::accumulate(arr2.begin(), arr2.end(), 0) << endl;
  return 0;
}
