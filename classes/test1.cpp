#include <iostream>

using namespace std;
// testing class aggregate initializes

class base2{

 public:
  int a;
  base2():a{0}{
    std::cout << "no arg const base2" << std::endl;
  };
  base2(int n):a{n}{
    std::cout << "single arg. const" << std::endl;
  }; 
  base2(const base2& obj){
    std::cout << "copy constructor called" << std::endl;
    a = obj.a;
  }   
  void print()const {std::cout << "a = " << a << std::endl;}

};

class base{

 private:
  int num4;
  double num3;

 public:
  int num1;
  float num2;
  base2 obj_b2;
  
  base():num1{0}, num2{0.0}, num3{0.0}, num4{0}{
        std::cout << "no arg const base" << std::endl;
  };
  base(int n1, float n2, double n3, int n4):
      num1{n1}, num2{n2}, num3{n3}, num4{n4}, obj_b2{base2{n4}}{
        std::cout << "base 4 arg const" << std::endl;
      };

  void print() const{
    std::cout << " num1 = " << num1 << " num2 = " << num2 
        << " num3 = " << num3 <<" num4 = " << num4 << std::endl;
  }
  const base2& get_objbase2()const {
    return obj_b2;
  }

  void print_num4(const base& obj){
    std::cout << " obj.num4 = " << obj.num4 << std::endl; // print num4 also has access to pvt members of obj
  }
  
  const double& get_num3(){return num3;};

};

base2 create_base2()
{
  base2 obj{};
  return obj;
}

base2 create_base2_rvo()
{
  return base2{};
}

int main(){
 
 std::cout << "-------1--------------------------" << std::endl;
 base b1 {1,4.5,1.2, 23};
 b1.print();
 std::cout << "&(b1.obj_b2) = " << &(b1.obj_b2) << std::endl;

 double d1{b1.get_num3()}; // assigned to local var
 std::cout << "d1 = " << d1 << std::endl;
 d1 = 34;
 std::cout << "d1 = " << d1 << std::endl;

 const double &d2 {b1.get_num3()}; // d2 is a ref to num3
 std::cout << "d2 = " << d2 << std::endl;
//  d2 = 56;
 std::cout << "d2 = " << d2 << std::endl;

 const double d3{b1.get_num3()}; // assigned to a const local var
 std::cout << "d3 = " << d3 << std::endl;


 std::cout << "-----2---------------------------" << std::endl;

 base b2(b1);
 b2.print_num4(b1);

 std::cout << "-----3---------------------------" << std::endl;

 base2 b3{98};

 std::cout << "-----4---------------------------" << std::endl;
 
 const base2& b4 {b1.get_objbase2()};
 std::cout << "&(b4) = " << &(b4) << std::endl;
 b4.print();

 std::cout << "-----5---------------------------" << std::endl;
  
 auto b5 = create_base2();

 std::cout << "-----6---------------------------" << std::endl;

 auto b6 = create_base2_rvo();


    
}