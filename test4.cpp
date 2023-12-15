#include <iostream>
#include <stdio.h>

using namespace std;
namespace foo{

int dosomething(int x, int y){
    return x-y;
}

void print(){
    cout<< "Hello universe!" << endl;
}
}
namespace goo {

int dosomething(int x, int y){
    return x+y;
}
}

void print(){
    cout << "Hello world" << endl;
}


int main(){

cout << foo::dosomething(5,6) << endl;
cout << goo::dosomething(5,6) << endl;
::print();
foo::print();

}