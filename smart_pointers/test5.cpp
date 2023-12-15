#include <stdio.h>
#include <iostream>
#include <memory>
#include "Base.h"
#include "Derived.h"
#include<vector>

using namespace std;

int main(){

  std::shared_ptr<int> p {new int{4}};           // only way to initialize a smart pointer
  std::unique_ptr<double> p1 {new double {5.4}}; // only way to initialize a smart pointer

 cout << p.get() << endl;
 cout << *p << endl;
 //p.reset();

 cout << p.get() << endl;

 std::shared_ptr<int> p2{p}; // p2 initialized as a copy of p
 cout << p2.get() << endl;

 // resetting full p2
 cout << p2.use_count() << endl;
 p.reset();
 
 cout << p2.use_count() << endl;
 p2.reset();

 cout << p2.use_count() << endl;
 // std::unique_ptr<double> p3 {p1}; // unique ptr cannot be copied

 cout << "----------1--------------" << endl;
 auto p4 = std::make_unique<Base>(45); // called by a parenthesis here, since a function
 cout << p4->get_name() << endl;
 cout << p4->get_num() << endl;
 p4.reset();
 
 auto p5 = std::make_shared<double>(12.3);
 cout << *p5 << endl;
 cout << p5.use_count() << endl;
 std::shared_ptr<double> p6 {p5};
 //auto p6 = std::make_shared<double>(p5);
 cout << p5.use_count() << endl;
 p5.reset();
 
 if(p5){
    cout << "managing" << endl;
 }
 cout <<  "--------3----------------" << endl;

 std::vector<std::unique_ptr<Base>> v;

 v.push_back(make_unique<Base>(12,3));
 v.push_back(make_unique<Derived>(45,6));
 v.push_back(make_unique<Base>());

 for(auto &c:v){  // can only use reference here, since unique_ptr cant be copied
   cout << c->get_num() << endl;
 }
 cout <<  "--------4----------------" << endl;
 int * p10 = new int{4};
 std::unique_ptr<int> p11{p10};

 cout << "------------5--------------" << endl;
 auto pb1 = std::make_unique<Base>(12,3);
 std::unique_ptr<Base> pb2{std::move(pb1)};

 if(pb1){cout << "pb1" << endl;}
 if(pb2){cout << "pb2" << endl;} 


 return 0;

}