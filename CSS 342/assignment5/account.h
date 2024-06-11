#pragma once
/*By Ruiqi Huang
* 
* The Account class has 10 funds. In order to open an account you need an id, first name, and last name. This account have the functions to withdraw and 
* deposit money as any account would. We did not need to implement a transfer function because that is going to be the bankers job as it involved the withdrawal
* and deposits of two accounts. Because the account have difference funds, it inherits the fund class in order to be in charge of all the funds. It is important
* to note that the Account class also have a record_transaction vector that will keep track of all the transaction that happened in this particular account. 
* That is why it inherits the transaction class. 
*/
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include "fund.h"
#include "transaction.h"

using namespace std;

//Global functions
const int kFundCount = 10;

class Account
{
public:
	//Constructors
	//In order to open account you need to have id, first name and last name
	Account(int id, string first, string last);
	~Account();

	//Operator Overloads
	bool operator==(const Account& account) const;
	friend std::ostream& operator<<(std::ostream& stream, const Account& account);

	//getters
	int getID() const;
	string getFirstName() const;
	string getLastName() const;
	//Gives full name.
	string getName() const;
	int getFundBalance(int fund_type) const;

	//Actions
	bool Withdraw(int fund_type, int amount);
	bool Deposit(int fund_type, int amount);

	//Prints all fund balance in account. 
	void RecordTransaction(Transaction& transaction);
	void PrintAccount();
	//Print a spefic fund
	void PrintFund(int fund_type);
	void PrintTransactionHistory();
	void PrintFundHistory(int fund_type);

private:
	int ID;
	string first_name;
	string last_name;

	//array that holds all the funds. Each fund is represented by a number.
	Fund funds[kFundCount];
	vector<Transaction> record_transactions;
};
#endif