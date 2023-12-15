#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <string>
#include "Employee.h"
#include <vector>

class Project {

private:
 std::string name;
 int ID, startDate, endDate;
 std::vector<Employee> worker;

 public:
 Project(){};
  Project(std::string n, int I, int s, int e):name{n},ID{I},startDate{s},endDate{e}{};
 ~Project(){};

};


#endif