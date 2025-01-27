#include <string>
#include <iostream>
#include <array>
#include <algorithm>

struct Student
{
    std::string name;
    int score;

    Student(std::string n, int s):name{n},score{s}{};
    ~Student(){};
};

int main(){

std::array<Student, 8> arr{
  { { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan has the most points (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } }
};

  auto lam = [](const Student &s1, const Student &s2){return s1.score < s2.score;};
  
 std::cout << (std::max_element(arr.begin(),arr.end(),lam))->name << " is the best student\n";


}
