#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>
#include <algorithm>    // std::min_element, std::max_element

using namespace std;

// more pointers practice here
// creating a dynamically allocated array

int *create_array(int init_value,int size);
void display(int *arr_ptr, int size);

int main()
{
  

    int *arr1;

    arr1 = create_array(20,100);
    display(arr1,100);

    delete [] arr1;

}


int *create_array(int init_value,int size)
{

    int *ptr1;
    ptr1 = new int[size];

    for (int ii=0; ii<size;ii++)
       ptr1[ii] = init_value;

    return ptr1;

}

void display(int *arr_ptr, int size)
{

    for (int ii=0; ii<size;++ii){
    cout << arr_ptr[ii] << " " ;
    }
}