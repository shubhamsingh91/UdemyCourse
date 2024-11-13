#include "../utils.h"
#include <iostream>

void fun(const double& x) {
  print(x);
}

void sort2(int &x, int &y) {
  if (x <= y) {
   return;
  } else {
   int temp = x;
    x = y;
    y = temp;
  }
}

int main() {

  const int *p1 {nullptr};
  print("p1 = ", p1);
  int i1 = 45;
  p1 = &i1;

  print("&i1 = ", &i1);
  print("p1 = ",p1);
  print("*p1 =", *p1);  

  printline();

  int arr1[6] {0,0,0,1,2,3};
  print("arr1 = ",arr1);
  print("*arr1 = ", *arr1);  
  
  for (auto &c: arr1) {
    print(c);
  }

  for (int i = 0; i < 6; i++) {
    print(*(arr1+i));
  }

  // pointer to a const
   double d1 {23.6};
   const double* ptr2 {&d1};

   print("*ptr2 = ", *ptr2);

   // const pointer
   float f1 {23.1};
   float *const ptr3 {&f1};
   print("ptr3 = ",*ptr3);
   float f2 {12.3};

  //  ptr3 = &f2; // illegal
  //  print("ptr3 = ",*ptr3);
   
  //  int x {45};
  //  int &y = x;
  //  print(y);
  //  y = 67;
  //  print(x);

  //  print("d1  before = ",d1);
  //  fun(d1);
  //  print("d1  after = ",d1);

  //  fun(45.6);


    int x { 7 };
    int y { 5 };

    std::cout << x << ' ' << y << '\n'; // should print 7 5

    sort2(x, y); // make sure sort works when values need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y); // make sure sort works when values don't need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    return 0;
}