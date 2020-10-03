#include"inc/creditaccountDb.h"
#include"inc/account.h"
#include"inc/CreditAccount.h"
#include <gtest/gtest.h>
namespace {

class CreditAccountDbTest:public ::testing::Test{

protected:
    void SetUp()
    {

    credits.addCustomer("9900","Raj",1000);
    credits.addCustomer("9902","Harsh",5000);
    credits.addCustomer("9903","Pruthvi",1500);
    credits.addCustomer("9904","Ramesh",1000);


    }
    void TearDown(){}
    CreditAccountDb credits;

};

TEST_F(CreditAccountDbTest,AddCustomerTest)
{
    credits.addCustomer("9901","pavan",500);
    EXPECT_NE((AccountBase*)NULL,credits.findCustomerByNo("9901"));
    EXPECT_EQ(5,credits.countAll());
}

TEST_F(CreditAccountDbTest,RemoveCustomerTest)
{
    credits.removeCustomer("9900");
    EXPECT_EQ(NULL,credits.findCustomerByNo("9900"));
    EXPECT_EQ(3,credits.countAll());


}

TEST_F(CreditAccountDbTest,CountTotalCustomerTest)
{
EXPECT_EQ(4,credits.countAll());

}


TEST_F(CreditAccountDbTest,ComputeMaxBalance)
{
double maxi=credits.computeMaxBalance();
EXPECT_EQ(5000,maxi);
}


}
