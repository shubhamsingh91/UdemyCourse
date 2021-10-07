#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>
#include <algorithm>    // std::min_element, std::max_element

using namespace std;

// more pointers practice here

void double_data(int *ptr);
void swap(int *ptr1, int *ptr2);
void display(vector<string> *ptr);

int main()
{

  int value = 10;
  int *ptr1 {nullptr};  

    ptr1 = &value;
    //*ptr1 = value; // doesn't work to initialize ptr1, first it needs to point somewhere

    cout << "value  = " << value << endl;

    double_data(&value);

    cout << "value now  = " << value << endl;
   
    cout << "value  = " << value << endl;

    double_data(ptr1);

    cout << "value now  = " << value << endl;

    int a = 12, b=19;

    cout << " a = " << a <<  " b = " << b << endl;
    swap(&a,&b);
    
    cout << " a = " << a <<  " b = " << b << endl; 

    // const here is not working

     vector<string> stooges {"Larry","Moe","Curly"};
    cout << "&stooges is" << &stooges << endl;


    //  vector<string> *str_ptr {};
    //  str_ptr = &stooges;
     display(&stooges);

}

void double_data(int *ptr) // that's how you pass a pointer to a function
{

    *ptr = *ptr *2; // doubling data here

}

void swap(int *ptr1, int *ptr2)
{

    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

}

// display is not working
void display(const vector<string> *const ptr)
{
    //(*ptr).at(0) = "Funny";
    for (auto str: *ptr)
    cout << str << endl;


}