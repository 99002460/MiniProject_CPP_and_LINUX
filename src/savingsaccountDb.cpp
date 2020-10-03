#include"savingsaccount.h"
#include"account.h"
#include"savingsaccountDb.h"

void SavingsAccountDb::addCustomer(std::string number,std::string name,double balance){

savings.push_back(SavingsAccount(number,name,balance));

}

void SavingsAccountDb::removeCustomer(std::string number){

std::list<SavingsAccount> :: iterator iter;

    for(iter=savings.begin();iter!=savings.end();iter++)
    {
        if(iter->getNumber()== number)
        {
           savings.erase(iter);
           break;
        }
    }


}

SavingsAccount* SavingsAccountDb::findCustomerByNo(std::string number)
{

    std::list<SavingsAccount> :: iterator iter;
    for(iter=savings.begin();iter!=savings.end();iter++)
    {
        if(number==iter->getNumber())
        {
           return &(*iter);
        }
    }
    return NULL;

}

int SavingsAccountDb::countAll()
{

    return savings.size();
}

double SavingsAccountDb::computeMaxBalance()
{
    std:: list<SavingsAccount> :: iterator iter = savings.begin();
    auto maxBal  = iter->getBalance();
   // auto maxiter = iter;
    iter++;
    for(;iter!=savings.end();++iter)
    {
        if(maxBal < iter->getBalance())
        {
            maxBal = iter->getBalance();
           // maxiter = iter;
        }

    }
    return maxBal;


}

