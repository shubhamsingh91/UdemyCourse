#include <iostream>
#include "../utils.h"
using namespace std;

class Fraction
{       
    
    public:
      int numerator;
      int denominator;

      Fraction ():numerator{0}, denominator {1}{}; 
      Fraction (int n, int m):numerator{n}, denominator {m}{}; 
      void printFraction() {
        std::cout << this->numerator << '/' << this->denominator << '\n';
      }
      void getFraction() {
        std::cout << "Enter a value for numerator: ";
        std::cin >> numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> denominator;
        std::cout << '\n';     
      }
      int get_num() const {return numerator;}
      int get_den() const {return denominator;}
      Fraction multiply(const Fraction &f2) {
        return Fraction(this->numerator * f2.get_num(), this->denominator * f2.get_den());
      }
    
};




int main()
{
 Fraction f1{};
    f1.getFraction();

    Fraction f2{};
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).printFraction();

    return 0;
}