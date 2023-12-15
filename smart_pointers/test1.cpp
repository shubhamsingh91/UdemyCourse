#include <stdio.h>
#include <iostream>
#include <memory>
#include "Base.h"
#include "Derived.h"
#include<vector>

using namespace std;

int main()
{
   
   std::unique_ptr<int> p1 { new int {100}}; // initializing a pointer
   
   cout << *p1 << endl;
   *p1 = 200;
   cout << *p1 << endl;

   std::cout << p1.get() << endl; // returns pointer
   p1.reset();  // re-sets the pointer to null pointer

   cout << "-----1------" << endl;

   std::unique_ptr<Base> p2 {new Base(10)};
   cout << p2->get_num() << endl;
   cout << p2->get_num2() << endl;

    cout << "-----2------" << endl;
    
    std::unique_ptr<int> p3 = make_unique<int> (200); // no new keyword needed 
    cout << *p3 << endl;
    
    std::unique_ptr<Base>p4 = make_unique<Base>(12,23);

    cout << p4->get_num() << endl;
    cout << p4->get_num2() << endl;

    auto p5 = make_unique<Derived>(2,1);

    cout << p5->get_num() << endl;
    cout << p5->get_num2() << endl;

    cout << "-----3------" << endl;
    p4 = std::move(p2); // data of p2 moved to p4, p2 is empty now, p4 owns data of p2 now
    cout << p4->get_num() << endl;
    cout << p4->get_num2() << endl;
    if (!p2)
      std::cout << "p2 is null" << endl;

    cout << "-----4------" << endl;
    
    std::vector<std::unique_ptr<Base>> vec1;
    
    vec1.push_back(make_unique<Base>(3,4));
    vec1.push_back(make_unique<Base>(12,2));
    vec1.push_back(make_unique<Derived>(1,4));
    
    for (auto &v:vec1){ // need reference here, or else copies- cant do copy, can only move
        std::cout << v->get_num() << endl;
        std::cout << v->get_num2() << endl;

    }
 

    cout << "-----5------" << endl;

    return 0;
}