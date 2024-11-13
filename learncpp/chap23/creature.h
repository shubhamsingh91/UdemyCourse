#ifndef _CREATURE_H_
#define _CREATURE_H_

#include <iostream>
#include <string>
#include "Point2D.h"
using namespace std;

class Creature{

    private:
        std::string name;
        Point2D loc;

    public:
        Creature():name{""},loc{Point2D{0,0}}{};
        Creature(std::string n, Point2D l):name{n},loc{l}{};

        friend std::ostream & operator << (std::ostream & out, const Creature& c) {
            cout << c.name << "is at " << c.loc;
            return out;
        }
        void moveTo(uint16_t x, uint16_t y) {
            loc.setpoint(x,y);
        }

        ~Creature(){};

};


#endif