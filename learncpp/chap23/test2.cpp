#include <iostream>
#include <string>
#include <string_view>
#include <functional>
#include <vector>
#include "intArray.h"
#include "../../utils.h"

class Teacher
{
private:
  std::string m_name{};

public:
  Teacher(std::string_view name)
      : m_name{ name }
  {
  }
  const std::string& getName() const { return m_name; }
};

class Department
{
private:
  std::vector<std::reference_wrapper<const Teacher>> teach_vec; 
  
public:
  Department(){}
  void add(const Teacher &t) {
    teach_vec.emplace_back(t);
  };
  friend std::ostream & operator<<(std::ostream &out, const Department& d) {
    out << "dept has ";
    for (auto t: d.teach_vec) {
        out << t.get().getName();
        out << " ,";
    }
    out << "!";
    return out;
  }
  ~Department(){};    

};

int main()
{
 // Create a teacher outside the scope of the Department
  const Teacher t1{ "Bob" };
  Teacher t2{ "Frank" };
  Teacher t3{ "Beth" };

  {
    // Create a department and add some Teachers to it
    Department department{}; // create an empty Department

    department.add(t1);
    department.add(t2);
    department.add(t3);

    std::cout << department;

  } // department goes out of scope here and is destroyed

  std::cout << t1.getName() << " still exists!\n";
  std::cout << t2.getName() << " still exists!\n";
  std::cout << t3.getName() << " still exists!\n";
  
  IntArray arr1{5};
  print(arr1.getlength());
  for (int i=0; i<arr1.getlength(); i++){
    arr1[i] = 3;
  }

  arr1.print();
  print("re-sizing!");
  arr1.resize(7);
  arr1.print();
  
  print("Creating new array using copy const!");

//   IntArray arr2(arr1);
//   arr2.print();

 // Declare an array with 10 elements
    IntArray array(10);

    // Fill the array with numbers 1 through 10
    for (int i{ 0 }; i<10; ++i)
        array[i] = i+1;

    // Resize the array to 8 elements
    array.resize(8);

    // Insert the number 20 before element with index 5
    array.insertBefore(20, 5);

    // Remove the element with index 3
    array.remove(3);

    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // A few more tests to ensure copy constructing / assigning arrays
    // doesn't break things
    {
        // IntArray b{ array };
        // b = array;
        // b = b;
        // array = array;
    }

    // Print out all the numbers
    for (int i{ 0 }; i<array.getlength(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    IntArray arr3{1,2,4};
    arr3.print();

    IntArray arr4{56};
    arr4.print();

    IntArray arr5{};
    arr5 = {1,2,3,4};
    arr5.print();


  return 0;
}