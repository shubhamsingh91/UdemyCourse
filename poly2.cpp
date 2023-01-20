#include <iostream>
#include <stdio.h>

using namespace std;

class Account
{
    public:
    virtual void withdraw(double amt) // can be over-ridden throughout in derived classes
    {
        cout << "Account::withdraw" << endl;
    };
    virtual  ~Account(){cout << "Account destructor!" << endl;};

};

class Savings: public Account
{
    public:
     void withdraw(double amt)
    {
        cout << "Savings::withdraw" << endl;
    };
    virtual  ~Savings(){cout << "Savings destructor!" << endl;};


}; 

class Checking: public Account
{
    public:
      void withdraw(double amt)
    {
        cout << "Checking::withdraw" << endl;
    };

        virtual  ~Checking(){cout << "Checking destructor!" << endl;};

}; 

class Trust: public Savings
{
    public:
      void withdraw(double amt)
    {
        cout << "Trust::withdraw" << endl;
    };
        virtual  ~Trust(){cout << "Trust destructor!" << endl;};


}; 


int main()
{

    Account *p1 = new Account(); // coming to derived class via a base class pointer or reference
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    Checking *p5 = new Checking();

    Account *ptr[] = {p1,p2,p3,p4};

    for(auto i=0;i<4;i++)
    {
        ptr[i]->withdraw(1000);
    }
    p5->withdraw(1000);


    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

