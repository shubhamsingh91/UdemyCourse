#include<vector>
#include "Account.h"
#include "Saving_account.h"

// Helper functions for Account

void display(std::vector<Account> &accounts)
{
    std::cout << "----------------------------- -----------------" << std::endl;
    std::cout << "-------------Accounts Details -----------------" << std::endl;
    for (auto const &acc : accounts)
    {
        std::cout << "["<<acc.get_name() << " , Balance: " << acc.get_balance() << "]"<< std::endl;
    }
    std::cout << "----------------------------- -----------------" << std::endl;

}

void deposit(std::vector<Account> &accounts, double amt)
{
    for (auto &acc : accounts)
    {
        acc.deposit(amt);
    }


}

void withdraw(std::vector<Account> &accounts, double amt)
{
    for (auto &acc : accounts)
    {
        acc.withdraw(amt);
    }


}


// Helper functions for Saving's accounts


void display(std::vector<Saving_Acc> &saving_acc)
{
    std::cout << "----------------------------- -----------------" << std::endl;
    std::cout << "-------------Saving Accounts Details ----------" << std::endl;
    for (auto const &sav_acc : saving_acc)
    {
        std::cout << "["<< sav_acc.get_name() << " , Balance: " << sav_acc.get_balance() << " , Int. Rate: "<<
            sav_acc.get_rate()<< "]"<<std::endl;
    }
    std::cout << "----------------------------- -----------------" << std::endl;

}



void deposit(std::vector<Saving_Acc> &accounts, double amt)
{
    for (auto &acc : accounts)
    {
        acc.deposit(amt);
    }


}

void withdraw(std::vector<Saving_Acc> &accounts, double amt)
{
    for (auto &acc : accounts)
    {
        acc.withdraw(amt);
    }


}






