
// Problem:
// Write a C++ function that takes in an array of integers and its size. The function should modify the array in-place by doubling the value of each element and swapping adjacent elements. The function should also return the index of the element with the largest value.
// You should implement the function using pointers and references, without using any standard library functions or containers.
// Here's an example to illustrate the expected behavior:
// cpp

#include <stdio.h>
#include <iostream>

using namespace std;

int doubleAndSwap(int* arr, int size){
  int max;
  
    for(int i=0;i<size;i++){
     *(arr+i) *= 2;  
    }

    return max;
};

int main(){

int arr[] = {5, 2, 8, 3, 1};
int size = sizeof(arr) / sizeof(arr[0]);

int maxIndex = doubleAndSwap(arr, size);

std::cout << "Modified array: ";
for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
}
std::cout << std::endl;

std::cout << "Index of maximum value: " << maxIndex << std::endl;



}