


#include"account.h"
#include"CreditAccount.h"
#include<string>
#include<cstdint>
#pragma once
#include <list>
#include <iterator>

class CreditAccountDb:public CreditAccount
{
    std::list <CreditAccount> credits;
public:
    void addCustomer(std::string,std::string,double);
    void removeCustomer(std::string);
    CreditAccount* findCustomerByNo(std::string);
    int countAll();
    double computeMaxBalance();


};

