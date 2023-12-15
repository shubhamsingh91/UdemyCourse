#include <vector>
#include <iostream>
#include <stdio.h>
#include "functions.cpp"


/*Author- Shubham Singh
Contact- singh281@utexas.edu

This is the solution to the problem statement presented for the JNJ assessment.
User can either input their own matrix (input 1), or generate a random matrix (input 2) with elements as 0 or 1.
The functions used here can be found in the functions.cpp file.

Some comments on the approach-
1. The STL vector container is used throughout for the implementation. Instead of this another approach would be to use the Eigen matrix, but for a small
size of matrix, the performance doesn't vary.

2. The process_matrix function essentially acts on the matrix and fills it with element 1 as required in the problem statement.

3. input_matrix is used to build the matrix by the user, while generate_rand_mat is used to generate a random matrix (with higher probability of 0 
being the element as compared 1) of a given size by the user.

4. print_matrix just prints the matrix elements row by row.

5. Four unit-tests are written for three of the essential functions used in this project. These are not exhaustive, and more tests can be easily replicated 
using the Google test framework.

6. For any questions in building and running the project, contact Shubham Singh- singh281@utexas.edu.
*/


int main(){


   std::vector<std::vector<int>> mat;
   int flag;

   std::cout << "Input 1 for inputting the matrix, 2 for generating a random matrix!" << std::endl;
   std::cin >>flag;
   switch (flag)
   {
   case 1:
    input_matrix(mat);                                // Inputting the elements of the matrix
    break;
    case 2:
    generate_rand_mat(mat);                           //  Generating a random matrix
    break;
   
   default:
   std::cout << "\nError! Select between 0 or 1. Exiting!" << std::endl;
    exit(1);
   }

    std::cout << "\nmatrix Before " << std::endl;

    print_matrix(mat);                                // Printing matrix before

    process_matrix(mat);                              // Processing the matrix
   
    std::cout << "\nmatrix After " << std::endl;
    print_matrix(mat);                                // Printing matrix after processing
   


}