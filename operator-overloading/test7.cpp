#include "mystring.h"
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

class Player{
 private:

 int health;
 std::string name;
 int attack;

 public:

  Player() =delete; // will never be used
  Player(int h, int a, std::string n):health{h}, attack{a},name{n}{};
  ~Player(){};
  std::string get_name()const {return name;}
  int get_health() const{return health;};
  int get_attack() const{return attack;};

  friend std::ostream& operator<<(std::ostream & out, const Player &p){
    out<< "Name = " << p.get_name() << ", health = " << p.get_health() ;
    return out;
  }
  friend bool operator<(const Player& p1, const Player& p2){
    return (p1.health < p2.health);
  }
  friend bool operator==(const  Player& p1, const Player& p2){
    return (p1.health == p2.health)&&(p1.attack == p2.attack);
  }
  
  Player operator+(const Player& p) const {

   return Player{p.get_health()+health,
            p.get_attack()+attack,name}; 
  }

  Player& operator=(const Player& p){
    if (this== &p){
        return *this;
    }
      health=p.get_health();
      attack = p.get_attack();
      name = p.get_name();
      return *this;

      }

};

class Array{

private:
 int * arr;
 size_t len;

 public:
 Array(){
        arr = new int[len];
 };
 Array(size_t n):len{n}{
    arr = new int[len];
 }

 ~Array(){delete [] arr;};

  int& operator[](const int loc){
   assert(loc<len);
   if (loc<len){
    return arr[loc];
   }
  }

  void print(){
    for(int i=0;i<len;i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;
  }
  friend std::ostream& operator<<( std::ostream &out,  Array& a){
    
    for(int i=0;i<a.len;i++){
        out << a[i] << " ";
    }
    return out;
  }



};



int main(){

 Player p1{98,12,"shubham"};
 Player p2(78,15," John");
 Player p3{78,15, "Ryan"};

 std::cout << p1 << endl;
 std::cout << p2 << endl;

 if(p1<p2){
    cout << " p1 < p2" << endl;
 }else{
    cout << "p1 > p2" << endl;
 }

 if (p2==p3){
        cout << "p2 = p3" << endl;
 }
 cout << "------------------1----------------------------" << endl;
 Player p4=p3;

 cout << p4 << endl;
 cout << Player{87,12,"shubham"} << endl;

 cout << "------------------2---------------------------" << endl;

 Player p5{12,12,"Hey"};
 cout << p5 << endl;
 p5=p5+p3;

 cout << p5 << endl;
 cout << "------------------3---------------------------" << endl;

 Player &p6  {p4}; // p6 is a refernce to p4
 cout << p6 << endl; 
 cout << &p6 << endl;
 cout << &p4 << endl;

 cout << "------------------4---------------------------" << endl;

 Array a1(5);
 a1[0]=1;
 a1[1] = 4;
 a1[2] =5;

 //a1.print();
 
 cout << a1 << endl;

    return 0;
}