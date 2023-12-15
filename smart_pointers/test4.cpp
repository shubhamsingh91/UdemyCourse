#include <stdio.h>
#include <iostream>
#include <memory>
#include<utility>

using namespace std;

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

int main(){

 int *num1 = new int {45};
  std::unique_ptr<int> ptr {num1};

 someFunction(); 

 auto ptr0 = new Resource(); // new T generates an object of type T and returns a pointer to it.

 cout << ptr0 << endl;
  
 Auto_Ptr<Resource> ptr1 {new Resource()};
 Auto_Ptr<Resource> ptr2 {std::move(ptr1)}; // on shallow-copy ptr2 also points to the resource of ptr1, without move it would call a copy constructor

Auto_Ptr<Resource> ptr3; 
ptr3 = generateResource(); // returns an r-value-- uses move constructor

ptr3= std::move(ptr2); // can invoke the move constructor now by casting the l-values into r-value references

cout << ptr1.isNull() << endl;
cout << ptr2.isNull() << endl;
cout << ptr3.isNull() << endl;

 cout << "---------------1-------------------" << endl;
 std::unique_ptr<Resource> ptr4 {new Resource()};
// std::unique_ptr<Resource> ptr5 {ptr4}; // copy constructor for unique_pointer is disabled, not used
 std::unique_ptr<Resource> ptr5 {std::move(ptr4)}; // this will work since unique_ptr implements move

 if(ptr4)
   cout << "ptr4 is managing an object" << endl;
  if(ptr5)
    cout << "ptr5 is managing an object" << endl; 

  auto ptr6 = make_unique<Resource>(); 

  std::shared_ptr<Resource> ptr7 { new Resource()};
  std::shared_ptr<Resource> ptr8 {ptr7};

  cout << ptr7.use_count() << endl;
  cout << ptr8.use_count() << endl;
  ptr7.reset();

    cout << ptr8.use_count() << endl;




    return 0;
}
