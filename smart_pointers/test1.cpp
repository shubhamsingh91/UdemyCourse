#include <stdio.h>
#include <iostream>
#include <memory>
#include "Base.h"
#include "Derived.h"
#include<vector>

//--- Session on unique_ptrs------------//

using namespace std;

template <typename T>
void print(const T &var){
  std::cout << var << std::endl;
}


template <typename T1, typename T2>
void print(const T1 &var1, const T2& var2){
  std::cout << var1 << " " << var2 << std::endl;
}


int main()
{
   
   std::unique_ptr<int> p1 { new int {100}}; // initializing a pointer
   
   cout << *p1 << endl;
   *p1 = 200;
   cout << *p1 << endl;

   std::cout << p1.get() << endl; // returns pointer
    
  //  std::unique_ptr<int> p6 {p1.get()};
  //  print(*p6); 
   print("resetting p1");
   p1.reset();  // re-sets the pointer to null pointer
  //  print(*p1);

   cout << "-----1------" << endl;

   std::unique_ptr<Base> p2 {new Base(10)};
   cout << p2->get_num() << endl;
   cout << p2->get_num2() << endl;
   print("raw pointer for p2 = ", p2.get());

    cout << "-----2------" << endl;
    
    std::unique_ptr<int> p3 = make_unique<int> (200); // no new keyword needed 
    cout << *p3 << endl;
    
    std::unique_ptr<Derived> p_der_1 = make_unique<Derived>();

    Derived d1{12,14};
    // std::unique_ptr<Derived> p_der_2 {&(d1)}; // not allowed- smart pointers can't manage automatic variables

    std::unique_ptr<Base>p4 = make_unique<Base>(12,23);

    cout << p4->get_num() << endl;
    cout << p4->get_num2() << endl;
    // print(p4.release()); // returns the raw pointer to the object, and releases the ownership
    // print(p4->get_name()); // not allowed since the ownership is released

    auto p5 = make_unique<Derived>(2,1);

    cout << p5->get_num() << endl;
    cout << p5->get_num2() << endl;

    cout << "-----3------" << endl;
    p4 = std::move(p2); // data of p2 moved to p4, p2 is empty now, p4 owns data of p2 now
    cout << p4->get_num() << endl;
    cout << p4->get_num2() << endl;
    if (!p2)
      std::cout << "p2 is null" << endl;

    std::unique_ptr<Base> p6 {std::move(p4)};
    print(p6->get_name());
    
    // std::unique_ptr<Base> p7{p6}; // not allowed, two uni ptrs can't manage the same object

  //   cout << "-----4------" << endl;
    
    std::vector<std::unique_ptr<Base>> vec1;
    
    vec1.push_back(make_unique<Base>(3,4));
    vec1.push_back(make_unique<Base>(12,2));
    vec1.push_back(make_unique<Derived>(1,4));
    
    for (auto &v:vec1){ // need reference here, or else copies- cant do copy, can only move
        std::cout << v->get_num() << endl;
        std::cout << v->get_num2() << endl;

    }
 
    cout << "-----5------" << endl;

    std::vector <std::unique_ptr<Derived>> vec_der;

    vec_der.push_back(make_unique<Derived>(1,2));
    vec_der.push_back(make_unique<Derived>());

    for (auto &c : vec_der){
      print(c->get_num2());
    }
    




    return 0;
}