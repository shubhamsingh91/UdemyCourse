#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

auto add(int x, int y){ // using auto as the return type
    return x+y;
}

auto sub (int x, int y) -> int // trailing return type here
{
    return x-y;
}

auto add(double x, double y){
    return x+y;
}

template <typename T>
T add(T x, T y)
{
    cout << "Templated function called!" << endl;
    return x+y;
}


// trying some static_casts
int main(){
    using dub = double; // d1 is an alias of double now
    typedef int I;

    dub d = 1.5;
    I i {static_cast<I>(d)}; // narrowing conversion not allowed by brace initialization, but allowed by static_cast

    cout << "d = " << d << endl;
    cout << "i = " << i << endl;
  
    char c {'y'};
    dub d1 {static_cast<dub>(c)};

    cout << "c = " << c << endl;
    cout << "d1 = " << d1 << endl;

    cout << "add(5,6) = "<< add(5,6) << endl;  
    cout << "sub(6,7) = " << sub(6,7) << endl; 

    cout << "add(5.6,6.7) = "<< add(5.6,6.7) << endl;  
    cout << "add<>(5.6,6.7) = "<< add<>(5.6,6.7) << endl;  


}