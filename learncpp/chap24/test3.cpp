#include <iostream>

using namespace std;

class Base {
protected:
    int val;
public:
    Base() : val{0} {};
    Base(int m) : val{m} {};
    void identify() { cout << "in base!" << endl; };
    int get_base_val(){return val;};
    ~Base() {};
};

class Derived : public Base {

public:
    Derived() {};
    Derived(int n) : Base{n} {};
    int get_val() { return val; };
    ~Derived() {};
    void callBaseIdentify() { Base::identify(); } // Public method to call Base::identify

private:
    using Base::identify; // Makes Base::identify private in Derived
    void identify() { cout << "in derived!" << endl; }; // Overrides Base::identify

    int get_base_val() = delete;

};
void externalFunction(Derived& d) {
    d.Base::identify(); // This should cause a compilation error
}

int main() {
    Derived d1;
    cout << d1.get_val() << endl;

    Derived d2(34);
    cout << d2.get_val() << endl;
    // d2.identify(); // Calls Derived::identify

    // Uncommenting the next line should cause a compilation error
    d2.Base::identify(); // not throwing a compilation error for some reason in g++

    d2.callBaseIdentify(); // Calls Base::identify through a public method
    externalFunction(d2);

    // d2.get_base_val(); // gives error
    d2.Base::get_base_val();
    static_cast<Base&>(d2).get_base_val();
 
    return 0;
}
