#include"inc/savingsaccount.h"
#include"inc/account.h"
#include"inc/savingsaccountDb.h"
#include <gtest/gtest.h>
#include<pthread.h>
#include<semaphore.h>
#include<iostream>
#include<list>
#include<iterator>
#include<cstdint>

pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;
SavingsAccountDb savings1;

void* efun1(void* pv){
	
	
	
	pthread_mutex_lock(&m1);
	
	savings1.addCustomer("9900","Raj",1000);
    	savings1.addCustomer("9902","Harsh",5000);
    	savings1.addCustomer("9903","Pruthvi",1500);
    	savings1.addCustomer("9904","Ramesh",1000);

	pthread_mutex_unlock(&m1);
	sem_post(&s1);
	
}

void* efun2(void* pv)		//consumer
{
	
	
	sem_wait(&s1);			//changing sequence lead to deadlock
	pthread_mutex_lock(&m1);
	
	std::cout<<"\n";
	std::cout<<"The producer added :"<<savings1.countAll()<<" SavingsAccountDetails\n";
	std::cout<<"\n";
	
	pthread_mutex_unlock(&m1);
	//pthread_exit(NULL);
}

namespace {

class SavingsAccountDbTest:public ::testing::Test{
public:
SavingsAccountDbTest(){};


};
	
   


TEST_F(SavingsAccountDbTest,AddCustomerTest)
{
	//void* efun1(void* pv);		//producer
	//void* efun2(void* pv);


        pthread_t pt1,pt2;	//thread handles
	sem_init(&s1,0,0);
	pthread_create(&pt1,NULL,efun1,NULL);
	pthread_create(&pt2,NULL,efun2,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	
    	savings1.addCustomer("9901","pavan",500);
    	EXPECT_NE((AccountBase*)NULL,savings1.findCustomerByNo("9901"));
    	EXPECT_EQ(5,savings1.countAll());
    	sem_destroy(&s1);
	pthread_mutex_destroy(&m1);
}

TEST_F(SavingsAccountDbTest,RemoveCustomerTest)
{
    savings1.removeCustomer("9900");
    EXPECT_EQ(NULL,savings1.findCustomerByNo("9900"));
    EXPECT_EQ(4,savings1.countAll());


}

TEST_F(SavingsAccountDbTest,CountTotalCustomerTest)
{
EXPECT_EQ(4,savings1.countAll());

}


TEST_F(SavingsAccountDbTest,ComputeMaxBalance)
{
double maxi=savings1.computeMaxBalance();
EXPECT_EQ(5000,maxi);
}


}

