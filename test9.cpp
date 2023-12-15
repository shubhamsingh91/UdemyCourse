#include <iostream>

using namespace std;

int main(){
  
 const  int n { 5};
 const int & ref {n};

  cout << n << endl;
  cout << ref << endl;
  //cout << *ref << endl; // wrong- not true with references




}