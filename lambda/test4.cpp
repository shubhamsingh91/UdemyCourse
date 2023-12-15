#include <iostream>
#include <stdio.h>

using namespace std;

int foo(){
    return 5;
}

int goo(int x){
    return x;
}


int main(){

cout << foo() << endl; 

int (*fptr)() {&foo}; // pointer to the function foo

cout << fptr << endl; // prints random things

cout << (*fptr)() << endl;

int (*gptr)(int) {&goo}; // pointer to the function foo
cout << (*gptr)(7) << endl;

 std::string s {"Hello"};
 std::string b {"Hello"};

 if (s<b){
    cout << "1" << endl;
 }else{
    cout << "2" << endl;
 }

}