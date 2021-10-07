#include <iostream>
#include <stdio.h>

using namespace std;

// max function

template<typename T>
T Max(T a, T b)
{
        cout << typeid(T).name() << endl;
        return a > b ? a : b;

}

template char Max(char a, char b); // explicit instantiating Max for character types

// adding two elements

template<typename T>
T add(T a, T b)
{
    return a+b;
}


// sum of the array elements
template<typename T>
T add_arr_elem(T *arr1, int arr_size)
{
    T sum = 0;
    for (int ii=0;ii<arr_size;ii++)
    {
        sum+=arr1[ii];
    }

    return sum;

}

// largest element in the array

template<typename T>
T largest_elem(T *arr1, int arr_size)
{
    T elem=arr1[0];
    for (int ii=1;ii<arr_size;ii++)
    {

        if(arr1[ii]>elem)
        {
            elem=arr1[ii];
        }


    }
    
    return elem;

}

int main()
{

    cout << Max(3,6) << endl;
    cout << Max(3.1,6.5) << endl;
    cout << Max('a','e') << endl;

    cout << Max<int>(3.4,6.5) << endl; // forcing it to be int here
    cout << add<int>(3.4,6.5) << endl; // forcing it to be int here

    int arr1[] {1,3,4,7,3};
    double arr2[] {5.78,56.9};

    cout << "sum of the int array is: " << add_arr_elem(arr1,5) << endl;
    cout << "sum of the double array is: " << add_arr_elem(arr2,2) << endl;

    cout << "largest of the int array is: " << largest_elem(arr1,5) << endl;
    cout << "largest of the float array is: " << largest_elem(arr2,2) << endl;


    return 0;
}