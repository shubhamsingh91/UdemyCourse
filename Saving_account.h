#ifndef _SAVING_ACCOUNT_H_  // include guards for Account class
#define _SAVING_ACCOUNT_H_

#include "Account.h"

class Saving_Acc:public Account{

    private:

    double int_rate;

    public:

    Saving_Acc();
    Saving_Acc(std::string name_in, double balance_in, double int_rate_in);

    bool deposit(double amt);
    double get_rate() const;
    // withdrawn in inherited

    ~Saving_Acc();

};


Saving_Acc::Saving_Acc()
{}

Saving_Acc::Saving_Acc(std::string name_in, double balance_in, double int_rate_in)
    : Account {name_in,balance_in},int_rate{int_rate_in}
    {

    }

bool Saving_Acc::deposit(double amt)
{
    if(amt > 0)
    {
        amt+=amt*int_rate/100;
        
        return Account::deposit(amt);

    } else 
    {
        return false;
    }
}   

double Saving_Acc::get_rate() const
{
    return int_rate;
} 

Saving_Acc::~Saving_Acc()
{}

#endif