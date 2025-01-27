#include <iostream>

class Foo
{
private:
    int m_x{};
public:
    explicit Foo(int x)
        : m_x{ x }
    {
        std::cout << "single arg const. called" << std::endl;
    }

    Foo(const Foo& other){
        std::cout << "copy const. called" << std::endl;
        this->m_x = other.m_x;
    }

    int getX() const { return m_x; }
};

void printFoo(const Foo &f) // has a Foo parameter
{
    std::cout << "printing a Foo parameter here" << std::endl;
    std::cout << f.getX() << std::endl;
}

int main()
{
    // printFoo(5); // we're supplying an int argument
    Foo f1{323};
    Foo f2(12);

    printFoo(f1);
    printFoo(f2);

    printFoo(static_cast<Foo>(4));
    printFoo(Foo{123});



    return 0;
}