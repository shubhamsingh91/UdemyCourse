#ifndef _CHECKING_ACCOUNT_H_  // include guards for Account class
#define _CHECKING_ACCOUNT_H_

#include "Account.h"

class Checking_Acc:public Account{

    private:


    public:

    Checking_Acc();
    Checking_Acc(std::string name_in, double balance_in);

     bool withdraw(double amt);

    ~Checking_Acc();

};


Checking_Acc::Checking_Acc()
{}

Checking_Acc::Checking_Acc(std::string name_in, double balance_in)
    : Account {name_in,balance_in}
    {

    }
bool Checking_Acc::withdraw(double amt)
{
    return Account::withdraw(amt+1.50);
}
  



Checking_Acc::~Checking_Acc()
{}

#endif