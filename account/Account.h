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
   
   Account()
    :name{"Un-named"},balance{0.0}{};  // initializing the regular constructor here

    // overloaded constructor 
   
    Account(std::string name_val, double bal_val);  // Default parameters

    // copy constructor 

    Account(const Account &source); 

    bool deposit(double bal);
    bool withdraw(double bal);
    void set_balance(double bal);
    double get_balance() const;
    void set_name(std::string str_name);
    std::string get_name() const;

    // Destructors
    ~Account();

};

// Account class member functions definition


// over-loaded constructor- initialized by a list, with default parameters
 Account::Account(std::string name_val, double bal_val)
    : name{name_val}, balance{bal_val}{

      //  cout << "Default 2 arg constructor called" << endl;
}

// Definition of copy-constructor- used when object is passed by value

Account::Account(const Account &source)
    : name{source.name}, balance{source.balance}
{
  //  cout << "copy constructor called" << endl;

}

bool Account:: deposit(double bal) 
{balance+=bal; 
cout << "Deposited "<< bal << " in " << name << "'s Account!" << endl;
return 1;
}

bool Account:: withdraw(double bal)
{
    if(balance>=bal)
    {
    balance -=bal;
        cout << "Withdrew " << bal << " from " << name << "'s Account!" << endl;
        return true;
    }else
    {
         cout << "Failed withdrawl in " << name <<"'s Account! Balance: " << balance << endl;
       
        return false;
    };
}

void Account::set_balance(double bal)
{
    balance = bal;
}

double Account::get_balance() const
{
    return balance;
}

void Account::set_name(string str_name)
{
    name = str_name;
}

string Account::get_name() const
{
    return name;
}

 Account::~Account()
{
  //  cout << "Destructor called here!" << endl;

}



#endif