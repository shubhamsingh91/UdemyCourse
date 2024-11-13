#include <iostream>
#include "../utils.h"

template<typename Derived>
class Base {

private:
    int num1;

public:
    Base() {}
    Base(int n): num1{n} {}

    void print_num() {
        // Static cast to Derived and call its print_num_impl
        static_cast<Derived*>(this)->print_num_impl();
    }

protected:
    int print_num_base() const { return num1; } // Provide access to Base's data for Derived
};

class Derived : public Base<Derived> {

private:
    int num2;

public:
    Derived() {}
    Derived(int n): Base<Derived>(n), num2{0} {}
    Derived(int n, int m): Base<Derived>(n), num2{m} {}

    void print_num_impl() {
        print(num2);
        print(print_num_base());
    }
};


class Derived2 : public Base<Derived2> {

private:
    int num3;

public:
    Derived2() {}
    Derived2(int n): Base<Derived2>(n), num3{0} {}
    Derived2(int n, int m): Base<Derived2>(n), num3{m} {}

    void print_num_impl() {
        print(num3);
        print(print_num_base());
    }
};

int main(){

    Derived obj(23,45);
    obj.print_num();

    Derived2 obj1(98,11);
    obj1.print_num();

}