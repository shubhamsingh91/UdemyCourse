#include <iostream>
#include <cmath>

class Point2d{
  
  private:
    double m_x{0.0}, m_y{0.0};

  public:
   Point2d(){};
   Point2d(const double& x, const double& y):m_x{x},m_y{y}{};
   Point2d(const Point2d& other){
    std::cout << "copy " << std::endl;
    m_x = other.m_x;
    m_y = other.m_y;
   }

   double distanceTo(const Point2d& other){
    return std::sqrt((m_x-other.m_x)*(m_x-other.m_x) + (m_y - other.m_y)*(m_y - other.m_y));
 
   } 
   void print(){
    std::cout << "x = " << m_x << " y = " << m_y << std::endl;
   } 
   Point2d& ret_obj(){
    return *this;
   }
   Point2d ret_obj_v2(){
    return *this;
   }
   ~Point2d(){};

};

int main()
{
   
   Point2d first{};
   Point2d second{3.0, 4.0};

//    Point2d third{4.0};

   first.print();
   second.print();
   std::cout << "distance bw the points 1 and 2 is =" << first.distanceTo(second) << std::endl; 
   
   std::cout << "add of second = " << &(second) << std::endl;
   std::cout << "add of second = " << &(second.ret_obj()) << std::endl;
//    std::cout << "add of second = " << &(second.ret_obj_v2()) << std::endl;
   auto temp = second.ret_obj_v2();
   std::cout << "add of temp = " << &(temp) << std::endl;

   auto &third {second.ret_obj()};
   std::cout << "add of third = " << &(third.ret_obj()) << std::endl;

   third.print();
    
    return 0;
}