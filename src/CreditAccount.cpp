
#include <iostream>
#include "CreditAccount.h"
CreditAccount::CreditAccount():AccountBase("",""),m_balance(0.0) { }
CreditAccount::CreditAccount(std::string num,std::string name, double balance):AccountBase(num,name),m_balance(balance) {}



void CreditAccount::debit(double balance)
{
    m_balance+=balance;
}
void CreditAccount::credit(double balance)
{
    m_balance-=balance;
}
double CreditAccount::getBalance() const
{

    return m_balance;
}

void CreditAccount::display()
{
    cout<<"Credit Account:";
     std::cout<<getName()<<" "<<getNumber()<<" "<<getBalance()<<std::endl;
}

std::string CreditAccount::getNumber() const
{
    return m_accNumber;
}
std::string CreditAccount::getName() const
{
    return m_accName;
}


