#include<iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/unsupported/Eigen/CXX11/Tensor>


using namespace std;

int main()
{

Eigen::Tensor<float, 3> m(3,10,10);

const Eigen::Tensor<double,3> tens1;

Eigen::Tensor<double,3>tens2 ;

tens2 = const_cast<Eigen::Tensor<double,3> &> (tens1);


cout << "test1" << endl;

return 0;

}