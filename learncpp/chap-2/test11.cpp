#include <stdio.h>
#include <iostream>
#include "head.h"

using namespace std;

 void fun1();

namespace foo
{
    int num=45;
    int fun(){
        return 6;
    }
    namespace goo {
        int num = 34;
    }
} // namespace name

namespace gf = foo::goo;


class apple{
 public:
 
 static int num ; // non-const static needs to be declared outside the class
 static const int num1 {12}; // const static can be declared here

};
int apple::num =16;

extern int num = 12;
extern const int num3 {21};
int gen_int(){
    static int t1=0; // gets destroyed at the end of the program now
    t1+=1;
    cout << "t1 = " << t1 << endl;
    return 2;
}

int main(){
     int x{gen_int()};

    cout << "x = " << x << endl;
    {   
        x=5;
     cout << "x = " << x << endl;

        int x {gen_int()};
     cout << "x = " << x << endl;
       
    }

    int y{foo::fun()};
     cout << "y = " << y << endl;
     cout << "num = " << foo::num << endl;
     cout << "num in goo = " << foo::goo::num << endl;
     cout << "num in goo = " << gf::num << endl;
    
     int num {13}; // shadows the global num

     cout << "num = " << num << endl;

     fun1();   

     cout << "----------1---------------" << endl;
     cout << num1 << endl;
     cout << num2 << endl;
     cout << num3 << endl;

     gen_int();
     gen_int();
     cout << "----------2---------------" << endl;
     
     apple a1;
     cout << a1.num << endl;
     cout << a1.num1 << endl;


    return 0;
}