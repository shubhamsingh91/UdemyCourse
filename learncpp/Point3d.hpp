#ifndef _POINT3D_H_
#define _POINT3D_H_

#include<iostream>

class Point3d{

private:
 int m_x, m_y, m_z;

public:
Point3d(){}
 
 void setValues(int x, int y, int z){
    m_x = x; m_y = y; m_z = z;
 }
void print(){
    std::cout << "<" << m_x<< ", " << m_y << ", " << m_z << ">" << std::endl;
}
bool isEqual(Point3d &rhs){

    if (((*this).m_x==rhs.m_x)&&((*this).m_y==rhs.m_y)&&((*this).m_z==rhs.m_z))
     {
        return true;
     }else{
        return false;
     }

    
} 

~Point3d(){}


};







#endif