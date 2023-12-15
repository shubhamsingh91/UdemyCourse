#include <gtest/gtest.h>
#include "functions.cpp"
#include <vector>
#include <iostream>

/*Author- Shubham Singh
Contact- singh281@utexas.edu
*/

/*This is a unit-test for the accuracy of the process_matrix function.
Several cases are shown here, from single row and column matrix, to a 2x2 zero matrix, 
and a 3x3 matrix from the problem statement.
*/
 TEST(ProcessMatrixTest,Accuracy ){
     // Test with a 3x3 matrix
    std::vector<std::vector<int>> matrix {{1,0,0},{0,0,0},{0,1,0}};
    process_matrix(matrix);

    EXPECT_EQ(matrix.size(), 3);
    EXPECT_EQ(matrix[0].size(), 3);

    EXPECT_EQ(matrix[0][0], 1);
    EXPECT_EQ(matrix[0][1], 1);
    EXPECT_EQ(matrix[0][2], 1);

    EXPECT_EQ(matrix[1][0], 1);
    EXPECT_EQ(matrix[1][1], 1);
    EXPECT_EQ(matrix[1][2], 0);
     
    EXPECT_EQ(matrix[2][0], 1);
    EXPECT_EQ(matrix[2][1], 1);
    EXPECT_EQ(matrix[2][2], 1);

   // Test with a 2x2 zero matrix
    std::vector<std::vector<int>> zeromatrix {{0,0},{0,0}};
    process_matrix(zeromatrix);

    EXPECT_EQ(zeromatrix.size(), 2);
    EXPECT_EQ(zeromatrix[0].size(), 2);

    EXPECT_EQ(zeromatrix[0][0], 0);
    EXPECT_EQ(zeromatrix[0][1], 0);

    EXPECT_EQ(zeromatrix[1][0], 0);
    EXPECT_EQ(zeromatrix[1][1], 0);

     // Test with a 1x2 matrix
    std::vector<std::vector<int>> vec2 {{0,1}};
    process_matrix(vec2);

    EXPECT_EQ(vec2.size(), 1);
    EXPECT_EQ(vec2[0].size(), 2);

    EXPECT_EQ(vec2[0][0], 1);
    EXPECT_EQ(vec2[0][1], 1);

    // Test with a 2x1 matrix
    std::vector<std::vector<int>> row2 {{0},{1}};
    process_matrix(row2);

    EXPECT_EQ(row2.size(), 2);
    EXPECT_EQ(row2[0].size(), 1);

    EXPECT_EQ(row2[0][0], 1);
    EXPECT_EQ(row2[1][0], 1);
 }

/*This is a unit-test for the accuracy of the print_matrix function
Two cases are shown here- a zero matrix and a 3x3 matrix.
*/
 TEST(PrintMatrixTest, OutputCheck) {
    // Test with an zero matrix
    std::vector<std::vector<int>> zeromatrix;
    std::stringstream expectedOutput;
    expectedOutput << std::endl;

    std::stringstream outputCapture;
    std::streambuf* originalCoutBuf = std::cout.rdbuf(outputCapture.rdbuf());

    print_matrix(zeromatrix);

    std::cout.rdbuf(originalCoutBuf);

    std::string output = outputCapture.str();
    EXPECT_EQ(output, expectedOutput.str());

    // Test with a 3x3 matrix
    std::vector<std::vector<int>> matrix = {{1,1,1}, {2,2,2},{3,3,3}};
    std::stringstream expectedOutput2;
    expectedOutput2 << "1 1 1" << std::endl << "2 2 2" << std::endl << "3 3 3" << std::endl;

    std::stringstream outputCapture2;
    std::streambuf* originalCoutBuf2 = std::cout.rdbuf(outputCapture2.rdbuf());

    print_matrix(matrix);

    std::cout.rdbuf(originalCoutBuf2); 

    std::string output2 = outputCapture2.str();
    EXPECT_EQ(output2, expectedOutput2.str());
}

/*This is a unit-test for the accuracy of the input_matrix function for a 2x2 input
*/
 TEST(InputMatrixTest,MatrixInput ){
     // Test with a 2x2 matrix
    std::stringstream input;
    input << "2" << std::endl << "2" << std::endl << "1 0" << std::endl << "0 1" << std::endl;
    std::istringstream inputString(input.str());
    std::streambuf* originalCinBuf = std::cin.rdbuf(inputString.rdbuf());

    std::vector<std::vector<int>> matrix;
    input_matrix(matrix);

    std::cin.rdbuf(originalCinBuf); 
    EXPECT_EQ(matrix.size(), 2);
    EXPECT_EQ(matrix[0].size(), 2);
    EXPECT_EQ(matrix[0][0], 1);
    EXPECT_EQ(matrix[0][1], 0);
    EXPECT_EQ(matrix[1][0], 0);
    EXPECT_EQ(matrix[1][1], 1);
 }

/*This is a unit-test for the accuracy of the input_matrix function for a 2x2 input with negative no of rows
*/
 TEST(InputMatrixTest,negativerows ){
     // Test with a row size as -1
    std::stringstream input;
    input << "-1" << std::endl << "2" << std::endl << "1 0" << std::endl << "0 1" << std::endl;
    std::istringstream inputString(input.str());
    std::streambuf* originalCinBuf = std::cin.rdbuf(inputString.rdbuf());

    std::vector<std::vector<int>> matrix;
     
     std::stringstream outputCapture;
    std::streambuf* originalCoutBuf = std::cout.rdbuf(outputCapture.rdbuf());


    input_matrix(matrix);
    std::cout.rdbuf(originalCoutBuf); // Restore cout's original stream buffer

    std::string output = outputCapture.str();
    EXPECT_EQ(output, "ERROR: Number of rows should be greater than 0!\n");
 }


 int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}