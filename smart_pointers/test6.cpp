#include <stdio.h>
#include <iostream>
#include <memory>
#include "Base.h"
#include "Derived.h"
#include<vector>

using namespace std;

template<typename T>
class Autoptr{
 
 private:
   T *ptr;

 public:
   Autoptr(){
    ptr = new T;
   }
   Autoptr(const T&a){
    ptr = new T;
    *ptr = a;
   }

   T* get(){
    return ptr;
   }
   T& operator*(){return *ptr;};
  // deep-copy constructor
   Autoptr( Autoptr&p){
    cout << "copy constructor" << endl;
    ptr = p.ptr;
    p.ptr = nullptr;
   }

   Autoptr(Autoptr && r){
    cout << "Move constructor" << endl;
    ptr = r.ptr;
    r.ptr = nullptr;
   }

   ~Autoptr(){delete ptr;}

};

template<typename T>
class SharedP{

  private:
   T* p1;
   int* refCount;  // for reference counter

  public:
  SharedP(){ p1 = new T;
    refCount = new int(1);
    };
  SharedP(const T& a){p1 = new T;
    *p1 = a;
    refCount = new int(1);
  }
  
  // deep-copy constructor

  SharedP(SharedP& p){
    p1 = p.p1;
    refCount =p.refCount;   
      *(refCount)=*(refCount)+1;
  }
  int count_if(){return *refCount;}
  T* get(){return p1;}

  T& operator*(){
    return *p1;
  }

 void reset(){
  if ((*refCount) == 1) {
          delete p1;
          *refCount=*refCount-1;
          }else if((*refCount) == 0){
          p1 = nullptr;

          } else{
          p1 = nullptr;
          *refCount=*refCount-1;
          }
   
  }

  ~SharedP(){
    if ((*refCount) == 1) {
            delete p1;
            delete refCount;
        }
  };

};


int main(){

  std::shared_ptr<int> p {new int};
  cout << "p" << p << endl;
  *p = 45;
  cout << "*p = " << *p << endl;
  cout << "p.get() = " << p.get() << endl;

  std::shared_ptr<int> p1{p}; // copying into another shared ptr

  cout << "*p1 = " << *p1 << endl;
  cout << "p1.count() = " << p1.use_count() << endl;

// avoid this below-----------------//
//   int x{23};
//   int*p2 {&x};

//   std::shared_ptr<int> p3{p2};
//   cout << "*p3 = " << *p3 << endl;
//   cout << "p3.count() = " << p3.use_count() << endl;

//   delete p2;


cout << "--------------1------------------------" << endl;

  std::unique_ptr<double> ud1 {new double{23.5}};

  cout << "*ud1 = " << *ud1 << endl;
  cout << "ud1.get() = " << ud1.get() << endl;
  //ud1.reset(); // resets the pointer
   if(ud1){   cout << "ud1 =" << *ud1 << endl;}

  std::unique_ptr<double> ud2{std::move(ud1)}; // unique ptr moved here

   cout << "*ud2 = " << *ud2 << endl;
   cout << "ud2.get() = " << ud2.get() << endl;

  cout << "--------------2------------------------" << endl;

  auto ud3 = std::make_unique<double>(14.5); // can use make unique here

  cout << "*ud3 = " << *ud3 << endl;
  cout << "ud3.get() = " << ud3.get() << endl;

  auto t1 = make_shared<Base>(23,12);
  cout << "t1 = " << t1->get_name() << endl;
  t1->set_num(12);
  cout << "t1 = " << t1->get_num() << endl;

  auto t2 = t1;

  cout << "t2 = " << t2->get_num() << endl;
  cout  << "t2.count = " << t2.use_count() << endl;

  cout << "--------------3------------------------" << endl;
  
  int && ref{23}; // r value ref- no copies are made here
  cout << ref << endl;

  auto t3 = std::make_unique<Base> (12,34);
  cout << t3->get_num2() << endl;

  auto t4 = std::move(t3);  //t3 is moved here, cant be copied, t3 now points to NULL after moving
    cout << t4->get_num2() << endl;
 
 if(!t3)
 {cout << "t3 is null now!" << endl;}

 std::vector<std::unique_ptr<Base>> v;
 v.push_back(make_unique<Base>(12));
 v.push_back(make_unique<Base>(13));
 v.push_back(make_unique<Base>(14,56));

 for (auto &c:v){
  cout << "num =  " << c->get_num() << endl;
 }

 cout << "---------------------4----------------" << endl;

  Autoptr<int> t5(12);
  cout << t5.get() << endl;
  cout << *t5 << endl;

  Autoptr<int> t6(t5);
    cout << *t6 << endl;

 Autoptr<int> t7(std::move(t6));
    cout << *t7 << endl;

 cout << "---------------------5----------------" << endl;
  
  SharedP<int> x{12};
  cout << x.get() << endl;
  cout << x.count_if() << endl;
  cout << *x << endl;

  SharedP<int> y{x};
  cout << y.count_if() << endl;
  cout << y.get() << endl;
  cout << x.get() << endl;
  cout << *x << endl;
  cout << *y << endl;
  cout << x.count_if() << endl;

 cout << "---------------------6----------------" << endl;

  x.reset();
   cout << x.count_if() << endl;
   cout << y.count_if() << endl;
  //   cout << *x << endl;
  cout << *y << endl;
  y.reset();

 cout << "---------------------7----------------" << endl;
   cout << x.count_if() << endl;
   cout << y.count_if() << endl;

  SharedP<int> z{14};
    cout << z.count_if() << endl;
  cout << z.get() << endl;
  cout << *z << endl;
   cout << y.count_if() << endl;
   cout << x.count_if() << endl;


 



}