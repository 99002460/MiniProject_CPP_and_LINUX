#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include<string>
using namespace std;
class AccountBase {
public:
  std::string m_accNumber;
  std::string m_accName;



  public:
  AccountBase();

  AccountBase(std::string,std::string);

  virtual void debit(double)=0;
  virtual void credit(double)=0;
  virtual void display() = 0;



};
#endif // ACCOUNT_H_INCLUDED

