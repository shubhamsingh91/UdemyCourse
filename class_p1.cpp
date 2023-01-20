#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "dog.h"

using namespace std;

// class practice

class Player{
public:
 // attributes
    string name {"Player"};
    int health {100};
    int xp {3};

 // methods

    void talk(string text_to_say) {cout << name << " says "<< text_to_say << endl;};
    bool is_dead() ;

};

class Account {
public:
    // attributes
    string name {"Account"};
    double balance {0.0};

    // methods

    bool deposit(double bal) {balance+=bal; 
    cout << bal << " Deposited in " << name << "'s Account!" << endl;
    return 1;
    };
    
    bool withdraw(double bal)
    {

        balance -=bal;
           cout << bal << " withdrawn from " << name << "'s Account!" << endl;
            return 1;
    };

};

int main() {


    Player Shubham;
    Player hero;

    Shubham.name = "Shubham";
    Shubham.health = 100;
    Shubham.xp = 5;

    // cout << "Shubham's name is " << Shubham.name << endl;
    // cout << "Shubham's health is " << Shubham.health << endl;
    // cout << "Shubham's xp is " << Shubham.xp << endl;

    Shubham.talk("Hi there enemy!");


    Player *enemy {nullptr};
    enemy = new Player;


    enemy->health = 100;
    enemy->name = "Trishna";
    enemy-> xp = 40;

    enemy->talk("Hi there Shubham!");

    // cout << "enemy's health is " << enemy->health << endl;
    // cout << "enemy's name is " << enemy->name << endl;
  

    delete enemy;

    cout << "------------------------------" << endl;

// -----------------------Account

    Account frank_acc, jim_acc;
   
   frank_acc.name = "Frank";
    cout << "Frank's balance is: " << frank_acc.balance << endl;


    frank_acc.deposit(100.63);
      cout << "Frank's balance is: " << frank_acc.balance << endl;
  
      frank_acc.withdraw(20.65);
      cout << "Frank's balance is: " << frank_acc.balance << endl;

// ------------------------- Dog

    cout << "------------------------------" << endl;

    Dog spot;
    spot.name="Spot";
    spot.age=5;
      cout << "spot's name is: " << spot.name << endl;











return 0;

}