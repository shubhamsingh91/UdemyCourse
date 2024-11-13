#include <string>
#include "../utils.h"

class Person{

 private:
  uint16_t age;
  float height; // in cm

 public:
  Person(): age{0}, height{0}{};
  Person( uint16_t a, float h): age{a}, height{h}{};
  void details(){
    print("age  = ", age);
    print("height  = ", height);
  } 
  ~Person(){};

};

class Employee
{
private:
    std::string m_employer{};
    double m_wage{};

public:
    Employee(std::string_view employer, double wage)
        : m_employer{ employer }, m_wage{ wage }
    {
    }

    const std::string& getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }
};

// Teacher publicly inherits Person and Employee
class Teacher : public Person, public Employee
{
private:
    int m_teachesGrade{};

public:
    Teacher(uint16_t age, float height, std::string name, double wage, int grade): Person{age, height} ,
        Employee{name,wage}, m_teachesGrade{grade}{};
        
    ~Teacher(){};
};

int main(){

    Person p1(32,168.2);
    p1.details();

    Employee shubham{"shubham",450};
    print(shubham.getEmployer());
    print(shubham.getWage());

    print("---------------------------------");
    Teacher Jack{34,165.2,"Jack",780,89};
    
    print(Jack.getEmployer());
    
    Jack.details();

    return 0;
}