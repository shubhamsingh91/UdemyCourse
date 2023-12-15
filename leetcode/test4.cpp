#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <limits.h>

using namespace std;
union U{
    int x;
    double d;
};

int get_length(char *str) {
    int count=0;
    cout << (str[count++]) << endl;
    while(str[count++]);
    return count-1;
}

int main(){
  U a;
  a.x = 1;

  std::cout << &(a.x) << std::endl;
  a.d = 23;
  std::cout << &(a.d) << std::endl;
  std::cout << &(a.x) << std::endl;

 int x=5, y=2;

 std::cout << (x&y) << std::endl;

 std::string str = "Hello";
 char *ptr = &str[0];

 cout << "---------1-----------" << endl;
 cout << get_length(ptr) << endl;

 float g; void *ptr1=&g;
 float f = *((float *)ptr1);

 char c = 129;

 printf("c = %i",c);
    cout << "CHAR_MIN : " << CHAR_MIN << endl;

    return 0;
}