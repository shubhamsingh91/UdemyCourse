#ifndef _MONSTER_H_
#define _MONSTER_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <array>
#include "Creature.hpp"
#include <random>

using namespace std;

class Monster: public Creature{
    using Creature::Creature; // for access to constructors
      public:
        enum Type{dragon,orc,slime,max_types = 3};
      private:
        static const Creature& getDefaultCreature(Type type) {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
            { { "dragon", 'D', 20, 4, 100 },
            { "orc", 'o', 4, 2, 25 },
            { "slime", 's', 1, 1, 10 } }
        };

        return monsterData.at(static_cast<std::size_t>(type));
        }

     public:   
    // constructors
    Monster(){}
    Monster(Type type):Creature(getDefaultCreature(type)){}
    static Creature getRandomMonster(){
  	std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<> die3{ 0, 2 }; 
      return Creature(getDefaultCreature(static_cast<Type>(die3(mt))));
    }
    ~Monster(){}

};



#endif