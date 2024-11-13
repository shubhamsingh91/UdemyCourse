#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(std::string s) {
    
     int tmp, tmp1;

     auto lambda = [](char &c) ->int {
        switch(c) {
          case 'I':
            return 1;
          case 'V':
            return 5;
          case 'X':
            return 10;
          case 'L':
            return 50;
          case 'C':
            return 100;
          case 'D':
            return 500;
          case 'M':
            return 1000;               
        };
     };
     
    //  for (int i = 0; i < s.size()-1; i++) {
    //    string str = s[i]+s[i+1];
    //     std::cout << str << " " <<std::endl;
    //     if (str == "IV")
    //      tmp = 5;   
    //     else if(str == "IX")
    //      tmp = 9;
    //     else if(str == "XL")
    //      tmp = 50;
    //     else if(str == "XC")
    //      tmp = 90;
    //     else if(str == "CD")
    //      tmp = 400;       
    //     else if(str == "CM")
    //      tmp = 900;     
    //     else
    //      tmp = 0;
    //  };

     return tmp;

    }
};

int main(){

    Solution s1;
    s1("VII");


    return 0;
}