#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<iostream>
#include<stdio.h>
#include <string>

using namespace std;

class Player: public Creature{
    using Creature::Creature; // for access to constructors
    private:
     int level;

    public:

    // constructors
    Player(){}
    Player(string n):Creature{n,'@',10,1,0},level{1}{}  

    // member functions  
    void levelUp(){level+=1;damage+=1;}  
    int getlevel(){return level;}
    bool hasWon(){
        if (level>=20) return true;
        else return false;
    }
     ~Player(){}

};



#endif