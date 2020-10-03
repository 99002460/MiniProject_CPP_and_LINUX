#ifndef CREDITACCOUNT_H_INCLUDED
#define CREDITACCOUNT_H_INCLUDED
#include "account.h"

class CreditAccount : public AccountBase {

  double m_balance;

  public:
  CreditAccount();
  CreditAccount(std::string,std::string,double);

  void debit(double);
  void credit(double);
  double getBalance() const;
  void display() ;
  std::string getName() const;
  std::string getNumber() const;


};


#endif // CREDITACCOUNT_H_INCLUDED

