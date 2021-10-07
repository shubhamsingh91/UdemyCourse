#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include <algorithm>
#include<map>
using namespace std;

// reverse string

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse (s.begin(),s.end());
    }
};

int main()
{

  //  vector<char> s {"h","e","l","l","o"};
    vector<char> s {'h','e','l','l','o'};

    Solution sol1;
    sol1.reverseString(s);

    for (int ii=0;ii<s.size();ii++)
    {
        cout << s[ii] << " " ;
    }

}