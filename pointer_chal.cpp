#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>    // std::min_element, std::max_element

using namespace std;

// pointer challenge

void print(int arr[], int size);
int *apply_all(int arr1[], int arr1_size, int arr2[], int arr2_size);

int main()
{

const size_t arr1_size {5};
const size_t arr2_size {3};

int arr1[] {1,2,3,4,5};
int arr2[] {10,20,30};

cout  << "Array 1: ";
print(arr1, arr1_size);

cout  << "Array 2: ";
print(arr2, arr2_size);

int *results {nullptr};

results = apply_all(arr1,arr1_size,arr2, arr2_size);

cout  << "Final array is: ";
print(results, 15); // for arrays, the name is the address of the first element

//cout << "results is" << results << endl;

delete [] results;

}




void print(int arr[], int size)
{

for (int ii=0; ii<size; ii++)
{
    cout << arr[ii] << " ";
}
cout  << endl;

}

int *apply_all(int arr1[], int arr1_size, int arr2[], int arr2_size)
{

    int *arr_ptr {nullptr};
    int arr_size {};
    int position {0};
    arr_size = arr1_size*arr2_size;

    arr_ptr = new int[arr_size];

    for (int jj=0; jj<arr1_size; jj++)
    {

        for (int ii=0; ii<arr2_size; ii++)
        {
            arr_ptr[position] = arr1[jj]*arr2[ii]; 
            position++;
        }

    }

return arr_ptr;

}