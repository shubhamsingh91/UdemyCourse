#ifndef _DEVELOPER_H_
#define _DEVELOPER_H_
#include <string>
#include "Employee.h"
#include <vector>

class Developer: public Employee {

private:
 std::string lang;

 public:
 Developer(){};
 Developer(std::string n, int I, int a):Employee(n,I,a){};
 void set_lang(std::string s){lang=s;};
 std::string get_lang(){return lang;}
 ~Developer(){};

};


#endif