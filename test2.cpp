#include <iostream>
#include <stdio.h>
using namespace std;
#define NAME "John"

struct str1
{
    int n1;
    int n2;
};
struct str2
{
    int n3;
    int n4;
};

int add(int x, int y); // forward declaration
int add(int x, int y,int z); // forward declaration- overloaded function

int main(){

 str2 s1{45,6};
 cout << "s1.n3 = " << s1.n3 << endl;
 cout << "s1.n4 = " << s1.n4 << endl;
 
 str1 s2{s1.n3,s1.n4};
 
 cout << "s2.n1 = " << s2.n1 << endl;
 cout << "s2.n2 = " << s2.n2 << endl;

 cout << "add(5,6) = " << add(5,6) << endl;
 cout << "add(5,6,7) = " << add(5,6,7) << endl;

 #ifdef NAME
 cout << NAME << endl;
 #endif
 #ifndef VAR
 #define VAR 12
 cout << VAR << endl;
 #endif

}

int add(int x, int y){
    return x+y;
}

int add(int x, int y,int z){
    return x+y+z;
}