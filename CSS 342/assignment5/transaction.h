#pragma once
/*By Ruiqi Huang
* 
* The Transaction class will take transactions from the bank queue and implement them to the accounts. I will keep track of the transactions, 
* along with the failed transactions in order to print them out later on. The transaction are are each defined by the action they represent. 
* When I say action I mean the withdraw, deposit, transfer, and display. There is also getters that we can use to get all transaction information 
* that we will eventually get from reading the transactions in the bank class. Thie transaction class don't need to inherit any other calss as it 
* jsut defines the transactions. The other calsses will need to inherit the transaction class though. 
*/

//Maybe include a vector that holds all the secessful transaction and the failed transactions. 
#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>
#include <iostream>

using namespace std;
class Transaction
{
public:
	Transaction();
	//Transaction for desposit and withdraw
	Transaction(char action, int id, int amount, bool fail_);
	//For transferring accounts
	Transaction(char action, int id1, int id2, int amount, bool fail_);
	//Print all output
	Transaction(char action, int id, bool fail_);
	//Print only given fund type
	//Transaction(char action, int id, int fundtype, bool fail_);
	//For openning account
	Transaction(char action, int id, string last_name, string first_name, bool fail);
	//Destructor
	~Transaction();

	//Getters
	int GetAccountID() const;
	int GetTransferAccountID() const;
	int GetTransactionAmount() const;
	int GetTransactionFund() const;
	int GetTranferFund() const;
	char GetAction() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetFullName() const;
	string GetFundName() const;

	//Setter
	void setFail(bool fail_);

	//Action
	bool CheckFail();
	void PrintTransaction();




private:
	int account_id;
	int transfer_account_id;
	int transaction_amount;
	int transaction_fund;
	int tranfer_transaction_fund;
	//Action is the action the transaction is asking us to do: aka open, withdraw, deposit, and transfer from account.
	char action_;
	string account_first_name;
	string account_last_name;
	//if fail is false then it is a sucess if fail is true then it failed
	bool fail = false;
};
#endif
