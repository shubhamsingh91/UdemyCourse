#include<iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/unsupported/Eigen/CXX11/Tensor>

#include <boost/fusion/tuple.hpp>
#include <string>
#include <boost/fusion/include/tuple.hpp>

#include <boost/fusion/tuple/tuple.hpp>
using namespace boost::fusion;
 using namespace std;

int main()
{


//  boost::fusion::tuple <int, std::string, bool, double> tuple_type{10, "Boost", true, 3.14};

 typedef  boost::fusion::tuple <int, std::string, bool, double> tuple_type;
 tuple_type t{10, "Boost", true, 3.14};
  std::cout << get<0>(t) << '\n';
  std::cout << get<1>(t) << '\n';
  std::cout << get<2>(t) << '\n';
  std::cout << get<3>(t) << '\n';

Eigen::Tensor<float, 3> m(3,10,10);

const Eigen::Tensor<double,3> tens1;

Eigen::Tensor<double,3>tens2 ;

tens2 = const_cast<Eigen::Tensor<double,3> &> (tens1);


cout << "test1" << endl;

return 0;

}