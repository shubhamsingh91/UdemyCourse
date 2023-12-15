#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <string>

class Employee {

private:
 std::string name;
 int ID, age;

 public:
 Employee(){};
 Employee(std::string n, int I, int a):name{n},ID{I},age{a}{};
 ~Employee(){};

};


#endif