#include <iostream>
#include "../utils.h"
#include <vector>
#include "Base.h"
#include "bar.h"

// function returning pointer
double * fun1(double& d)
{
 print("fun1");
 return &d;    
}

// returns a pointer to a vector created on heap
std::vector<double>* create_vec(int n, double d)
{
  std::vector<double>* ptr = new std::vector<double>;
  ptr->resize(n);
  for (int i = 0; i<n; i++){
    ptr->at(i) = d;
  } 
  return ptr;
}

void deallocate_vec(std::vector<double> *ptr)
{
    ptr = nullptr;
}

// return by reference function



// return by const reference 

// return by value

// return by const value

int main()
{
 double d1{45.1};
 double *ptr1{nullptr};
 print("ptr = ", ptr1);
 ptr1 = &(d1);
 print("ptr = ", ptr1);
 print("sizeof ptr1",sizeof ptr1);

 print("&ptr1 = ",&ptr1); // adress of the ptr, not the ptr itself
 *ptr1 = 12.1;

 print("ptr1 = ",*ptr1);

 print("----------------------");
 std::vector<double> v1{1,2,3};
 std::vector<double> *ptr2;

 ptr2 = &v1;
 print(ptr2->at(0));
 print(ptr2->at(1));

 print((*ptr2)[0]);
 print((*ptr2)[1]);

 double *ptr3 = new double{};  // allocates a double on heap 
 print("*ptr3",*ptr3);

 *ptr3 = 12.1;
 print("*ptr3",*ptr3);
 delete ptr3;
 print("*ptr3",*ptr3);
 print("ptr3 = ",ptr3);

 print("------------------------");
 double *ptr4 = new double[4];
 
 ptr4[0] = 1;
 ptr4[1] = 2;
 ptr4[2] = 3;
 ptr4[3] = 4;

 print("ptr4",ptr4);
 print("ptr4",ptr4[0]);
 print("ptr4",ptr4[4]);

 print("ptr4++",*(ptr4));
 print("ptr4 = ",*ptr4);

 print("--------------------------");

Base *p4 = new Base{45,3};

print(p4->get_name());
std::cout << p4->get_num() << std::endl;
std::cout << p4->get_num2() << std::endl;

delete p4;
print("deleted p4");
// print(p4->get_num()); // returns garbage value

Base b1 {15,32};
Base *p5 {&(b1)};

print(p5->get_num2());
print(p5->get_num());

print("---------------------");

int arr1 [3]{4,5,6};
print(arr1); // name of the array is the pointer to the first element
print(*arr1);// first element
print(arr1+1);
print(*(arr1+1));
print(arr1[3]);

print("---------------------");
const double d2{78.1};
const double *p6 {&d2};
print(*p6);

p6 = &(d1);
print(*p6);

// const pointer- cannot point to something else
print("const pointer");
double *const p7 {&d1};
print(*p7);
// p7 = &d2;  // not allowed

print("d1 address = ",&d1);
double *p8 = fun1(d1);
print("p8 - &d1 = ",p8-&d1);

std::vector<double>* p9 = create_vec(10,34.1);
 
for (auto &p: *p9){
    print(p);
}

print("deallocating vec");
deallocate_vec(p9);


print("------------- references-----");

double& ref1 {d1};
print(ref1);
ref1 = 14.1;
print("d1 = ",d1);
print(ref1);
 
print("- tests with Bar------------");
Bar b2(1,2,3,"rock");

int ref2{b2.get_n1()}; // ref2 gets assigned to a value
print("ref2 = ", ref2);
ref2 = 23; // changing value of ref2
print("ref2 = ", ref2);
print("b2.get_n1() = ", b2.get_n1()); // no change in num1

print("------------tests for return by ref-----------");
int & ref3 = b2.get_n1();
print("ref3 = ", ref3);
print("changing ref3 ");
ref3 = 67;
print("ref3 = ", ref3);
print("b2.get_n1() = ", b2.get_n1()); 
// can assign a return by ref to const ref, but not the other way round.
const &ref6 {b2.get_n1()};// since assigned a return by ref to const ref, cant change it now
print("ref6 = ",ref6);
// ref6 = 12; // not allowed to change it now

print("---------- Return by const value-----------");
int val1 {b2.get_n2()};
print("val1 = ", val1);
print("num2 = ",b2.get_n2());
val1 = 89;
print("changed val1 to 89");
print("val1 = ", val1);
print("num2 = ",b2.get_n2()); // num2 didnt change since val1 is not a ref

print("----return by const ref----");
const int &ref5 {b2.get_n2()}; //if ref5 is a ref, can only be const ref
print("ref5 = ", ref5);
// ref5 = 98; // cannot be changed
// int &ref7 {b2.get_n2()};// trying to assign a return by const ref to ref, we cannot

// return by const val
print("--------return by const val---------");
int val2 {b2.get_n3()};
print("val2 = ",val2);
val2 = 25; // allowed to change val2 here, since num3 is return by const val, but copied to val
print("changed val2  to 25");
print("val2 = ",val2);
print("b2.get_n3() = ",b2.get_n3()); // doesnt matter at all


}