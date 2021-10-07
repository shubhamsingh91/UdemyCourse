#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

// testing switch case here

    int day_code;

    cout << "Enter day_code" << endl;
    cin >> day_code; 

    switch (day_code)
    {
    case 0: 
        cout << "It's sunday!" << endl;
        break;
     case 1: 
        cout << "It's Monday!" << endl;
        break;
     case 2: 
        cout << "It's Tuesday!" << endl;
        break;
     case 3: 
        cout << "It's Wednesday!" << endl;
        break;
     case 4: 
        cout << "It's Thursday!" << endl;
        break;
     case 5: 
        cout << "It's Friday!" << endl;
        break;
     case 6: 
        cout << "It's saturday!" << endl;
        break;
    default:
        cout << "Illegal entry!" << endl;
        break;
    }

    

}