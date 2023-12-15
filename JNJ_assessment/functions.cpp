#include <vector>
#include <iostream>
#include <cassert>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

/*Author- Shubham Singh
Contact- singh281@utexas.edu
*/

/*input_matrix function is used to input in a mxn matrix from the user.
First it takes in the number of rows and columns for the matrix, and then row by row elements separated by space.
Only 0 or 1 can be inputs for the elements of the matrix.
*/

void input_matrix(std::vector<std::vector<int>>& mat){
     int rows,cols;

    std::cout << "Enter the no of rows = ";
    std::cin >> rows;
    if (rows <= 0) {
        std::cerr << "\nERROR: Number of rows should be greater than 0. Exiting!" << std::endl;      // Check for number of rows > 0
        exit(1);
    }
    std::cout << "Enter the no of cols = ";
    std::cin >> cols;
    if (cols <= 0) {
        std::cerr << "\nERROR! Number of columns should be greater than 0. Exiting!" << std::endl;  // Check for number of cols > 0
        exit(1);
    }
    std::cout << "\nNo of rows, cols = " << rows << "x" << cols<<std::endl;

    mat.resize(rows);
    for (auto &c:mat){
        c.resize(cols);
    }
    std::cout << "\nEnter row elements separated by spacing" << std::endl;
    for (size_t i=0;i<rows;i++){
    std::cout << "Row " << i+1 << ": ";
      for (size_t j=0;j <cols;j++){
        int temp;
        std::cin >> temp;
       if ((temp!=0)&&(temp!=1)) {
        std::cerr << "\nERROR! input elements should be 0 or 1. Exiting!" << std::endl;      // Check for number of rows > 0
        exit(1);
        }
        mat[i][j] = temp;
        
      }

    }
}

/*process_matrix function modifies a mxn matrix based on the problem statement. Based on which elements of the matrix
are 1, corresponding rows and columns are set as 1.
*/

void process_matrix(std::vector<std::vector<int>> &mat){
    int rows, cols;

    rows = mat.size();
    cols = mat[0].size();

    std::vector<int> row_set,col_set;            // vectors for storing which rows and cols to set to 1
    row_set.clear();
    col_set.clear();

    
    for (size_t i=0;i <rows;i++){                // Filling up the col_set and row_set vectors
        for (size_t j=0;j<cols;j++){
            if (mat[i][j]==1){
                row_set.push_back(i);
                col_set.push_back(j);
            }
        }
    }

    for (auto &r:row_set){                       // setting required rows to 1
        for (size_t j=0;j<cols;j++){
            mat[r][j]=1;
        }
    }

    for (auto &r:col_set){                       // setting required cols to 1
        for (size_t j=0;j<rows;j++){
            mat[j][r]=1;
        }
    }
}

/*print_matrix function prints the values of a mxn matrix row by row.
This also performs a check for both rows and columns of the matrix to be greater than 0.
*/

void print_matrix(const std::vector<std::vector<int>> &mat)
{   int rows, cols;

    rows = mat.size();
    if (rows <= 0) {
        std::cerr << "ERROR! Number of rows should be greater than 0. Exiting!" << std::endl;
        exit(1);
    }
     cols = mat[0].size();
    if (cols <= 0) {
        std::cerr << "ERROR! Number of columns should be greater than 0. Exiting!" << std::endl;
        exit(1);
    }      
      for(auto &r:mat){
        for (auto &e: r){
            std::cout << e <<  " ";
         }
            std::cout << std::endl;
        }

}


/*generate_rand_mat function is used to generate  mxn matrix from the user.
First it takes in the number of rows and columns for the matrix, and then generates a mxn matrix
with random values of 0 and 1, with higher probability of 0.
*/
void generate_rand_mat(std::vector<std::vector<int>>& mat){
     // Seed the random number generator using the current time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Define a custom distribution with a higher probability for zeros
    std::discrete_distribution<int> distribution({80, 20});

    int rows,cols;

    std::cout << "Enter the no of rows = ";
    std::cin >> rows;
    if (rows <= 0) {
        std::cerr << "\nERROR: Number of rows should be greater than 0. Exiting!" << std::endl;      // Check for number of rows > 0
        exit(1);
    }
    std::cout << "Enter the no of cols = ";
    std::cin >> cols;
    if (cols <= 0) {
        std::cerr << "\nERROR! Number of columns should be greater than 0. Exiting!" << std::endl;  // Check for number of cols > 0
        exit(1);
    }
    std::cout << "\nNo of rows, cols = " << rows << "x" << cols<<std::endl;

    mat.resize(rows);
    for (auto &c:mat){
        c.resize(cols);
    }
    std::cout << "\nGenerating Random Matrix!" << std::endl;

    for (auto &r:mat){
        for (auto &e:r){
        e =  distribution(generator);
        }
    } 
     
}
