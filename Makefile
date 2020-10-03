all.out:account_test.cpp creditaccountDb_test.cpp savingsaccountDb_test.cpp src/account.cpp src/CreditAccount.cpp src/creditaccountDb.cpp src/savingsaccount.cpp src/savingsaccountDb.cpp
	g++ account_test.cpp creditaccountDb_test.cpp savingsaccountDb_test.cpp src/account.cpp src/CreditAccount.cpp src/creditaccountDb.cpp src/savingsaccount.cpp src/savingsaccountDb.cpp -lgtest -lgtest_main -lpthread -lrt -o all.out -static -Lsrc -laccount

run:all.out
	./all.out
