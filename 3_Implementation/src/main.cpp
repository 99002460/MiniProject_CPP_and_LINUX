#include<pthread.h>
#include<semaphore.h>
#include<iostream>
#include"savingsaccount.h"
#include"account.h"
#include"savingsaccountDb.h"
pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;
SavingsAccountDb savings;
int main()
{
void* efun1(void* pv);
void* efun2(void* pv);


        pthread_t pt1,pt2;	//thread handles
	sem_init(&s1,0,0);
	pthread_create(&pt1,NULL,efun1,NULL);
	pthread_create(&pt2,NULL,efun2,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
        sem_destroy(&s1);
	pthread_mutex_destroy(&m1);
}

void* efun1(void* pv)		//producer
{
	
	
	
	pthread_mutex_lock(&m1);
	
	savings.addCustomer("9900","Raj",1000);
    	savings.addCustomer("9902","Harsh",5000);
    	savings.addCustomer("9903","Pruthvi",1500);
    	savings.addCustomer("9904","Ramesh",1000);

	pthread_mutex_unlock(&m1);
	sem_post(&s1);
	
}
void* efun2(void* pv)		//consumer
{
	
	
	sem_wait(&s1);			//changing sequence lead to deadlock
	pthread_mutex_lock(&m1);
	std::cout<<"B--welcome,waiting for semaphore\n";
	pthread_mutex_unlock(&m1);
	//pthread_exit(NULL);
}





