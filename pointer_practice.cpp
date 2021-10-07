#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>
#include <algorithm>    // std::min_element, std::max_element

using namespace std;

int main()
{

// practice pointers

int *int_ptr={}; // initialized to null
int num1 = 5;
char *char_ptr;
char char1 = 'c';

vector<int> *vec_ptr;
vector <int> vec1 {1,21,32,44};

cout << "int_ptr is " << int_ptr << endl;

int_ptr = &num1;
cout << "int_ptr is " << int_ptr << endl;

cout << "dereferencing int_ptr:" << *int_ptr << endl;


 cout << "char_ptr is " << (void *)char_ptr << endl; // garbage
 char_ptr = &char1;

 cout << "char_ptr now is " << (void *)char_ptr << endl; 
 cout << "dereferencing char_ptr:" << *char_ptr << endl;

// vec pointer
cout << "vec_ptr is " << vec_ptr << endl;

vec_ptr = &vec1;

 cout << "vec_ptr is " << vec_ptr << endl;
 cout << "dereferencing vec_ptr:" << (*vec_ptr).at(0) << endl;
 cout << "dereferencing vec_ptr:" << (*vec_ptr).at(2) << endl;


// using dynamic memory allocation

cout << "-------------------------------" << endl;

int *int_ptr2 {nullptr};
int_ptr2 = new int; // allocating new integer on the heap, cannot access the int variable, only the pointer to it

cout << "int_ptr2 is " << int_ptr2 << endl;
cout << "dereferencing int_ptr2 is " << *int_ptr2 << endl;

*int_ptr2 = 45;

cout << "dereferencing int_ptr2 is " << *int_ptr2 << endl;

delete int_ptr2;
int size;

int *ptr_array {nullptr};
cout << "Enter the size of the integer array" << endl;
cin >> size;
ptr_array = new int[size];

cout << "ptr_array is " << ptr_array << endl;

*ptr_array = 1;

cout << "ptr_array now is " << ptr_array << endl;

cout << "dereferencing ptr_array  is " << *ptr_array  << endl;

delete [] ptr_array; // deleting the ptr_array


// double array dynamic memory

cout << "-------------------------------" << endl;
cout << "-------------------------------" << endl;

double *temp_ptr {nullptr};
size_t sized;

cout << "What size of temp?" << endl;
cin >> sized;

temp_ptr = new double[sized];

*temp_ptr = 32.1;
*(temp_ptr+1) = 64.1;
*(temp_ptr+2) = 72.1;


cout << "temp_ptr is" << temp_ptr << endl;

cout << "temp[0] is" << *temp_ptr << endl;
cout << "temp[1] is" << *(temp_ptr+1) << endl;
cout << "temp[1] is" << *(temp_ptr+2) << endl;

delete [] temp_ptr;  // deallocating memory

}