#include"creditaccountDb.h"
#include"account.h"
#include"CreditAccount.h"

void CreditAccountDb::addCustomer(std::string number,std::string name,double balance){

credits.push_back(CreditAccount(number,name,balance));

}

void CreditAccountDb::removeCustomer(std::string number){

std::list<CreditAccount> :: iterator iter;

    for(iter=credits.begin();iter!=credits.end();iter++)
    {
        if(iter->getNumber()== number)
        {
           credits.erase(iter);
           break;
        }
    }


}

CreditAccount* CreditAccountDb::findCustomerByNo(std::string number)
{

    std::list<CreditAccount> :: iterator iter;
    for(iter=credits.begin();iter!=credits.end();iter++)
    {
        if(number==iter->getNumber())
        {
           return &(*iter);
        }
    }
    return NULL;

}

int CreditAccountDb::countAll()
{

    return credits.size();
}

double CreditAccountDb::computeMaxBalance()
{
    std:: list<CreditAccount> :: iterator iter = credits.begin();
    auto maxBal  = iter->getBalance();
   // auto maxiter = iter;
    iter++;
    for(;iter!=credits.end();++iter)
    {
        if(maxBal < iter->getBalance())
        {
            maxBal = iter->getBalance();
           // maxiter = iter;
        }

    }
    return maxBal;


}
