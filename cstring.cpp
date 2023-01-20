#include <stdio.h>
#include <iostream>
#include <cstring>
#include"Mystring.hpp"

using namespace std;
int main()
{

    
    int scores[] {1,2,3};
    int *score_ptr {scores};

    cout << scores << endl;
    cout << scores[0] << endl;

    cout << "--------------" << endl;

    cout << scores[2] << endl;
    cout << *scores<< endl;

    cout << score_ptr << endl;
    cout << *score_ptr<< endl;

    char arr2[] {'a','v','c'};

    cout << arr2 << endl;   // this doesnt show the address, but the value of the stored element

    cout << *arr2 << endl; // gives the first element of the character array

    // practicing references
    int num {100};
    int &ref {num}; // definition of a reference

    cout << num << endl;
    cout << ref << endl;

    ref = 300;

     cout << num << endl;
    cout << ref << endl;
   

   // Mystring here
   Mystring str1 {"Hellos"};

    const char *str_ptr {nullptr};
    str_ptr=  str1.get_str();

    cout << str_ptr << endl;
    cout << *str_ptr << endl;

    Mystring str2;
    str2 = str1;
    
    str2 = "Hola";
    
    // cout << &str1 << endl; // returns the address of str1

    str1.display();
    str2.display();

    return 0;
}