#include <iostream>
#include <algorithm>
#include <memory>
#include "../utils.h"
#include "../inheritence/base2.h"
#include "../inheritence/derived2.h"
#include <eigen3/Eigen/Dense>

int main(){
    
    std::shared_ptr<base2> b1 = std::make_shared<base2>(23,1,2);
    print("1. b1. count = ", b1.use_count());
    b1.reset();
    print("b1 = ", b1);
    std::shared_ptr<base2> p2 = std::make_shared<base2>(12,13,4);
    p2->get_name();

    std::shared_ptr<base2>  b2{p2};
    print("\nuse count of b1 = ", b1.use_count());

    b1 = b2;
    print("use count of b1 after= ", b1.use_count());
    print("use count of b2 = ", b2.use_count());
    print(b1.get());
    print(b2.get());
    print(p2.get());    


    auto lambda1 = []() -> int{std::cout << "\nrunning lambda expres" << std::endl;
                                return 7;};
    
    int y{56};
    auto lambda2 = [&y](int x){std::cout << "running lamb2 \n"; 
                            return x+y;};

    lambda1();
    auto z = lambda2(12);
    print("z =", z);

     [&z](int g){std::cout<< g+z << std::endl;}(18);

     auto lam4 = [z, &b2](int u)mutable 
     {z=0; 
     return z+u+ b2->get_num2();};
     print("lam4 = ", lam4(0));

     int h = lam4(89);

     print("------------ 1.-----------");

    /*'Filtering with std::find_if
    Given a vector of integers, write a lambda function with std::find_if to find the first even number in the vector
    */
     typedef std::vector<int> vi;

     std::vector<int> v_int  = {11,283,3,41,53,61,77,81,34,1};

     auto it1 = std::find_if(v_int.begin(),v_int.end(),[](const int& n){return (n%2==0);});
     if (it1 != v_int.end()){
        std::cout << *it1 << std::endl;
     } else {
        print("Even no. not found!");
     }

     print("-------------2----------------");
     /*
     Create a lambda function to transform a vector of integers by doubling each element. Use std::transform to apply this lambda function.
     */
     vi v_int2 = {12,34,12,13,45,6};
     vi v_int_result (v_int2.size());

     std::transform(v_int2.begin(), v_int2.end(), v_int_result.begin(), [](int a){return 2*a;});

     for (auto &i : v_int_result){
        std::cout << i << " ";
     }
     

     print("\n-------------------------------");


}