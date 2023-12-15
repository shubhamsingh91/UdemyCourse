#include <iostream>

bool passorFail()
{
    static int s_num;
    s_num++;
    if (s_num<=3){
        return true;
    }
    return false;
}

int main(){

   std::cout << "User #1: " <<(passorFail() ? "Pass\n": "Fail\n");
   std::cout << "User #2: " <<(passorFail() ? "Pass\n": "Fail\n");
   std::cout << "User #3: " <<(passorFail() ? "Pass\n": "Fail\n");
   std::cout << "User #4: " <<(passorFail() ? "Pass\n": "Fail\n");
   std::cout << "User #5: " <<(passorFail() ? "Pass\n": "Fail\n");
   std::cout << "User #6: " <<(passorFail() ? "Pass\n": "Fail\n");



    return 0;
}