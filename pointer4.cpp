#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int* create_array(int size,int initial){
    int* arr=new int[size];
    for (int i=0;i<size;i++){
        arr[i]=initial;
    }
    return arr;
}

void disp_array(int* arr,int size){

 for (int i=0;i<size;i++){
    cout << arr[i] << " ";
 }
}

int main(){


  int *p {nullptr};

  cout << p  << endl;
 // cout  <<  *p << endl; // seg fault
  int p1=34;
  p=&p1;
 cout  <<  *p << endl; 
 int p2=45;

 int *ptr2 {&p2}; // initialized pointer
 cout  <<  *ptr2 << endl; 
 *ptr2 = 12;
 cout << p2 << endl;

  int* ptr3 = new int {23}; // allocating pointer on the heap
  cout << *ptr3 << endl;

 int *ptr_arr = new int[5];
  ptr_arr[0]=12;
  ptr_arr[1]=34;

  cout <<  ptr_arr[0] << " " <<  ptr_arr[1] << endl;

  delete []ptr_arr;

  int arr1[4] {1,2,3,4};
  cout << arr1 << endl; // arr1 is the pointer to the first element of the array
  cout << *arr1 << endl;
  cout << *(arr1+1) << endl;
  cout << *(arr1+2) << endl;

  const double * ptr4 {nullptr}; // pointer to a const
  const double d1=12.1,d2=34.1;
  ptr4 = &d1;

  cout << *ptr4 << endl;
  ptr4 = &d2;
  cout << *ptr4 << endl;

  double d3=67.1;
  double* const ptr5 {&d3}; // const pointer has to be initialized and cant be pointer anywhere else
  cout << *ptr5 << endl;

  int * arr2 {create_array(5,1)};
  disp_array(arr2,5);
  int arr3[] {1,2,3};

  cout << std::size(arr3) << endl;

   const int size1= 4;
  int temp[size1]{};
  



    return 0;
}