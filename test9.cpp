#include <iostream>

using namespace std;

int x = 45;

void fun() {
  std::cout << "x = " << x << std::endl;
}

int main(){
  
 const  int n { 5};
 const int & ref {n};

  cout << n << endl;
  cout << ref << endl;
  //cout << *ref << endl; // wrong- not true with references




}