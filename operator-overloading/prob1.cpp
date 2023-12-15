#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;


template <typename T>
struct Traits{
  std::string str;
  
  static std::string name(int i){return "";};
  
};

template <>
std::string Traits<Fruit>::name(int i){
      Fruit f=static_cast<Fruit>(i);
         
      switch(f) {
    case Fruit::apple:
        return "apple";
        break;
    case Fruit::orange:
         return "orange";
        break;
    case Fruit::pear:
         return "pear";
        break;       
    default:
         return "unknown";
    }
  }
    
template <>
std::string  Traits<Color>::name(int i){
    Color c = static_cast<Color>(i);
      switch(c) {
    case Color::red:
         return "red";
        break;
    case Color::green:
         return "green";
        break;
    case Color::orange:
         return "orange";
        break;       
    default:
        return "unknown";
    } 
    
}
  

int main()
{

	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
        
    }
}

