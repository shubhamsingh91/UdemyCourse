#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "dog.h"
#include "Account.h"
using namespace std;

// class practice

class Player{
private:
 // attributes
    string name {"Player"};
    int health {100};
    int xp {3};

 // methods
public:
    void talk(string text_to_say) {cout << name << " says "<< text_to_say << endl;};
    bool is_dead() ;

};


void disp_account(Account acc);

int main() {


    Player Shubham;
    Player hero;

    Shubham.talk("Hi there enemy!");


    Player *enemy {nullptr};
    enemy = new Player;

    enemy->talk("Hi there Shubham!");


    delete enemy;

    cout << "------------------------------" << endl;


//---------- Account

Account frank_acc;



cout << frank_acc.get_name() <<"'s balance is: " << frank_acc.get_balance() << endl;
frank_acc.set_name("Frank");
frank_acc.deposit(1000);
frank_acc.withdraw(1544);
cout << frank_acc.get_name() <<"'s balance is: " << frank_acc.get_balance() << endl;

Account jim_acc("Jim",140); // called with 2 arguements here
//jim_acc.set_name("Jim");
cout<< jim_acc.get_name() << endl;
cout<< jim_acc.get_balance() << endl;

Account bill_acc("Bill",120);
cout<< bill_acc.get_name() << endl;
cout<< bill_acc.get_balance() << endl;

// calling the disp_account function here

disp_account(bill_acc);

Account new_acc {bill_acc};

// Dog
cout << "---------------------------------------------------" << endl;

Dog spot;
Dog fido("Fido",4);
cout << spot.get_name() << endl;
cout <<spot.get_age() << endl;
cout << fido.get_name() << endl;
cout <<fido.get_age() << endl;

spot.set_name("spot");
cout << spot.get_name() << endl;
spot.set_age(5);
cout <<spot.get_age() << endl;
cout <<"human age is" << spot.get_human_years() << endl;
spot.speak();

Dog twin {spot};

return 0;

}

void disp_account(Account acc)
{
    cout << "acc.name is" << acc.get_name() << endl;
    cout << "acc.balance is" << acc.get_balance() << endl;
}
