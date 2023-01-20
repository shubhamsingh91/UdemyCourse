#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "dog.h"
#include "Account.h"
using namespace std;


class Player
{

    private:
    string name;
    int xp;
    int health;


    public:
        static int num_players; // cannot initialize here- belongs to the class

    Player(string name_val="None",int xp_val=0,int health_val=0);
    string get_name() const;  // calling this method to be const correct
    void set_name(string name_in);
    ~Player();

    static int get_num_players(); // This static function has only have access to static class variables
};

Player::Player(string name_val,int xp_val,int health_val)
    :name{name_val}, xp{xp_val},health{health_val}
{   
    ++num_players;
    cout << "Constructor called!" << endl;
}

string Player::get_name() const
{
    return name;
}

void Player::set_name(string name_in)
{
    name = name_in;
}


Player::~Player()
{
    --num_players;
    cout << "Destructor!" << endl;
}

int Player::num_players {0};
int Player::get_num_players()
{
    return num_players;
}

int main()
{

{
const Player villian {"villain", 3,100};
 Player Hero {"Hero",5,200};

 cout<<   Hero.get_name() << endl;

 cout << "No of players are " << Player::get_num_players() << endl;  // calling the static class method here
 cout << "No of players are " << Player::num_players << endl;  // calling the static class method here


}
 cout << "No of players are " << Player::get_num_players() << endl;  // calling the static class method here
 cout << "No of players are " << Player::num_players << endl;  // calling the static class method here


}