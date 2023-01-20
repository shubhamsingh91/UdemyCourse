#include <stdio.h>
#include <iostream>
#include<string.h>
#include <algorithm>    // std::reverse


// new functions/methods used-
// 1. std::reverse (algorithm)
// 2. std::to_string (algorithm)

using namespace std;

int main()
{
 int num1 = -101;

std::string str1 = std::to_string(num1);
std::string str2 = str1;
std::reverse(str1.begin(),str1.end());

if (str2==str1)
{
    cout << "true!";
}


}