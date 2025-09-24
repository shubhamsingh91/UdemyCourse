#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

template <typename T> void double_data(T *p) { *p = *p * 2; }
template <typename T> void swap(T *a, T *b) {
  T temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int t = 12;
  int *p1 = &t;

  cout << "t = " << t << endl;
  cout << "&t = " << &t << endl;
  cout << "*p1 = " << *p1 << endl;
  cout << "p1 = " << p1 << endl; // gives the address it stores
  cout << sizeof p1 << endl; // size of pointer

  std::cout<< "----------0-------------" << std::endl;
   
  double *p2{nullptr};
  cout << p2 << endl; // returns 0
  double d1{45.1};
  double d2{34.1};
  p2 = &d1;
  cout << p2 << endl;

  cout << sizeof p2 << endl;
  p2 = &d2;
  cout << p2 << endl;
  cout << *p2 << endl;

  *p2 = 12.3; // also chaanges the value of d2. this is essentially changing the
              // value stored at p2- i.e. d2

  cout << p2 << endl;
  cout << *p2 << endl;
  cout << d2 << endl;

  double low_temp{34.1};
  double high_temp{56.1};
  double *temp_ptr{&low_temp};
  cout << *temp_ptr << endl;
  temp_ptr = &high_temp;
  cout << *temp_ptr << endl;

  cout << "------1-------" << endl;

  string *str_ptr;
  string str1 = "James";
  str_ptr = &str1;
  cout << *str_ptr << endl;
  str1 = "Frank";
  cout << *str_ptr << endl;

  cout << "------2-------" << endl;

  std::vector<string> *ptr2;
  std::vector<string> stooges{"Larry", "Moe", "Curly"};
  ptr2 = &stooges;
  cout << ptr2->at(0) << endl;
  cout << ptr2->at(1) << endl;
  cout << ptr2->at(2) << endl;
  cout << (*ptr2).at(1) << endl; // first dereferecing and then using at

  for (auto s : *ptr2) {
    cout << s << endl;
  }

  cout << "------3-------" << endl;

  int *p3 = new int{45};
  cout << *p3 << endl;

  double db_arr[]{12.1, 23.3, 45.1};
  double *db_ptr{db_arr};

  cout << *db_ptr << endl;
  db_ptr++;
  cout << *db_ptr << endl;
  db_ptr++;
  cout << *db_ptr << endl;

  cout << "------4-------" << endl;
  char name[]{"shubham"};
  char *p5{&name[0]};
  char *p6{&name[4]};

  cout << p6 - p5 << endl;

  cout << "------5-------" << endl;
  double d3 = 10;
  cout << d3 << endl;
  double_data(&d3);

  cout << d3 << endl;

  int t2 = 12;
  cout << t2 << endl;
  double_data(&t2);
  cout << t2 << endl;
  cout << "------6-------" << endl;

  int t3 = 13;
  cout << " t2 = " << t2 << " t3 = " << t3 << endl;
  swap(&t2, &t3);

  cout << " t2 = " << t2 << " t3 = " << t3 << endl;

  return 0;
}