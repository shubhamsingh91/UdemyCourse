#ifndef _CREATURE_H_
#define _CREATURE_H_

#include<iostream>
#include<stdio.h>
#include <string>

using namespace std;

class Creature{
    protected:

    std::string name;
    char symbol;
    int health;
    int damage;
    int gold;

    public:

    // constructors
    Creature(){}
    Creature(string n):name{n}{}
    Creature(string n,char s, int h, int d, int g):name{n}, 
                        symbol{s},health{h},damage{d},gold{g}{}

     // getters
        string getName() const {return name;}
        char getSymbol() const {return symbol;}
        int getHealth() const {return health;}
        int getDamage() const {return damage;}
        int getGold() const {return gold;}

     // other functions
      void reduceHealth(int r){ health-=r; }
      void addGold(int g){ gold+=g;}
      bool isDead(){
        if (health<=0) return true;
        else return false;
      }

      
     ~Creature(){}

};



#endif