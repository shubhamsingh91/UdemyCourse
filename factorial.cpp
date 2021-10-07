#include <iostream>
#include <cmath> // math library

using namespace std;

unsigned long long factorial(unsigned long long n);

int main()
{
    
    cout << "factorial 5 is " << factorial(5) << endl;
    cout << "factorial 10 is " << factorial(10) << endl;
    cout << "factorial 12 is " << factorial(12) << endl;
    cout << "factorial 15 is " << factorial(15) << endl;
    cout << "factorial 60 is " << factorial(60) << endl;

}

unsigned long long factorial(unsigned long long n)
{
    if(n<=1){
        return n;
    } else {
        return n*factorial(n-1);
    }    
}