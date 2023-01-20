#include<iostream>
#include <stdio.h>
#include <string>

using std::cout;
using std::endl;

template <typename T>
T max(T a, T b)
{
    return (a>b) ? a :b;

}

template <typename T1, typename T2>
void func(T1 a, T2 b)
{
    std::cout << a << " " << b << std::endl;
}

struct Person
{
    std::string name;
    int age;
};

template <typename T>
void my_swap(T &a, T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

int main()
{
    Person p1 {"Moe",30};
    Person p2 {"Curly",50};

    int a =1,b=2;

    cout << max(1.1,3.2) << endl;
   
    cout << max('A','N') << endl;

    func<int,double>(5,6.1);
    func<std::string,char>("Shubham",'A');

    int x = 100,y=200;

    cout << "x: " << x << "y: " << y << endl;
    my_swap(x,y);
    cout << "x: " << x << "y: " << y << endl;
   

}