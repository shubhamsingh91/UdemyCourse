#include <iostream>
#include <string>

using namespace std;

void mightGoWrong()
{
    bool error1 {true};
    bool error2 {false};
    bool error3 {false};

    if (error1)
    {
        throw 8;
    } 
    else if (error2)
    {
        throw std::string("Cat error!"); // creating a string object here
    }
    else if (error3)
    {
        throw new int{89};
    }
    
}

class mightGowrong{

 public:
    mightGowrong(){
        char *mem = new char[999999999999];
        delete [] mem;
    }

};

int main()
{
    try
    {
        mightGoWrong();
    }
    catch(int e)
    {
        std::cout << "Error code " << e << std::endl;
    }
    catch(std::string &e)
    {
        std::cout << "Error string " << e << std::endl;
    }
    catch(int *e){
        std::cout << "error code = " << *e << std::endl;
    }

    try
    {
        mightGowrong m;
    }
    catch(std::bad_alloc &e)
    {
        std::cout << "caught exception" << e.what() << '\n';
    }
    
    

}