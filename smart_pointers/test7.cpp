#include <stdio.h>
#include <iostream>
#include <memory>
#include "Base.h"
#include "Derived.h"
#include<vector>

using namespace std;

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


int main()
{

std::unique_ptr<double> p1 { new double{12.4}};
cout << *p1 << endl;

cout << p1.get() << endl;
p1.reset();
cout << p1.get() << endl;

p1 = make_unique<double>(34.4);
cout << p1.get() << endl;
cout << *p1 << endl;

if(p1){
    cout << "*p1 = " << *p1 << endl;
}

 auto p2 = std::move(p1);  // here p1 is converted to an r-value reference and then moved, after moving of p1,it is null.
 cout << p1.get() << endl;
    cout << "*p2 = " << *p2 << endl;


 cout << "---------1-------------------" << endl;

 std::shared_ptr<int> p3 {new int{34}};
 cout << p3.use_count() << endl;
 cout << *p3 << endl;

 auto p4 = p3;
 cout << p3.use_count() << endl;
 cout << *p4 << endl;

 p3.reset();
 cout << p4.use_count() << endl;

 cout << "---------2-------------------" << endl;
 
 SharedP<int>pt1(6);
 cout << pt1.count_if() << endl;
 cout << *pt1 << endl;
 auto pt2{pt1};

  cout << *pt2 << endl;
  cout << pt1.count_if() << endl;
  cout << pt2.count_if() << endl;
 
  cout << "resetting pt1" << endl;

  pt1.reset();
  cout << pt1.count_if() << endl;
  cout << pt2.count_if() << endl;
  cout << *pt2 << endl;



return 0;
}