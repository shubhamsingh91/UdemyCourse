#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>

using namespace std;

void print_guest_list(const std::string list1 [],int size_list); // need square brackets for pass by reference
void clear_guest_list(std::string list2 [],int size_list);


int main()
{

    std::string list1[] {"Joe", "Moe","Larry", "John", "Obama"};
    print_guest_list(list1,5);
    clear_guest_list(list1,5);
    cout << "Event finished, now the guest list is" << endl;
    print_guest_list(list1,5);

}

void print_guest_list(const std::string list1 [],int size_list)
{
    for (int ii=0; ii<size_list; ii++)
    {
        cout << list1[ii] << " ";
    }

    cout << endl;    
}

void clear_guest_list(std::string list2 [],int size_list)
{
    for (int ii=0; ii<size_list; ii++)
    {
        list2[ii] = " ";
     }

}
