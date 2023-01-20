#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// Udemy section-7 final challange

int main()
{

    vector<int> vector1,vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "vec1[0] is" << vector1.at(0) << endl;
    cout << "vec1[1] is" << vector1.at(1) << endl;

    cout << "size of vec1 is" << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "vec2[0] is" << vector2.at(0) << endl;
    cout << "vec2[1] is" << vector2.at(1) << endl;

    cout << "size of vec2 is" << vector2.size() << endl;


 // vector_2d

    vector<vector <int>> vector_2d;
    
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "elements of vec_2d are" << vector_2d.at(0).at(0) << endl;
    cout << "elements of vec_2d are" << vector_2d.at(0).at(1) << endl;

    cout << "elements of vec_2d are" << vector_2d.at(1).at(0) << endl;
    cout << "elements of vec_2d are" << vector_2d.at(1).at(1) << endl;

    cout  << "size of vec_2d is" << vector_2d.size() << endl;

    vector1.at(0) = 1000;

    cout << "----------------------------------------------------------" << endl;
    cout << "displaying the elements of vec_2d again" << endl;
    cout << "elements of vec_2d are" << vector_2d.at(0).at(0) << endl;
    cout << "elements of vec_2d are" << vector_2d.at(0).at(1) << endl;

    cout << "elements of vec_2d are" << vector_2d.at(1).at(0) << endl;
    cout << "elements of vec_2d are" << vector_2d.at(1).at(1) << endl;
   
    cout << "vec1[0] is" << vector1.at(0) << endl;
    cout << "vec1[1] is" << vector1.at(1) << endl;

    
}