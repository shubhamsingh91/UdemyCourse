#include <iostream>

class bar{

    private:
      float num1 {};

    public:
      bar(): num1{0.0}{};
      explicit constexpr bar(float f): num1{f}{};
      constexpr bar(const bar& other){
        this->num1 = other.num1;
      }

      constexpr float get_num1(){
        return num1;
      }  

      constexpr float generate_num(){
        const float f{9.6};
        return f;
      }
       void print_num1(){
        std::cout << "num1 = " << num1 << std::endl;
      }

};

int main(){

    bar b1{34.1};
    std::cout << "b1.num1 = " << b1.get_num1() << std::endl;

    constexpr float f1{b1.generate_num()};
    std::cout << "f1 = " << f1 << std::endl;

    constexpr bar b2{76.1};
    constexpr bar b3{b2};

    // b2.print_num1();
    //  float f2{b2.get_num1()};
    // std::cout << "b2.num1 = " << f2 << std::endl;
    // std::cout << "b3.num1 = " << b3.get_num1() << std::endl;


}