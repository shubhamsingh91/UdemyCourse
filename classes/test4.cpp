#include <iostream>
#include <string>

class Car {
public:
    std::string name;
    int speed;
    int* mileage {nullptr}; // Dynamically allocated memory

public:
    // Constructor 1: Default constructor
    Car():name{"Default Car"}, speed{0}, mileage{new int{0}}{};

    // Constructor 2: Parameterized constructor
    Car(const std::string& name, int speed):name{name}, speed{speed}, mileage{new int{0}}{};

    // Constructor 3: Delegating constructor
    Car(int speed):Car("Default Car", speed){};

    // Copy constructor
    Car(const Car& other){
        this->name = other.name;
        this->speed = other.speed;
        this->mileage = new int{};
        *this->mileage = *other.mileage; // deep - copy
    };

    // Destructor
    ~Car(){delete [] mileage;};

    // Utility to print details
    void printDetails() const
    {
        std::cout << "name = " << name << std::endl;
        std::cout << "speed = " << speed << std::endl;
        std::cout << "mileage = " << mileage <<  " value = " << *mileage << std::endl;

    };
};


int main(){

    Car c1{"F1", 300};
    c1.printDetails();

   Car c2{700};
   *c2.mileage = 45;
   c2.printDetails();


  std::cout << "---------------------------" << std::endl;
   Car c3{c2};
   c3.printDetails();


}