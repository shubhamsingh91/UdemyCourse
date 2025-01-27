#include <iostream>
#include <optional>
#include "../utils.h"

using namespace std;

template <typename T>
std::optional<T> fraction(const T& x, const T& y)
{
    if (y==0){
        return std::optional<T>{};
    } else {
        return x/y;
    }
}

template <typename T> 
void check_frac(const std::optional<T>& f)
{
    if (f.has_value()){
        std::cout << "f has a value " << std::endl;
        std::cout << f.value() << std::endl;
    } else {
        std::cout << "f has no value" << std::endl;
    }
}


int main(){

    std::optional<int> t1{23};
    if (t1)
    {
        std::cout << "t1 has a value" << std::endl;
    } else {
        std::cout << *t1 << std::endl;
    }
    
    std::optional<float> f1 = fraction<float>(2.1,0.0);
    check_frac(f1);

    std::optional<int> f2 = fraction<float>(50,12);
    check_frac(f2);


}