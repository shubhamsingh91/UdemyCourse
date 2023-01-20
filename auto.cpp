#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>
#include <algorithm>    // std::min_element, std::max_element
#include <iomanip>

using namespace std;

// testing range based for loops

int main()
{


int scores[] {12,24,46};

cout << fixed << setprecision(1);

for (auto score : scores)
cout << score << endl;
    
}