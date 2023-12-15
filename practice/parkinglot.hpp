#ifndef _PARKINGLOT_H_
#define _PARKINGLOT_H_
#include <iostream>

using namespace std;

class Parkinglot{


private:
 int max_lim=50;
 int m_spots=20,l_spots=10;
 int car_regular=10, car_compact=10;

public:
 Parkinglot(){}
 int getspots(){return (m_spots+car_regular+car_compact+l_spots);}
 int getmotorcycle_spots(){return (m_spots);}
 int getcarspots(){return (car_regular+car_compact);}
 int getlargespots(){return (l_spots);}

 bool parkingfull(){
    if ((m_spots+car_regular+car_compact+l_spots)<=max_lim)
    {return true;}
    else {return false;}
 }

 bool parkingempty(){
    if ((m_spots+car_regular+car_compact+l_spots)==0){
        return true;
    }else{
        return false;
    }
 }

 void parkMotorcycle(){
    if(m_spots>0){
        m_spots=m_spots-1;
    }else if (car_compact>0){
        car_compact=car_compact-1;
    }else if(car_regular>0){
        car_regular=car_regular-1;
    }else if (l_spots>0){
        l_spots=l_spots-1;
    }else{
        std::cout << "Parking full!" << std::endl;
    }

 }

 void parkCar(){
    if(car_compact>0){
        car_compact=car_compact-1;
    }else if(car_regular>0){
        car_regular=car_regular-1;
    }else if(l_spots>0){
        l_spots=l_spots-1;
    }else{
        std::cout << "Parking full!" << std::endl;
    }
 }

 void parkVan(){
    if(l)
 }

 ~Parkinglot(){}




};



#endif