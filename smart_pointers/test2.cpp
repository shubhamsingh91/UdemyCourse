#include "Base.h"
#include "Derived.h"
#include <iostream>
#include <memory>
#include <stdio.h>
#include <vector>

using namespace std;

void func(std::shared_ptr<double> ptr) { // passing by value- ptr copied
  cout << "ptr.use_count() = " << ptr.use_count() << endl;
}

void my_deleter(Base *ptr) {
  cout << "in my_deleter" << endl;
  delete ptr;
}

int main() {

  std::shared_ptr<int> p1{new int{100}};

  cout << "*p1 = " << *p1 << endl;
  cout << p1.use_count() << endl;

  std::shared_ptr<int> p2{p1}; // copy constructor used
  cout << p1.use_count() << endl;
  cout << p2.use_count() << endl;

  cout << "----1----" << endl;
  p1.reset();
  cout << p1.use_count() << endl;
  cout << p2.use_count() << endl;

  cout << "----2----" << endl;
  p2.reset();
  cout << p1.use_count() << endl;
  cout << p2.use_count() << endl;

  cout << "----3----" << endl;

  std::shared_ptr<Base> p3{new Base(33)};
  cout << p3->get_num() << endl;
  cout << p3.use_count() << endl;

  std::shared_ptr<Base> p4{p3};
  cout << p4->get_num() << endl;
  cout << p3.use_count() << endl;

  cout << "----4----" << endl;
  auto p5 = std::make_shared<double>(65.3);
  std::shared_ptr<double> p6{p5};
  std::shared_ptr<double> p7;
  p7 = p5;
  func(p5);

  p5.reset();
  cout << "p5.use_count() = " << p5.use_count() << endl;
  cout << "p6.use_count() = " << p6.use_count() << endl;
  p6.reset();
  cout << "p6.use_count() = " << p6.use_count() << endl;
  cout << "p7.use_count() = " << p7.use_count() << endl;
  p7.reset();
  cout << "p7.use_count() = " << p7.use_count() << endl;

  cout << "----5----" << endl;
  // custom deleter
  //  std::shared_ptr<Base> p8 = std::make_shared<Base>(5, 3);
  std::shared_ptr<Base> p8{
      new Base(5, 6),
      my_deleter}; // my_deleter is used here to delete the shared ptr

  std::shared_ptr<Base> p9{new Base(56, 3), [](Base *ptr) {
                             cout << "inside lambda custom deleter" << endl;
                             delete ptr;
                           }};

  return 0;
}