#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>

using namespace std;

double f_to_c(double temp_f);
double f_to_k(double temp_f);

int main()
{

 double temp_f;

 cout << "Enter a temp in F deg " << endl;
 cin >> temp_f;

 cout << "temp in c is " << f_to_c(temp_f) << " deg C" << endl;
 cout << "temp in K is " << f_to_k(temp_f) << " deg K" << endl;
    


}


double f_to_c(double temp_f)
{

    return (5.0/9.0)*(temp_f-32.0);
}

double f_to_k(double temp_f)
{
    return round((5.0/9.0)*(temp_f-32.0)+273);
}

