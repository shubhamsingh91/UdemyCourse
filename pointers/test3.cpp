#include <iostream>
#include <stdio.h>
#include "Base.h"

using namespace std;

// templated array

template<int n,typename T>
class Array{
private:
T *ptr{nullptr};

public:
 Array(){
  ptr = new T[n];
 };
 Array(T m){
     ptr = new T[n]; 
    for(int i=0;i<n;i++){
        ptr[i]=m;
    }
 }
 void print(){
    for(int i=0;i<n;i++){
        cout << ptr[i] <<  " " << endl;
    }
 }
 
 ~Array(){delete [] ptr;};

};

// returns pointer here
int* make_array(int n){

    int* p = new int[n];
    return p;

}

int main(){

int *p {nullptr};

int x{3};
int y[4] {4,5,21,4}; // integer array

cout << "p = " << p << endl;
p=&x;

cout << "p = " << p << endl;
cout << "p[0] = " << p[0] << endl;

cout << "*p = " << *p << endl;

cout << "y = " << y << endl; // name of the array is a pointer to the first element of the array
cout << "y[0] = " << y[0] << endl;

for (auto &c:y){
    cout << c << endl;
}
cout << "-----------0----------------" << endl;

cout << *(y) << endl; // can also use array name as a pointer and use pointer arithmetic here
cout << *(y+1) << endl; // using pointer arithmetic here


cout << "-----------1----------------" << endl;

int &u = x; // u is a refernce to x (declaring reference here)
cout << "x = " << x << endl;
u = 23;
cout << "u = " << u << endl;
cout << "x = " << x << endl;
u = y[0];
cout << "u = " << u << endl;

cout << "-----------2----------------" << endl;
Base *p2 {nullptr};
Base b1(1,4);
p2=&b1;
p2->set_num(23);

cout << p2->get_name() << endl;
cout << "-----------3----------------" << endl;

Base* p3 = new Base{23}; // p3 is a pointer to an object of type Base on the free-store or the heap

p3->set_num2(12);

cout << p3->get_num() << endl;
cout << p3->get_num2() << endl;

cout << "-----------4----------------" << endl;

int* p4 = new int[4] {12,3,4,5};

cout << p4[2] << endl;

int* p5 = new int[4]{45,34,1} ;

cout << "-----------5----------------" << endl;

Array<4,int> a1;
a1.print();

Array<5,int> a2(23); //overloaded constructor
a2.print();

Array<3,double> a3{0.1};
a3.print();

cout << "-----------6----------------" << endl;
int *a4 = make_array(5);
cout << a4[0] << endl;

void* p6 {nullptr};
int* p7 = new int{45};

cout << *p7 << endl;
cout << p7 << endl;

p6 = &(*p7);
void* p9 = new double {23.4};
double* p10 = static_cast<double*>(p9); // void pointer has to be casted to some other type of pointer in order to dereference

int*p8 = static_cast<int*>(p6);

cout << *p8 << endl;

cout << *p10 << endl;






return 0;

}