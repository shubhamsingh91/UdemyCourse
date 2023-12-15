#include <stdio.h>
#include <iostream>
#include "Base.h"
#include <vector>
#include <string>

using namespace std;

template<typename T>
void double_data (T&p)  {
    p=p*2;
}

Base* make_base(){
    return new Base{12,13};
}

template<int size,typename T>
class Array{

    private:
    T* ptr{nullptr};

    public:
    Array(){
         ptr = new T[size];
    }
     Array(T m){
         ptr = new T[size];
    for(int i=0;i <size; i++){
            ptr[i]=m;
        }
    }
    void print(){
        for(int i=0;i <size; i++){
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    ~Array(){
        delete []ptr;
    };

};


int main(){

int x=12;
int *ptr {nullptr};
ptr = &x;

cout << "ptr  =" << ptr << endl;
cout << "*ptr = " << *ptr << endl;
cout << "&x =" << &x << endl;

*ptr = 13; // changed the value of x using the ptr to x

cout << "x =" << x << endl;

cout << "size of ptr = " << sizeof(ptr) << endl;

double y=34.1;
double *p1 {&y};

cout << "size of p1 = " << sizeof(p1) << endl; // size of ptr doesnt change, all same size for all types

Base b1{12,4};

Base* p2 {&b1};             // pointer to a static object
Base *p3 = new Base{12,2}; // pointer to a dynamic object of class Base

cout << p2->get_name() << endl;
cout << p3->get_num2() << endl;

int arr[4] {45,3,1,4}; // name of the arr is a pointer to the first element of arr
cout << "*arr = " << *arr << endl;
cout << "*(arr+1) = " << *(arr+1) << endl;

double *p4 = new double[2];
*(p4) = 23.1;
*(p4+1) = 2.5;

cout << "*(p4+1) = " << *(p4+1) << endl;

cout << "------------1--------------" << endl;

vector<int> *p5;
vector<int> arr_int{12,3,5};
p5 = &arr_int;

cout << "p5[0] = " << p5->at(0) << endl; // can only access using an at here, no other method for vector pointers

char name[]{'a','b','c'};
char *p6{name};

cout << "p6[0] = " << p6[0] << endl;

cout << "------------2--------------" << endl;
constexpr int t{34};
const int *p7 {&t};

cout << "*p7 = " << *p7 << endl;

p7=&x; // pointer pointed to a new location, not a const pointer
cout << "*p7 = " << *p7 << endl;

const int *const p8 {&t}; // const pointer
cout << "*p8 = " << *p8 << endl;

// p8 = &t; // cant be pointed to other variables, const pointer

int x1 {34};
cout << "x1 = " << x1 << endl;
double_data<int>(x1);

cout << "x1 = " << x1 << endl;


cout << "------------3--------------" << endl;

int &x2 {x1}; // x2 is a reference to x1, cant be aliased to somwhere else
x2 = 45;

cout << "x1 = " << x1 << endl;
x2=x;
cout << "x1 = " << x1 << endl;

cout << "------------4--------------" << endl;

Base* b2 { make_base()}; // this is OK to assign an output pointer directly to annother pointer
cout << "b2 = " << b2->get_num2() << endl;

//int x3 {double_data(34)}; // not possible in double_data, cant change const value
//cout << "x3 = " << x3 << endl;

cout << "------------5--------------" << endl;

Array<4,int> a1;
a1.print();

Array<4,char> c1{'H'};
c1.print();

}