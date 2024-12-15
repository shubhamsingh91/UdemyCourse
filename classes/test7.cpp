#include <iostream>
#include "../utils.h"

class test7
{
private:
    float num1;

public:
    test7():num1{0.0} {}
    test7(float f):num1{f} {}
    test7(const test7& other){
        print("copy constructor called");
        num1 = other.num1;
    }
    test7& getobj(){ // return by reference
        return *this;
    }
    test7 getobj_v2(){ // return by value
        return *this;
    }
    const test7& getobj_v3(){
        return *this;
    }

    ~test7() {}
    
};

int main()
{
    test7 t1(45);
    print(" t1 = ", &(t1));
    print(" t1 = ", &(t1.getobj()));

    auto t2 {t1.getobj_v2()};
    print("t1 using v2 = ", &(t2));

    const test7 &t3 {t1.getobj_v3()};
    print("t1 using v3 = ",&(t3));

    return 0;
}