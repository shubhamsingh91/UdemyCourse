#include <stdio.h>
#include <iostream>
#include <memory>
#include <utility>
#include "../utils.h"
#include "Base.h"

using namespace std;

//--- Practice for making a basic shared pointer from scratch --- //

class Resource{

    private:
     int num;

    public:
     Resource(){cout << "Resource const" << endl;}
     ~Resource(){cout << "Resource dest." << endl;}

};

template<typename T>
class Auto_Ptr{

 private:
  T *ptr;

 public:
  Auto_Ptr(T *p=nullptr):ptr{p}{};

// deep-copy constructor
 Auto_Ptr(Auto_Ptr &a)  // works on l value references
  { 
    cout << "Copy constructor" << endl; 
    ptr = a.ptr;
    a.ptr=nullptr;
  };

  // move constructor
  Auto_Ptr(Auto_Ptr &&a)   noexcept // works on r value rreferences
    {
     cout << "Move constructor" << endl;
     ptr=a.ptr;
     a.ptr = nullptr;

    }
  ~Auto_Ptr(){delete ptr;};

    // assignment operator using deep-copy
  Auto_Ptr& operator=(Auto_Ptr &a){
      cout << "Copy assignment oper" << endl; 
  
    if (&a==this){ // self-assignment check
        return *this;
    }
    
    this->ptr = a.ptr;
    a.ptr=nullptr;
    return *this;
     
  }

// move assingment operator 
   Auto_Ptr& operator=(Auto_Ptr &&a) noexcept {
      cout << "Move assignment oper" << endl; 

    if (&a==this){ // self-assignment check
        return *this;
    }
    
    this->ptr = a.ptr;
    a.ptr=nullptr;
    return *this;
     
  }

  T& operator*() const {return *ptr;}
  T* operator->() const {return ptr;} 
  bool isNull(){return (ptr==nullptr);}

};

void someFunction(){
    Resource* ptr = new Resource();

    return; // leads to dangling pointer
     delete ptr;

}

Auto_Ptr<Resource> generateResource()
{
    Auto_Ptr<Resource> res{new Resource};
    return res;
}

template <typename T>
class Smart_ptr{
 
 private:
   T *ptr {nullptr};
   int *ref_count_ptr {nullptr};

 public:
  Smart_ptr(){
    ptr = new T;
    ref_count_ptr = new int {1};
  };
  
  Smart_ptr(const T &var){
    ptr = new T {var};
    ref_count_ptr = new int {1};
  };
  

  // Deep-copy constructor
  Smart_ptr(const Smart_ptr<T> &obj): ptr{obj.ptr}, ref_count_ptr{obj.ref_count_ptr}{
    *(this->ref_count_ptr)+=1;
  };

  T* get(){return ptr;};
  int use_count(){return *(ref_count_ptr);};
  void reset(){
    ptr = nullptr;
    (*ref_count_ptr)--;
    if (*ref_count_ptr==0){
      delete ptr;
      delete ref_count_ptr;
    }
  };

  // Move constructor
  Smart_ptr(Smart_ptr<T> &&obj): ptr{obj.ptr}, ref_count_ptr{obj.ref_count_ptr}{
    delete obj.ptr;
    delete obj.ref_count_ptr;
  }
 
  // Dereferencing
  T& operator*(){
    if (ptr == nullptr) {
        throw std::runtime_error("Attempting to dereference a null pointer.");
    }
    return (*ptr);
    };

  T* operator->(){
    if (ptr == nullptr) {
        throw std::runtime_error("Attempting to dereference a null pointer.");
    }
    return (ptr);
  }
  
  ~Smart_ptr(){
    (*ref_count_ptr)--;
    if (*ref_count_ptr==0){
      delete ptr;
      delete ref_count_ptr;
    }
  } 

};


class Test{

 private:
 static int num1;

 public:
  Test(){};
  void increment_num(){num1+=1;}
  int get_num(){return num1;};

  ~Test(){};


};

int Test::num1 {0};

int main(){

 int *num1 = new int {45};
  std::unique_ptr<int> ptr {num1};

 someFunction(); // should be avoided, leads to a dangling pointer

 auto ptr0 = new Resource(); // new T generates an object of type T and returns a pointer to it.

 cout << ptr0 << endl;

 print("------- testing smart pointer-----------");
 Smart_ptr<int> ptr_int1 {12};
 print(ptr_int1.get());

 print("ptr_int1 use count =", ptr_int1.use_count());

 Smart_ptr<int> ptr_int2{ptr_int1};
 print("ptr_int1 use count =", ptr_int1.use_count());
 print("ptr_int2 use count =", ptr_int2.use_count());

 print("resetting ptr_int1");
 ptr_int1.reset();

 print("ptr_int1 use count =", ptr_int1.use_count());
 print("ptr_int2 use count =", ptr_int2.use_count());
 
 print("*ptr_int2 = ", *ptr_int2);

 print("----------------------------------------------");
 Smart_ptr<Base> ptr_b1 {Base{12}};
 
 print("ptr_b1 name = ", ptr_b1->get_name());
 print("ptrb1 num = ", ptr_b1->get_num2());

 auto ptr_b2 {ptr_b1};

 print("ptr_b1 use count",ptr_b1.use_count());
 print("ptr_b2 use count",ptr_b2.use_count());

 auto ptr_b3{Smart_ptr<Base> {Base{14}}}; // invoking the move constructor
 
 print("ptr_b3 use count",ptr_b3.use_count());
 print(ptr_b3->get_num());



 print("---------------Testing shared pointer-----");

 std::shared_ptr<int> ptr_s1 {new int{2}};
 std::shared_ptr<int> ptr_s2 {ptr_s1};

 print("ptr_s1 use count = ",ptr_s1.use_count());
 print("ptr_s2 use count = ", ptr_s2.use_count());

 ptr_s1.reset();
 print("resetted ptr_s1");
 print("ptr_s1 use count = ",ptr_s1.use_count());
 print("ptr_s2 use count = ", ptr_s2.use_count());


//  print(ptr_int2.get());

//  Test t1;
//  print(t1.get_num());
//  t1.increment_num();
//  print(t1.get_num());
 
print("------------------------------------------------------");
  
 Auto_Ptr<Resource> ptr1 {new Resource()};
//  Auto_Ptr<Resource> ptr2 {std::move(ptr1)}; // move constructor
 Auto_Ptr<Resource> ptr2 {ptr1}; // copy constructor

Auto_Ptr<Resource> ptr3; 
ptr3 = generateResource(); // returns an r-value-- uses move constructor

// ptr3= std::move(ptr2); // can invoke the move constructor now by casting the l-values into r-value references

// cout << ptr1.isNull() << endl;
// cout << ptr2.isNull() << endl;
// cout << ptr3.isNull() << endl;

//  cout << "---------------1-------------------" << endl;
//  std::unique_ptr<Resource> ptr4 {new Resource()};
// // std::unique_ptr<Resource> ptr5 {ptr4}; // copy constructor for unique_pointer is disabled, not used
//  std::unique_ptr<Resource> ptr5 {std::move(ptr4)}; // this will work since unique_ptr implements move

//  if(ptr4)
//    cout << "ptr4 is managing an object" << endl;
//   if(ptr5)
//     cout << "ptr5 is managing an object" << endl; 

//   auto ptr6 = make_unique<Resource>(); 

//   std::shared_ptr<Resource> ptr7 { new Resource()};
//   std::shared_ptr<Resource> ptr8 {ptr7};

//   cout << ptr7.use_count() << endl;
//   cout << ptr8.use_count() << endl;
//   ptr7.reset();

//     cout << ptr8.use_count() << endl;




    return 0;
}
