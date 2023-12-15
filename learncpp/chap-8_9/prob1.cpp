/* Write a C++ program that implements a function template to find the maximum value 
from a given array of any data type. The program should:
Define a function template called max_value that takes an array of any data type and 
its size as parameters and returns the maximum value in the array.
In the main function, declare three arrays of different data types (e.g., int, double, and float), initialize them with some values, and call the max_value function for each array to find its maximum value.
Display the maximum values of each array on the screen with appropriate messages.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

template <typename T>
T max_value(T *arr, int size){
    T max;
    max=*(arr);
    for (int i=1; i<size;i++){
        if (*(arr+i)>max){
            max=arr[i];
        }
    }
    return max;
}

int main(){

   int intArr[] = {2, 3, 6, 8, 1, 4};
    double doubleArr[] = {3.14, 2.718, 1.414, 1.732, 0.866};
    float floatArr[] = {2.5f, 3.7f, 1.2f, 5.9f, 4.3f};


    int intMax = max_value(intArr, 6);
    double doubleMax = max_value(doubleArr, 5);
    float floatMax = max_value(floatArr, 5);
    
    cout << "The maximum value in intArr is: " << intMax << endl;
    cout << "The maximum value in doubleArr is: " << doubleMax << endl;
    cout << "The maximum value in floatArr is: " << floatMax << endl;

    return 0;
}