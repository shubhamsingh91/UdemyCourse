#include <iostream>
#include <cmath> // math library

using namespace std;

double double_penny(double amount, int days);

int main()
{
 int days;
    cout << "Enter the no of days: " << endl;
    cin >> days;
    cout << "0.01 doubled in " << days << "days is: $ " << double_penny(0.01,days) << endl;    
    return 0;

}

double double_penny(double amount, int days)
{        
    if (days==1){
    return amount;
    } else {
        days = days-1; 
        amount=2*double_penny(amount,days);
    }
}