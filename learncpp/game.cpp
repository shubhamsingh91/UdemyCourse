#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Player.hpp"
#include "Monster.hpp"

using std::cout;
using std::endl;

class Game{

 private:
  char action;

 public:
 Game(){};
 void run_game(){
  	std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<> toss{ 0, 1 }; // 0 for escape, 1 for getting attack

    string name;
    cout << "Enter Player Name:" << endl;
    cin >> name;
    Player p(name);
    cout << "Welcome " << p.getName() << ".\n You have " << p.getHealth() 
       << " health and are carrying " << p.getGold() << " gold." << endl;  
    
    while ((!p.hasWon())&&(!p.isDead())){

     Creature m1 = Monster::getRandomMonster();
     std::cout << "A " << m1.getName() << " (" << m1.getSymbol() << ") was created.\n";
      
        while (!m1.isDead()){
        cout << "Enter player Action: Run(R) or Fight(F): " << endl;
        cin  >> action;
        if (action=='R'){
            int decision=toss(mt);
            if(decision==0){// escapes
                cout << "Player escapes!" << endl;
                break;

            }else{ cout<<"Player couldn't escape! Monster attacks!" << endl;
                MonsterAttacks(p,m1);    
            }

        }else if(action=='F')
        {   m1.reduceHealth(p.getDamage());
            if(m1.isDead()){
            p.addGold(m1.getGold());
            p.levelUp();           
            cout << "Monster dead! Player level up, Player gold = " << p.getGold() << endl;
            }else{
               cout << "Monster not dead, attacks player!" << endl;
                MonsterAttacks(p,m1);    
            }
        }
        else{cout << "Wrong action selected! Exiting!" << endl;
        break;}

        if  (p.isDead()){
            cout << "Player Dead!" << endl;
            cout << "level =" << p.getlevel() << " Gold = " << p.getGold() << endl;
            break;
        }
        if(p.hasWon()){
            cout << "Player Won!" << endl;
            cout << " Gold = " << p.getGold() << endl;
            break;
        }
    
        }

        }
       
 
    }
 
 void MonsterAttacks(Player &p, Creature &m){
     p.reduceHealth(m.getDamage());
     cout << "Player health = " << p.getHealth() << endl;

 }

 ~Game(){};



};

int main(){

  Game g;
  g.run_game();

    return 0;


}