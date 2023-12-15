#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Base.h"

using namespace std;

template <typename T,int n> // partial template specialization
class Array{

 private:
  T* ptr {nullptr};

 public:
  Array(){ptr = new T[n];};
   Array(T y){ptr = new T[n];
    for(int i=0;i<n;i++){
        ptr[i]=y;
    }
   };
  void print(){
    for (int i=0;i<n;i++){
        cout << ptr[i] << " ";
    }
    cout << endl;
  }
  ~Array(){ delete[] ptr;};

};


int main(){

 int *p {nullptr};
 int x=34;
 p  = &x;

 cout << "p  =" <<p << endl;
 cout << "*p = " << *p << endl;
 
 const int y = 23;
 const int*p2{nullptr}; // p2 is the pointer to a const int
 p2 = &y;
 cout << "*p2 = " << *p2 << endl;

 const int z=12;
 p2 = &z;
 cout << "*p2 = " << *p2 << endl;

 const int * const p3{&z}; // p3 is a const pointer to a const int
 cout << "*p3 = " << *p3 << endl;

 cout << "------------1------------------" << endl;
 
 int *p4 = new int {34};
 cout << "*p4 = " << *p4 << endl;  

 Base *ptr1 = new Base{12,23};
 cout << ptr1->get_name() << endl;
 ptr1->set_num2(34);

 cout << ptr1->get_num2() << " " << ptr1->get_num() << endl;

 cout << sizeof ptr1 << endl;

 delete ptr1;

 cout << "------------2------------------" << endl;
 int arr1[4]{1,2,3,4};

 cout << *arr1 << endl;
 cout << *(arr1+1) << endl; // pointer arithmetic

 Array<int,4> arr2;
 Array<double,3> arr3(12.4);
 arr3.print();

 cout << "-----------3------------------" << endl;
 int &r =x;

 cout << r << endl;
 cout << x << endl;

 r = y;
 cout << x << endl;



    return 0;
}
