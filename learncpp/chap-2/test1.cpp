#include "../../utils.h"
#include <iostream>

int x = 23; // available throughout tthe code- in global namespace

namespace A {
 
 int b = 23;

}

void fun() {

    print("x = ",x);
}

class Test{
  private:
   int num1;
  public:
    Test(){print("x in class Test = ",x);};


};

int main(){

  fun();
  print("x in main = ",x);

  Test t;
  print("A::b = ",A::b);

    return 0;
}