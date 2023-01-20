#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>

using namespace std;

void print_grocery_list(int apples=3,  int oranges=7, int mangos=13);

int main()
{

    int mangos, oranges, apples;

 print_grocery_list();
 print_grocery_list(5);
 print_grocery_list(7,11);


}

void print_grocery_list(int apples, int oranges, int mangos)

{
    cout << "apples = " << apples << endl;
    cout << "oranges = " << oranges << endl;
    cout << "mangos = " << mangos << endl;

}