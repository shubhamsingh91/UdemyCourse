#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct StudentGrade{
std::string name;
char grade;

};

class GradeMap{
 private:
  std::vector<StudentGrade> m_map;

    public:
   char& operator[](const std::string &s){
    std::vector<StudentGrade> :: iterator it = std::find_if(m_map.begin(),m_map.end(),[&](const auto& student){return (student.name==s);});
    if (it!=m_map.end()){
        return it->grade;
    }else
    {
        m_map.push_back(StudentGrade {s});
        return m_map.back().grade;
    }

  }

};

int main(){


    GradeMap grades{};
    grades["Joe"]='A';
    grades["Frank"]='B';

    std::cout << "Joe has a grade of " << grades["Joe"] << endl;
   
    char& gradeMac {grades["Mac"]};
    gradeMac='C';
    std::cout << "Mac has a grade of " << grades["Mac"] << endl;

    return 0;
}