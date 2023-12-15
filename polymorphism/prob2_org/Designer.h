#ifndef _DESIGNER_H_
#define _DESIGNER_H_
#include <string>
#include "Employee.h"
#include <vector>

class Designer: public Employee {

private:
 std::string tool;

 public:
 Designer(){};
 Designer(std::string n, int I, int a):Employee(n,I,a){};
 void set_tool(std::string s){tool=s;};
 std::string get_tool(){return tool;}
 ~Designer(){};

};


#endif