


#include"account.h"
#include"savingsaccount.h"
#include<string>
#include<cstdint>
#pragma once
#include <list>
#include <iterator>

class SavingsAccountDb:public SavingsAccount
{
    std::list <SavingsAccount> savings;
public:
    void addCustomer(std::string,std::string,double);
    void removeCustomer(std::string);
    SavingsAccount* findCustomerByNo(std::string);
    int countAll();
    double computeMaxBalance();


};


