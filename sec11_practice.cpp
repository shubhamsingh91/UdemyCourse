#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>

using namespace std;

double area_circle(double r); // function prototype
double vol_cyl(double h, double r); // function prototype
int pass_by_value1(int num);
//vector<string> pass_by_valuestr(vector<string> s); // doesnt work
void pass_by_valuestr(vector<string> s); //  works

// functions for passing arrays in functions
void print_array(const int arr1[], int size);
void set_array(int arr1[], int size, int num_in);

void print_vec(vector<int> &vec1, int size); // using pass-by-reference here for vector
void clear_vec(vector<int> &vec1); // using pass-by-reference here for vector

// pass by reference
void pass_by_ref1(int &num);

void static_local_example();

int main()
{

    cout << "sin of floor of exp(5) is " << sin(floor(exp(5))) << endl;
    cout << "sqrt of 41 is " << sqrt(41) << endl;

    cout << "5^4 is " << pow(5,4) << endl;


    // creating random numbers  
    int random_number {};
    size_t count {10};


    cout << "RAND_MAX on my system is" << RAND_MAX << endl;
    cout << "time(nullptr) is" << time(nullptr) << endl;

    srand(time(nullptr)); // seeding the random_generator- without it, the same sets of random number are generated


    for  (int ii=0; ii<10; ii++)
    {
        random_number = rand() % 6 +1 ;
        cout << random_number << endl;
    }


    cout << "------------------------" << endl;

    cout << "Area of the circle with rad = 4.1 is " << area_circle(1) << endl;

    cout << "Vol of the cyl with rad=3, h=4 is " << vol_cyl(3,4) << endl;


    int num = 10;
    // testing pass by value
    cout << "num originally is" << num << endl;

    cout << "return of pass_by_value1 is" << pass_by_value1(num) << endl; // doesn't change the value of num here- pass_by_value1

    cout << "num after pass_by_value1 is" << num << endl;


    vector<string> strarr1 {"a1","a2","a3"};
    cout << "strarr1[0] before is " << strarr1[0] << endl;

    pass_by_valuestr(strarr1);

    cout << "strarr1[0] after is " << strarr1[0] << endl;
   
    
    // testing passing arrays in functions here

    int arr1[5] {45,23,12,34,53};
    print_array(arr1,5);
    set_array(arr1,5,67);
    print_array(arr1,5);

    // testing passing vectors by reference in functions here

    vector<int> vec1 {1,2,3,3,4};
    cout << "vec1 is" << endl;
    print_vec(vec1,5);
    cout << "clearing vec1" << endl;
    vec1.clear();
   // clear_vec(vec1);
    cout << "size of vec1 now is" << vec1.size() <<endl;

    cout << "Done!!" << endl;

    // more pass by reference test

    int num2 = 5;

    cout << "num2 is" << num2 << endl;
    pass_by_ref1(num2);
     cout << "num2 is" << num2 << endl; // value is changed now due to pass by reference
   
 // static example - 
  static_local_example();
  cout << "------------------" << endl;
    static_local_example();


}


// Function for calculation of the area of the circle
double area_circle(double r)
{

    return M_PI*pow(r,2);
}

double vol_cyl(double h, double r)
{

    return M_PI*pow(r,2)*h;
}

int pass_by_value1(int num)
{

    num = 1000;
    return num;
}

void pass_by_valuestr(vector<string> s)
{

    s.clear();
}

void print_array(const int arr1[], int size)
{

    for (int ii=0; ii<size; ii++)
    {
        cout << arr1[ii] << " ";
    }
    cout << endl;
}

void set_array(int arr1[], int size, int num_in)
{

    for (int ii=0; ii<size; ii++)
    {
        arr1[ii] = num_in;
    }
}

void print_vec(vector<int> &vec1, int size)
{

    for (int ii=0; ii<size; ii++)
    {
        cout << vec1.at(ii) << " ";
    }
    cout << endl;
    
}

void clear_vec(vector<int> &vec1)
{

    vec1.clear();    
}

void pass_by_ref1(int &num)
{

    num = 1000;
}

void static_local_example()
{

    static int num=100; // retains values between function calls, only initialized once.
    cout << "num is" << num << endl;
    num=num+100;

    cout << "num after is" << num << endl;
}