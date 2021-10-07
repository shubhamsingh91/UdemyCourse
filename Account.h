// Account class declaration

#include<stdio.h>
#include<iostream>
#include<string>
#ifndef _ACCOUNT_H_  // include guards for Account class
#define _ACCOUNT_H_

using namespace std;

class Account {
private:
    // attributes
    std::string name ;
    double balance;

    // methods
public:
    // two overloaded constructors 
   
    Account(std::string name_val="None", double bal_val=0.0);  // Default parameters

    // copy constructor 

    Account(const Account &source); 

    bool deposit(double bal);
    bool withdraw(double bal);
    void set_balance(double bal);
    double get_balance();
    void set_name(std::string str_name);
    std::string get_name();

    // Destructors
    ~Account();

};


// over-loaded constructor- initialized by a list, with default parameters
 Account::Account(std::string name_val, double bal_val)
    : name{name_val}, balance{bal_val}{

        cout << "Default 3 arg constructor called" << endl;
}

// Definition of copy-constructor- used when object is passed by value

Account::Account(const Account &source)
    : name{source.name}, balance{source.balance}
{
    cout << "copy constructor called" << endl;

}

bool Account:: deposit(double bal) {balance+=bal; 
cout << bal << " Deposited in " << name << "'s Account!" << endl;
return 1;
}

bool Account:: withdraw(double bal)
{
    if(balance>=bal)
    {
    balance -=bal;
        cout << bal << " withdrawn from " << name << "'s Account!" << endl;
        return true;
    }else
    {
         cout << "Insufficient balance! Balance: " << balance << endl;
       
        return false;
    };
}

void Account::set_balance(double bal)
{
    balance = bal;
}

double Account::get_balance()
{
    return balance;
}

void Account::set_name(string str_name)
{
    name = str_name;
}

string Account::get_name()
{
    return name;
}

 Account::~Account()
{
    cout << "Destructor called here!" << endl;

}



#endif