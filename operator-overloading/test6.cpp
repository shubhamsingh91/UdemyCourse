#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

class IntArray{

 private:
  int *arr;
  size_t len;
 
 public:
  IntArray(){};
  IntArray(int num):len(num){
    arr = new int[len];
  } 
//   IntArray(const IntArray& source){
   
//   }
  int& operator[](const int& loc) const {
    assert(loc<=(len-1));

    if (loc<=len-1){
        return arr[loc];
    }

  }
  friend std::ostream& operator<<(std::ostream& out, const IntArray& a){
    if(a.arr){
        for (int i=0;i<a.len;i++){
            out << a[i] << " ";
        }

    }
    return out;
  }
  IntArray& operator=(const IntArray& source){
    if (this==&source){
        return *this;
    }  

    len=source.len;

    delete []arr;

    arr = new int[len];

    for (int i=0;i<len;i++){
        arr[i]=source.arr[i];
    }
    return *this;

  }

  ~IntArray(){};


};

IntArray fillArray(){

    IntArray a(5);
    a[0]=5;
    a[1]=8;
    a[2]=2;
    a[3]=3;
    a[4]=6;

    return a;

}

int main(){

  IntArray a {fillArray()}; 
  cout << a << endl;

  auto& ref{a};
  a=ref;

  IntArray b(1);
  b=a;

  cout << b << endl;

    return 0;
}