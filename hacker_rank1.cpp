#include <stdio.h>
#include <iostream>

using namespace std;

void fizzBuzz(int n)
{

for (int i=1;i<n+1;i++)
{
 if (((i%3)==0)&&((i%5)==0)) // 3 and 5
    {
        cout << "FizzBuzz" << endl;
    } else if (((i%3)==0)&&((i%5)!=0)) // 3 but not 5
    {
                cout << "Fizz" << endl;

    }   else if (((i%3)!=0)&&((i%5)==0)) // 5 but not 3
    {
                cout << "Buzz" << endl;

    }else
    {
        cout << i << endl;
    }
}
}

int main()
{

    fizzBuzz(15);

    return 0;

}