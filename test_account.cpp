#include <iostream>
#include <stdio.h>
#include "Account.h"
#include "Saving_account.h"
#include "Trust_account.h"
#include "checking_account.h"
#include "Account_utils.h"
#include <vector>

using namespace std;

int main()
{
   
   vector<Account> accounts;

    Account acc1 {"Shubham",1000};
    Account acc2 {"Amit",700};
    Account acc3 {"Raj",400};
    Account acc4;

    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);
    accounts.push_back(acc4);

    deposit(accounts,500);
    withdraw(accounts,1000);
    
    display(accounts);

   vector<Saving_Acc> sav_accounts;
    sav_accounts.push_back(Saving_Acc {"John",1000.0,5.0});
    sav_accounts.push_back(Saving_Acc {"Jack",100.0,7.5});
    sav_accounts.push_back(Saving_Acc {"Joe",630.0,6.7});
    
    deposit(sav_accounts,500);
    withdraw(sav_accounts,800);

    display(sav_accounts);

 // Testing Trust account here

    Trust_Acc trust1{"Curry",700,5};

    trust1.deposit(50);
    trust1.withdraw(500);
    trust1.deposit(5000);

  // Testing checking account here

     Checking_Acc check1{"Moe", 450};
     check1.deposit(40);
     check1.withdraw(60);
    std::cout <<"balance = " <<  check1.get_balance() << std::endl;



}