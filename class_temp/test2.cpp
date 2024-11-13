#include <stdio.h>
#include <iostream>
#include<vector>
#include "../utils.h"

class Fun{
 
 public:
   int num1;

  explicit Fun(int x): num1{x}{

  };
  ~Fun(){};

};

void get_fun(Fun f) {
    print(f.num1);
}

int main() {
    
    Fun f{34};
    get_fun(f);
    // get_fun(45);
    

    return 0;
}