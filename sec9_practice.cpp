#include <iostream>
#include <stdio.h>

using namespace std;

// testing if-else

int main()
{

int age;
bool has_car;

cout << "Enter your age!" << endl;
cin >> age;

if (age >= 16){
    cout << "Do you own a car? If yes then enter 1, otherwise 0!" << endl;
    cin >> has_car;

    if(has_car)
    {
    cout << "Yes - you can drive!";
    } else {
        cout << "Sorry! you need to buy a car to drive!" << endl;
    }

} else 
{
cout << "Sorry come back in " << 18-age << " years!" << endl;
}


// conditional operator




}