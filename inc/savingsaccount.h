#ifndef SavingsAccount_H_INCLUDED
#define SavingsAccount_H_INCLUDED
#include "account.h"

class SavingsAccount : public AccountBase {

  double m_balance;

  public:
  SavingsAccount();
  SavingsAccount(std::string,std::string,double);

  void debit(double);
  void credit(double);
  double getBalance() const;
  void display() ;
  std::string getName() const;
  std::string getNumber() const;

};


#endif // SavingsAccount_H_INCLUDED
