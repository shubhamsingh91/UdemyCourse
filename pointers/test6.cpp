#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Base.h"
#include <memory>
#include <cassert>

using namespace std;

template <typename T>
void print(const T &a){
    std::cout << a << std::endl;
}

template <typename T1, typename T2>
void print(const T1 &a, const T2 &b){
    std::cout << a << " " << b << std::endl;
}

void swap(float *ptr1, float *ptr2){
    
    float num1 = *ptr2;
    *ptr2 = *ptr1;
    *ptr1 = num1;
}

template <typename T, int n>
class Array{

//  private:
 
 public:
   T *ptr {nullptr};

   Array(){
    ptr = new T[n];
   };

   Array(const T var){
        ptr = new T[n];
        for (int i=0; i<n; i++){
            ptr[i] = var;
        }
   }
   int get_size() const {return n;}

   // copy constructor
   Array(const Array &obj) {
    // check if the size is same
     assert(this->get_size() == obj.get_size());

     ptr = new T[n];

     for (int i=0; i<n; i++){
        ptr[i] = obj.ptr[i];
     }
    
   }
   // move constructor
   Array(Array &&obj) noexcept{
    assert(this->get_size() == obj.get_size());
    this->ptr = obj.ptr;
    obj.ptr = nullptr;
   }

   T & operator[] (int i){
    return (this->ptr[i]);
   }

   ~Array(){ delete []ptr;};

};

int main(){

    float a1 {0.6};
    float *ptr1 {nullptr};
    ptr1 = &a1;

    print(a1);
    print(*ptr1);

    *ptr1 = 34.1;
    print(a1);
    print(ptr1);
    print(&a1);

    ptr1 = nullptr;
    // print(*ptr1); // causes seg fault

    print("-----------------1-----------------");

    float a3=1.5, a4=2.3;

    print("before a3 = ", a3);
    print(" a4 = ", a4);

    swap(&a3,&a4);
    print("after a3 = ", a3);
    print(" a4 = ", a4);

    Base *ptr3 = new Base();
    ptr3->set_num(1);
    
    print(ptr3->get_name());

    print("--------------------2-----------------");

    Base *ptr4;
    Base b1(14);
    ptr4 = &b1;
    
    print(ptr4->get_name());
    print(ptr4->get_num2());
    print(ptr4->get_num());
    print(ptr4->squared_fun(14.5));

    double *p5 = new double{12.5}; // double on the heap
    delete p5;
    // print("deleted p5");
    print(*p5);

    int *arr = new int[3] {1,21,34};
    print(*(arr+1)); // pointer arithmetic
    print(*(arr+2));
    
    print("---------------3---------------------");

    float arr2[4] {12.1,14.5,13.4,67.1};
    print(arr2[0]);
    print(arr2[2]);
    print(*(arr2+3));

    print("---------------4---------------------");

    Base * ptrb1 = new Base{}; // 
    ptrb1->get_name();
    ptrb1->set_num2(13);
    print(ptrb1->get_num2());
    
    print("---------------5---------------------");

    std::vector<Base*> vec_ptr;  // vec_ptr is a vector of points of Base objects
    vec_ptr.push_back(new Base{14});
    vec_ptr.push_back(new Base{});

    for (auto &c : vec_ptr){
        c->set_num(45);
        print(c->get_num());
    }

    print("---------------6---------------------");

    // const pointers

    const Base *ptrb2 = new Base{15}; // ptrb2 is a pointer to a const Base object
    print(ptrb2->get_name());
    print(ptrb2->get_num());

    Base obj{19}; 
    ptrb2 = &(obj); // ptrb2 is now moved to a different Base object
    print(ptrb2->get_num());

    Base *const ptrb3 = new Base{18}; // ptrb3 is a const pointer to a Base object, cant be moved to a different const Base object
    const Base obj1{31};

    // ptrb3 = &(obj1); // not allowed- compiler error

    print("---------------7---------------------");

    Array<int,4> arr1 {25};

    print(*arr1.ptr);
    print(*(arr1.ptr+3));

    Array<int,4> arr3{arr1}; // copy constructor
    print(*(arr3.ptr+2));

    Array<int,4> arr4 {arr3}; // move constructor example, arr3 obj is moved
    print(*(arr4.ptr+1));

    arr4[0] = 47;
    print(arr4[0]);


    return 0;
}