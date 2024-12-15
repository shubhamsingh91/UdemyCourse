#include <iostream>
#include "../utils.h"
#include <cstdint>
#include <cstddef>
#include <limits>

using namespace std;

class test1
{
private:
    double n1;
    int n2;
public:
    test1(): n1{0.1},n2{8}{};
    ~test1(){};
};


int main()
{
    // testing the sizeof operator

    std::cout << "size of bool = " << sizeof(bool) << std::endl;
    std::cout << "size of char = " << sizeof(char) << std::endl;
    std::cout << "size of float = " << sizeof(float) << std::endl;
    std::cout << "size of int = " << sizeof(int) << std::endl;
    std::cout << "size of uint8_t = " << sizeof(uint8_t) << std::endl;
    std::cout << "size of uint16_t = " << sizeof(uint16_t) << std::endl;
    std::cout << "size of uint32_t = " << sizeof(uint32_t) << std::endl;
    std::cout << "size of double = " << sizeof(double) << std::endl;
    std::cout << "size of long long = " << sizeof(long long) << std::endl;
    std::cout << "size of long double= " << sizeof(long double) << std::endl;

    test1 t1{};

    std::cout << "size of t1 = " << sizeof(t1) << std::endl;

    std::cout << "size of int_fast8_t = " << sizeof(int_fast8_t)*8 << " bits " << std::endl;
    std::cout << "size of int_fast16_t = " << sizeof(int_fast16_t)*8 << " bits " << std::endl;
    std::cout << "size of int_fast32_t = " << sizeof(int_fast32_t)*8 << " bits " << std::endl;
    std::cout << "size of int_fast64_t = " << sizeof(int_fast64_t)*8 << " bits " << std::endl;

    std::cout << "size of int_least16_t = " << sizeof(int_least16_t)*8 << " bits " << std::endl;
    std::cout << "size of int_least32_t = " << sizeof(int_least32_t)*8 << " bits " << std::endl;


    std::cout << "size of std::size_t = " << sizeof(std::size_t) << " bytes " << std::endl;
    
    std::cout << "float = " << std::numeric_limits<float>::is_iec559 << std::endl;





}