#include "Base.h"
#include "Derived.h"
#include <iostream>
#include <memory>
#include <stdio.h>
#include <vector>
#include "../utils.h"

//----- practice on shared_ptr -------------------//

using namespace std;

std::shared_ptr<double> func(std::shared_ptr<double> ptr) { // passing by value- ptr copied
  std::shared_ptr<double> ptr1 {ptr};
  
  print("ptr1 use count = ", ptr1.use_count());
  cout << "ptr.use_count() = " << ptr.use_count() << endl;

  print("ptr get = ", ptr.get());
  print("ptr1 get = ", ptr1.get());

  return ptr1;
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

  print("------------- Double free error test----");
  std::shared_ptr<int> p1_1{p2}; // bad practice since both will try to delete the raw pointer- double deletion problem
  print("p3 ref count = ",p1_1.use_count());
  print("p2 ref count = ", p2.use_count());
  print("p2 raw pointer = ", p2.get());
  print("p3 raw pointer = ", p1_1.get());

  cout << "----1----" << endl;
  p1.reset();
  cout << p1.use_count() << endl;
  cout << p2.use_count() << endl;

  cout << "----2----" << endl;
  p2.reset();
  cout << p1.use_count() << endl;
  cout << p2.use_count() << endl;
  print("p1_1 ref count = ", p1_1.use_count());

  cout << "----3----" << endl;

  std::shared_ptr<Base> p3{new Base(33)};
  cout << p3->get_num() << endl;
  cout << p3.use_count() << endl;

  std::shared_ptr<Base> p4{p3};
  cout << p4->get_num() << endl;
  cout << p3.use_count() << endl;

  std::shared_ptr<Base> p4_1 {make_shared<Base>(14,17)};
  print(p4_1->get_name());
  print(p4_1->get_num2());
  print(p4_1.get());

  cout << "----4----" << endl;
  auto p5 = std::make_shared<double>(65.3);
  std::shared_ptr<double> p6{p5};
  std::shared_ptr<double> p7{p6};

  print("p5.get() = ", p5.get());
  print("p6.get() = ", p6.get());
  
  std::shared_ptr<double> p8 {func(p5)};
  print("p8 use count = ", p8.use_count());

  print("p8.get() = ", p8.get());

  print("-----------------------------");

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
  std::shared_ptr<Base> p9 = std::make_shared<Base>(5, 3);
  std::shared_ptr<Base> p10{
      new Base(5, 6),
      my_deleter}; // my_deleter is used here to delete the shared ptr


  std::shared_ptr<Derived> p11 {new Derived(10,17), [](Derived *ptr){
    print("inside custom lambda deleter");
    }};

    print("p11 use_count = ", p11.use_count());
    print("p11 name = ",p11->get_name());

  auto lambda1 = [](Base *ptr){print("lambda function-1"); delete ptr;};

  // std::shared_ptr<Base> p9{new Base(56, 3), [](Base *ptr) {
  //                            cout << "inside lambda custom deleter" << endl;
  //                            delete ptr;
  //                          }};

  std::shared_ptr<Base> p12 {new Base{122,14}, lambda1};

  return 0;
}