#ifndef _MANAGER_H_
#define _MANAGER_H_
#include <string>
#include "Employee.h"
#include <vector>

class Manager: public Employee {

private:
 std::vector<Employee> list;

 public:
 Manager(){};
 Manager(std::string n, int I, int a):Employee(n,I,a){};
 ~Manager(){};

};


#endif