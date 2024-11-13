#include <iostream>
#include <memory>
#include "base6.h"
#include "../utils.h"
using namespace std;

int main()
{ 
  base6 obj1;
  obj1.print();

  print("-----------------------------------");
  print("-----------------------------------");
  std::shared_ptr<base6> p1 = std::make_shared<base6>(1,0.1,2,3);
  p1->print();
  print("num3 = ",p1->num3);

  std::shared_ptr<base6> p2(p1);
  print("use count p1 = ", p1.use_count());  
  print("use count p2 = ", p2.use_count()); 
  print("p1 is managing = ", p1.get());
  print("p2 is managing = ", p2.get());
  print("p1->fun(23) = ", p1->fun(23));

  p1.reset();
  print("restting p1");
  print("use count p1 = ", p1.use_count());  
  print("p1 = ", p1);
  print("use count p2 = ", p2.use_count()); 

  print("-----------------------------------");
  derived6 obj3{23,3.1,34,1};  
//   print("num4 = ", obj3.num4);// not accessible

  print("-----------------------------------");
  auto p3 = std::make_shared<derived6>(12,87.1,13,95);
  p3->fun(678);
  print("obj3 fun = ", obj3.fun(23));
    
   print("-----------------------------------");
   std::shared_ptr<base6> p4= std::make_shared<derived6>(56,12.1,13,124);
   std::shared_ptr<derived6> p5 = std::dynamic_pointer_cast<derived6>(p4);

   p4->fun(231);
   p4->bar(); // not virtual
   print("-----------------------------------");
   print("p5");
   p5->fun(12);
   p5->bar(); 

}