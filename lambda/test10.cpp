#include <iostream>
#include <algorithm>
#include <memory>
#include "../utils.h"
#include "../inheritence/base2.h"
#include "../inheritence/derived2.h"
#include <eigen3/Eigen/Dense>

template <typename T, int r, int c>
void printMat(const Eigen::Matrix<T,r,c>& mat){

    for (int i = 0; i < mat.rows(); ++i)
    {
        for (int j = 0; j < mat.cols(); ++j){
            std::cout << mat(i,j) << " ";
        }
        std::cout << std::endl;
    }

}
template<typename T>
void printMatd(const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> &mat){
    for (int i = 0; i < mat.rows(); ++i)
    {
        for (int j = 0; j < mat.cols(); ++j){
            std::cout << mat(i,j) << " ";
        }
        std::cout << "\n";
    }

}

using Vecd = Eigen::VectorXd;
using Matd = Eigen::MatrixXd;
using Vec2d = Eigen::Vector2d;
using Mat2d = Eigen::Matrix2d;

int main()
{

  Eigen::MatrixXd mat1(3,3);
  mat1 << 1,2,3,4,5,6,7,8,9;

  Eigen::Matrix<double,2,3,Eigen::RowMajor> mat2;
  mat2 << 1,2,3,4,5,6; 

  auto mat3 = Eigen::Matrix2d::Zero();

  print(mat1);
  print("mat2 = ");
  print(mat2);
  print("mat3 ");
  printMatd<double>(mat3);

  /*
  Create a 4x4 Eigen matrix and use a lambda function to compute the sum of squares of each row. Store the results in an Eigen vector.
  */  
   Eigen::Matrix4f mat4;
   mat4.setRandom();
   print("mat4 = ");
   printMatd<float>(mat4);
   
   auto lam_eigen1 = [&mat4](){
    Eigen::VectorXf vec = mat4.rowwise().squaredNorm();
    return vec;

   };

   auto vec1 = lam_eigen1();
   print("vec1 = ");
   printMatd<float>(vec1);

   

   /*3. Filtering Matrix Elements
    Generate a random 5x5 Eigen matrix and use a lambda function to set all elements less than 0.5 to zero.
    */

   Eigen::MatrixXd mat5(5,5);
   mat5.setRandom();
   print("mat5 = ");
   printMatd<double>(mat5);

    mat5 = mat5.unaryExpr([](double d){return (d<0.5) ? 0.0 : d;}); // passed by value in unaryexpr

   print("\nafter filtering");
   printMatd(mat5);

    /*4. Dot Product with Lambda

    Create two Eigen vectors, v1 and v2. Use a lambda function to calculate their dot product and display the result.
    */
   Vecd v1(10), v2(10);
   v1.setRandom();
   v2.setRandom();

   auto lam_dot = [](const Vecd &v1, const Vecd &v2){ return v1.dot(v2);};

   print("v1 = ");
   printMatd<double>(v1);

   print("v2 = ");
   printMatd<double>(v2);

   print("v1 dot v2 = ", lam_dot(v1,v2));

 
    /*
    5. Matrix Scaling

    Write a program that uses a lambda function to scale all elements of an Eigen matrix by a given scalar value.
    */
   Matd mat6(4,6);
   mat6.setConstant(1.2);
   print("mat6 = ");
   printMatd<double>(mat6);

   auto lam_scale = [](Matd& mat, const double scale){
    mat = mat.unaryExpr([&scale](double d){return d*scale;});
   };

   lam_scale(mat6, 2.1);
   print("mat6 after scale =");
   printMatd(mat6);


    /*
    6. Element-Wise Operations
    */
    // Create two Eigen matrices of the same size. Use a lambda function with the binaryExpr method to calculate the element-wise maximum of the two matrices.

    Matd mat7(5,6), mat8(5,6);
    mat7.setRandom();
    mat8.setRandom();

    print("Mat7 = ");
    printMatd(mat7);

    print("Mat8 = ");
    printMatd(mat8);

    Matd mat_result = mat7.binaryExpr(mat8, [](double a, double b){return (a>b)? a : b;});

    print("result = ");
    printMatd(mat_result);
    

    // 7. Conditional Element Replacement
    // Generate a random 4x4 Eigen matrix. Use a lambda function with unaryExpr to replace all negative elements with their absolute values.

    Matd mat9(4,4);
    mat9.setRandom();
    print("mat9 = ");
    printMatd(mat9);
    mat9 = mat9.unaryExpr([](double d){return (d < 0)? -d : d;});

    print("mat9 abs = ");
    printMatd(mat9);

    // 8. Custom Row Sorting
    // Create a 4x4 Eigen matrix with random values. Write a lambda function to sort each row of the matrix in descending order.
    Matd mat10(4,4);
    mat10.setRandom();
    print("mat10 = ");
    print(mat10);

    auto lam_sort = [](Matd &mat){
      for (int i = 0; i < mat.rows(); ++i){
        std::sort(mat.row(i).begin(), mat.row(i).end());
      }
    };

    lam_sort(mat10);
    print("mat10 = ");
    print(mat10);

    // 9. Matrix Column Normalization
    // Create a random 5x3 Eigen matrix. Use a lambda function to normalize each column so that the sum of each column equals 1.
    
    Matd mat11(5,3);
    mat11.setRandom();
    print("mat11 = ");
    print(mat11);

    auto lam_normal = [](Matd& mat){
        mat = mat.colwise().normalized();
    };
    
    lam_normal(mat11);
    print("mat11 normalised= ");
    print(mat11);

}