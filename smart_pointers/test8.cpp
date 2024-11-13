#include <stdio.h>
#include <iostream>
#include <memory>
#include "Base.h"
#include "Derived.h"
#include<vector>
#include "../utils.h"

int main() {
 
  std::unique_ptr<Base> p1 {new Base{23,1}};
   print(p1->get_name()); 
   print(p1.get());

   if(p1) {
    print("p1 is not null!");
   }

   Base* ptr2 {p1.release()};
   ptr2->set_num(78);
   print(ptr2->get_num());
   
   if(p1) {
    print("p1 is not null!");
   }

   auto ptr3 = std::make_unique<Derived> (12,34);
   print(ptr3->get_num2());
   print(ptr3->Base::get_name());
   print(ptr3.get());
   ptr3.reset();
   print(ptr3.get()); // reset to null


}