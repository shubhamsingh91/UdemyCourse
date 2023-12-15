#include <stdio.h>
#include <iostream>
#include <memory>
#include "Base.h"
#include "Derived.h"
#include<vector>

using namespace std;

void base_deleter(Base *ptr){
    std::cout << "custom deleting Base" << std::endl;
    delete ptr;
}

int main(){

  std::unique_ptr<int> p1 {new int {100}};
  cout << *p1 << endl;
  cout << p1.get() << endl;  // getting the value of unique ptr
  
  cout << "----------1-----------" << endl;

  std::unique_ptr<Base> p2 {new Base(12)};
  cout << p2->get_num() << endl;
  cout << p2->get_name() << endl;
    
  cout << "----------2-----------" << endl;
  auto p3 = make_unique<Base>(14);
  p3->set_num(11);
  cout << p3->get_name() << endl;
  cout << p3->get_num2() << endl;
  cout << p3->get_num() << endl;

   cout << "----------3-----------" << endl;
  auto p4 = make_unique<Derived>(12,1);
  cout << p4->get_num() << endl;
  double x=1.5;
  cout <<  p4->squared_fun(x) << endl;


   cout << "----------4-----------" << endl;
   shared_ptr<double> p5 {new double {12.5}};
   cout <<  *p5 << endl;
   cout << p5.use_count() << endl;
   shared_ptr<double> p6(p5);
   cout << p5.use_count() << endl;

   cout << "----------5-----------" << endl;
   p5.reset();
   cout << p5.use_count() << endl;
   shared_ptr<double> p7(p6);

   cout << p6.use_count() << endl;
   cout << p7.use_count() << endl;

    cout << "----------6-----------" << endl;
    auto p8 = make_shared<Base>(12,1);
    cout << p8->get_num2() << endl;
    cout << p8.use_count() << endl;
    auto p9(p8);
    cout << p8.use_count() << endl;
    cout << p8.get() << endl;
    cout << p9.get() << endl;
 
    cout << "----------7-----------" << endl;
    std::shared_ptr<Base> p10{new Base(2),base_deleter};
  

    return 0;
}