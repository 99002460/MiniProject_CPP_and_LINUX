#include <iostream>
#include "savingsaccount.h"
SavingsAccount::SavingsAccount():AccountBase("",""),m_balance(0.0) { }
SavingsAccount::SavingsAccount(std::string num,std::string name, double balance):AccountBase(num,name),m_balance(balance) {}



void SavingsAccount::debit(double balance)
{
    m_balance-=balance;
}
void SavingsAccount::credit(double balance)
{
    m_balance+=balance;
}
double SavingsAccount::getBalance() const
{

    return m_balance;
}

void SavingsAccount::display()
{
    cout<<"Credit Account:";
     std::cout<<getName()<<" "<<getNumber()<<" "<<getBalance()<<std::endl;
}
std::string SavingsAccount::getNumber() const
{
    return m_accNumber;
}
std::string SavingsAccount::getName() const
{
    return m_accName;
}



