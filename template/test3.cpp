#include <iostream>
#include "../utils.h"
#include <string>

template <typename T, int n>
class Calc {
 
 private:
   T a;  

 public:
   Calc(T b):a{b}{};
   void modify(){a  = a*5.0;}

   template <typename T1, int n1>
   friend std::ostream& operator<< (std::ostream& out, const Calc<T1,n1>& obj);
   ~Calc(){};

};
 template<typename T, int n>
 std::ostream& operator<< (std::ostream& out, const Calc<T,n>& obj) {
   out << obj.a;
   return out;
 }



// Full specialization of the class template for `int`
template <int n>
class Calc<int, n> {
private:
    int a;

public:
    Calc(int b) : a{b} {}

    void modify() { a = a * 7; }

    template <typename T1, int n1>
    friend std::ostream& operator<<(std::ostream& out, const Calc<T1, n1>& obj);

    ~Calc() {}
};


template <typename T, typename ... Args>
void function(T a, Args... args) {
    print(a);
    print(args...);
}

int main() {    

    Calc<int,4> a1(56);
    a1.modify();
    print(a1);
    std::string s {"asda"};
    print(s);
    function(34,12.3,56.2);

    return 0;
}