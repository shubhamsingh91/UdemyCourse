#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Mystring{
private:

std::string s;

public:
Mystring(string str):s{str}{}
~Mystring(){}
friend std::ostream & operator<<(std::ostream &out, Mystring &str){
    out << str.s << std::endl;
    return out;
}

std::string operator()(int num1, int num2){
    return s.substr(num1,num2);
}


};

int main(){
 
  Mystring s {"Hello world!"};
  std::cout << s(7,5) << endl;

    return 0;
}