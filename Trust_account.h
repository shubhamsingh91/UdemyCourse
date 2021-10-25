#ifndef _TRUST_ACCOUNT_H_  // include guards for Account class
#define _TRUST_ACCOUNT_H_

#include "Account.h"

class Trust_Acc:public Account{

    private:

    double int_rate;
    int withdraw_count;

    public:

    Trust_Acc();
    Trust_Acc(std::string name_in, double balance_in, double int_rate_in);

    bool deposit(double amt);
    double get_rate() const;
    int get_withdraw_count() const;

    bool withdraw(double amt);

    ~Trust_Acc();

};


Trust_Acc::Trust_Acc()
{}

Trust_Acc::Trust_Acc(std::string name_in, double balance_in, double int_rate_in)
    : Account {name_in,balance_in},int_rate{int_rate_in},withdraw_count{0}
    {

    }

bool Trust_Acc::deposit(double amt)
{
    if(amt > 0)
    {
        if (amt >=5000) // add 50 bonus if the amount is over 5000
        {
            amt+=50+(amt*int_rate/100);

        }else {
            amt+=amt*int_rate/100;
        }

        return Account::deposit(amt);

    } else 
    {
        return false;
    }
}

bool Trust_Acc::withdraw(double amt)
{
    double balance;
    balance = Account::get_balance();
    if((withdraw_count<=3)&&(amt <= 0.2*balance))
    {
        withdraw_count+=1;
        cout << 3-withdraw_count << " withdrawl counts left!" << endl;
        return Account::withdraw(amt);
    }else
    {
        cout << "Failed withdrawl in " << Account::get_name() <<"'s Account! Balance: " << Account::get_balance() << endl;
        return false;
    }

}

double Trust_Acc::get_rate() const
{
    return int_rate;
} 

int Trust_Acc::get_withdraw_count() const
{
    return withdraw_count;
}

Trust_Acc::~Trust_Acc()
{}

#endif