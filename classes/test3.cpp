#include <iostream>
#include <memory>

using namespace std;

class base1{
    public:
     int num1;
     base1():num1{0}{};
     base1(int n):num1{n}{};
};

class base2{
    public:
     int num2;
     std::shared_ptr<base1> b_ptr;
     float num3;

     base2():num2{0}{};
     base2(int n, float m):num2{n}, b_ptr{std::make_shared<base1>(n)}, num3{m} {
        std::cout << "single arg constructor" << std::endl;
        std::cout << "b_ptr = " << b_ptr << std::endl;
        std::cout << " num1 = " << num1 << std::endl;
     };
     const std::shared_ptr<base1>& get_base1_ptr(){
        return b_ptr;
     }
     base2(int n): base2(n,0.0){std::cout << "calling delegating const" << std::endl;};
};

int main(){
 
  std::cout << "----------1---------------------" << std::endl;
  base2 obj1{12,34.1};
  std::cout << "obj1.get_base1_ptr() = " <<  obj1.get_base1_ptr() << std::endl;

  std::cout << "----------2---------------------" << std::endl;
  base2 obj2 {34};

}