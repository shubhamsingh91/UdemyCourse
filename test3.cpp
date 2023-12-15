#include <iostream>
#include <stdio.h>

using namespace std;

bool iseven(int z){
    return (z%2==0);
}


int main(){

  std::cout << "Enter a single character" << endl;
  char c1;
  cin>>c1;

  cout << "You entered " << c1 << ", which has ASCII code " << static_cast<int>(c1) << endl;

  cout << "----------------------------" << endl;
  int num1;
  cout << "Enter an integer: " << endl;
  cin>> num1;

  cout << "num1 even = " << iseven(num1) << endl;


    return 0;
}