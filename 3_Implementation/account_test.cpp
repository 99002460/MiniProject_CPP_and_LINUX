#include "inc/account.h"
#include "inc/CreditAccount.h"
#include"inc/savingsaccount.h"
#include <gtest/gtest.h>
#include <memory>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

namespace {

TEST(CreditAccount, DefaultConstructor) {
  CreditAccount ft;
  EXPECT_EQ(0, ft.getName().length());
  EXPECT_EQ(0, ft.getNumber().length());
  EXPECT_EQ(0, ft.getBalance());

}

TEST(CreditAccount, ParameterizedConstructor) {
  AccountBase *ptr;
  ptr = new CreditAccount("9900", "Raj",800);
  CreditAccount *fptr = dynamic_cast<CreditAccount*>(ptr);
  EXPECT_STREQ("Raj", fptr->getName().c_str());
  EXPECT_STREQ("9900", fptr->getNumber().c_str());
  EXPECT_EQ(800, fptr->getBalance());

}

TEST(CreditAccount, ComputationTest) {

  AccountBase *ptr;
  ptr = new CreditAccount("9901", "Raj",800);
  CreditAccount *fptr = dynamic_cast<CreditAccount*>(ptr);
  EXPECT_STREQ("Raj", fptr->getName().c_str());
  EXPECT_STREQ("9901", fptr->getNumber().c_str());
  EXPECT_EQ(800, fptr->getBalance());
  fptr->debit(100);
  EXPECT_EQ(900, fptr->getBalance());
  fptr->credit(300);
  EXPECT_EQ(600, fptr->getBalance());


}
TEST(CreditAccount, WithoutDynamicCastTest) {

  CreditAccount fptr("9902","Raj",800);
  AccountBase *ptr=&fptr;
  EXPECT_STREQ("Raj", fptr.getName().c_str());
  EXPECT_STREQ("9902", fptr.getNumber().c_str());
  EXPECT_EQ(800, fptr.getBalance());
  ptr->debit(100);
  EXPECT_EQ(900, fptr.getBalance());
  ptr->credit(300);
  EXPECT_EQ(600, fptr.getBalance());


}



TEST(SavingsAccount, DefaultConstructor) {
  SavingsAccount ft;
  EXPECT_EQ(0, ft.getName().length());
  EXPECT_EQ(0, ft.getNumber().length());
  EXPECT_EQ(0, ft.getBalance());

}

TEST(SavingsAccount, ParameterizedConstructor) {
  AccountBase *ptr;
  ptr = new SavingsAccount("9903", "Raj",800);
  SavingsAccount *fptr = dynamic_cast<SavingsAccount*>(ptr);
  EXPECT_STREQ("Raj", fptr->getName().c_str());
  EXPECT_STREQ("9903", fptr->getNumber().c_str());
  EXPECT_EQ(800, fptr->getBalance());

}

TEST(SavingsAccount, ComputationTest) {

  AccountBase *ptr;
  ptr = new SavingsAccount("9904", "Raj",800);
  SavingsAccount *fptr = dynamic_cast<SavingsAccount*>(ptr);
  EXPECT_STREQ("Raj", fptr->getName().c_str());
  EXPECT_STREQ("9904", fptr->getNumber().c_str());
  EXPECT_EQ(800, fptr->getBalance());
  fptr->debit(100);
  EXPECT_EQ(700, fptr->getBalance());
  fptr->credit(300);
  EXPECT_EQ(1000, fptr->getBalance());


}
TEST(SavingsAccount, WithoutDynamicCastTest) {

  SavingsAccount fptr("9905","Raj",800);
  AccountBase *ptr=&fptr;
  EXPECT_STREQ("Raj", fptr.getName().c_str());
  EXPECT_STREQ("9905", fptr.getNumber().c_str());
  EXPECT_EQ(800, fptr.getBalance());
  ptr->debit(100);
  EXPECT_EQ(700, fptr.getBalance());
  ptr->credit(300);
  EXPECT_EQ(1000, fptr.getBalance());


}

} // namespace

