#include<iostream>
#include <stdio.h>
#include <string>

using namespace std;

template<typename T>
class Pair1{
private:
 T f;
 T s;

 public:
  Pair1(){};
  Pair1(T f, T s):f{f},s{s}{};
  T first() const {return f;};
  T second() const {return s;};
 ~Pair1(){};

};

template<typename T1, typename T2>
class Pair{
private:
 T1 f;
 T2 s;

 public:
  Pair(){};
  Pair(T1 f, T2 s):f{f},s{s}{};
  T1 first() const {return f;};
  T2 second() const {return s;};
 ~Pair(){};

};

template<typename T>
class StringValuePair: public Pair<std::string,T>{

 public:
 StringValuePair(){}
 StringValuePair(std::string f, T s):Pair<std::string,T>(f,s){}
 ~StringValuePair(){}
 

};

int main(){
 
  Pair1<int> p1 {5,8};
  cout << "Pair: " << p1.first() <<" " << p1.second() << std::endl;

  Pair1<double> p2 {2.3,4.5};
  cout << "Pair: " << p2.first() <<" " << p2.second() << std::endl;

   Pair<int,double> p3{5,6.7};
    cout << "Pair: " << p3.first() <<" " << p3.second() << std::endl;
  
  StringValuePair<int> svp {"Hello world",45};
  cout << "svp :" << svp.first() <<" " << svp.second() << std::endl;

    return 0;
}