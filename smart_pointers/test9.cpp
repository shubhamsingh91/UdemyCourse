#include <iostream>
#include <memory>
#include "../utils.h"
#include "Base.h"
// 
void fun1(std::unique_ptr<Base> &&ptr)
{
 print("running fun1");
}


// practicing smart pointers
int main(){
 
    float f = 21.0;
    std::cout << "f = " << f << std::endl;
    std::cout << "&f = " << &f << std::endl;
    float* raw_1 (&f); // raw pointer for f- stores the address of f

    std::cout << "raw1 = " << raw_1 << std::endl;
    print("*raw1",*raw_1);

    std::unique_ptr<float> ptr1 = std::make_unique<float>(f); // initialized with f- creates a new raw pointer and ptr1 manages that
    std::unique_ptr<float> ptr2 (raw_1); // initializes ptr2 with raw_1

    print("ptr1",*ptr1);
    print("ptr1.get", ptr1.get());
    print("ptr2.get() = ", ptr2.get());

    print("------------------------------------");

    typedef std::unique_ptr<Base> base_ptr;

    std::unique_ptr<Base> ptr3 = std::make_unique<Base>(34,12);
    print("ptr3 = ", ptr3.get()); // returns the raw pointer underneth

    std::unique_ptr<Base>ptr4 {ptr3.get()};
    print("ptr4 = ",ptr4.get());
    print("ptr3 = ", ptr3.get()); // returns the raw pointer underneth
    ptr4.reset(new Base{14,15});
    print("resetting 4");

    if (!ptr4)
    {
        print("ptr4 resetted");
        print(ptr3->get_num2());// returns garbage since ptr4 is resetted and is managing the same memory
    } else 
    {
        print(ptr3->get_num2()); // returns garbage since ptr4 is resetted to a new pointer
        print(ptr4->get_num());  // returning get_num
    }

    print("---- using the release method to get the raw pointer rather");

    base_ptr ptr5 = std::make_unique<Base>(12,45);
    base_ptr ptr6 {ptr5.release()}; // releases the ownership of ptr5 and initializes ptr6 with the raw pointer
    print("ptr6 = ", ptr6->get_num2());

    print("------- using std move--------");
    print("ptr6.get = ", ptr6.get());
    base_ptr ptr7 = std::move(ptr6);
    print("ptr6.get = ", ptr6.get());
    print("ptr7.get()", ptr7.get());

    print("-------------------------------");
    fun1(std::move(ptr7));


    print("------------- shared ptr--------------------");
    typedef std::shared_ptr<Base>  base_shared_ptr;

    base_shared_ptr ptr_shared1 = std::make_shared<Base>(12,98);
    print("ptr_shared1.use_count()", ptr_shared1.use_count());
    base_shared_ptr ptr_shared2 {ptr_shared1};// copies
    print("ptr_shared1.use_count()", ptr_shared2.use_count());
    print("raw ptr = ",ptr_shared1.get());
    print("raw ptr 2= ",ptr_shared2.get());
    base_shared_ptr ptr_shared3  = ptr_shared2;
    print("raw ptr 3= ",ptr_shared3.get());
    
    print("----------------------------------------");
    


}