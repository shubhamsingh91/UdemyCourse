#include <iostream>
#include "../../utils.h"
#include <string>
#include <string_view>

using namespace std;

class Person{
 
 public:
  std::string m_name;
  int m_age;

  Person() = default;
  Person(std::string_view n, int a):m_name{n}, m_age{a}{};
  const std::string& get_name() const {return this->m_name;}
  int getAge() const {return m_age;}

  ~Person(){};

};

class BaseballPlayer : public Person{
 public:
   double m_battingavg;
   double m_homeruns;

   BaseballPlayer(double batting_avg = 0.0, double homeruns = 0.0):m_battingavg{batting_avg},m_homeruns{homeruns}{};

};

//Employee publicly inherits from Person
class Employee: public Person
{
public:
    double m_hourlySalary{};
    long m_employeeID{};

    Employee(double hourlySalary = 0.0, long employeeID = 0)
        : m_hourlySalary{hourlySalary}, m_employeeID{employeeID}
    {
    }

    void printNameAndSalary() const
    {
        std::cout << Person::m_name << ": " << m_hourlySalary << '\n';
    }
};

int main() {

    BaseballPlayer p1(12,34);
    p1.m_name = "Jack";
    std::string p2 = p1.get_name()+"Moe";
    print(p2);
   
    Employee e1(1213,12);
    e1.m_name = "John";
    e1.printNameAndSalary();

    return 0;
}