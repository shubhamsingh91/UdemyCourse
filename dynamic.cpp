#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>
#include <algorithm>    // std::min_element, std::max_element

using namespace std;

int main()
{

    int scores[] {98,100,85,12,56,-1};

    cout << scores << endl; // is sort of the address of the first element of the array
    cout << *scores << endl; // gives the first element of the array

    int *score_ptr {nullptr}; 
    score_ptr = scores; // pointer initialized to the first element of the scores array

    cout << score_ptr << endl; // is sort of the address of the first element of the array


    cout << "scores[0] is" << score_ptr[0] << endl;
    cout << "scores[1] is" << score_ptr[1] << endl;
    cout << "scores[2] is" << score_ptr[2] << endl;

    cout << "scores[0] is" << *score_ptr << endl;
    cout << "scores[1] is" << *(score_ptr++) << endl;

    cout << "scores[0] is" << *scores << endl;
    cout << "scores[1] is" << *(scores+1) << endl;
    cout << "scores[2] is" << *(scores+2) << endl;

    cout << "---------------------------" << endl;
    while(*score_ptr!=-1)
    {
        cout << *score_ptr << endl;
        cout << score_ptr << endl;
        score_ptr++;

    }


    // constant pointers

   const int high_score {100};
    int low_score {45};

//------ This is confusing and unclear----------------------------------//
    const int *score_ptr1 {&high_score}; // pointer to a int constant

    cout << "score_ptr is " << score_ptr1 << endl;
    cout << "*score_ptr is " << *score_ptr1 << endl;
    //*score_ptr1 = 1;  // illegal
    cout << "*score_ptr is " << *score_ptr1 << endl;
    cout << "score_ptr is " << score_ptr1 << endl;
    score_ptr = &low_score;
    cout << "*score_ptr is " << *score_ptr1 << endl;
    cout << "score_ptr is " << score_ptr1 << endl;


//----------------------------------------------------

    int high_score2 {74};
    int low_score2 {36};

    int *const score_ptr2 {&high_score2};
   cout << "--------------------------------" << endl;
     cout << "score_ptr2 is " << score_ptr2 << endl;
    cout << "*score_ptr2 is " << *score_ptr2 << endl;
    
    *score_ptr2 = 78;
    high_score2 = 73;

    cout << "*score_ptr2 is " << *score_ptr2 << endl;
     cout << "score_ptr2 is " << score_ptr2 << endl;
    //score_ptr2 = &low_score2; // illegal step here, since score_pt2 is a constant pointer to an integer



}