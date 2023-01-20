#include<iostream>
#include<stdio.h>
#include<vector>
#include "Account.h"

using namespace std;

// Making some derived classes here

class Savings_account : public Account
{
private:
double int_rate;


public:
    // std::string get_name();
    // void set_name(string name_in);

};

// // Specialized member function
// string Savings_account::get_name()
// {
//     return name;
// }

// void Savings_account::set_name(string name_in)
// {
//    // name = "test name"; // name here should be a public or protected for the base class
//    // balance = 450;
// }

int main()
{

    Account acc;

    acc.set_name("Shubham's account");
    acc.set_balance(5000);

   // acc.name = "ABE";

    Account *acc_ptr {nullptr};
    acc_ptr = new Account;
    
    acc_ptr->set_name("John's account");
    acc_ptr->set_balance(6000);

    Savings_account sav_acc ;

    sav_acc.set_name("shubham's savings");
    sav_acc.set_balance(7800);
    sav_acc.deposit(5600);

    // sav_acc.name="A";
    // sav_acc.balance=670;

    cout << "shubham's savings account name: " << sav_acc.get_name() << endl;
    cout << "shubham's savings account deopsit: " << sav_acc.get_balance() << endl;


    delete acc_ptr;

}