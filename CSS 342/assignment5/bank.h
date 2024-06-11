/*BY Ruiqi Huang
* 
* The bank class is in charge of putting all the transaction into action. First the bank reads the transactions and then the banker executes all the transactions 
* accordingly. All the transaction read is going to be put into a queue of transactions. It will be read in order from top to bottom. Even though this 
* class seem to have really little functions, all the functions have a lot of priorities in order for this Jolly Bank to work. In general, the Bank class
* needs to inherit the account and binary search tree to display the accounts and executes the transactions within the accounts. The bank also needs to inherit the 
* transaction class because it needs to actually read the transactions and place then into the right transaction constructor in order for the transaction
* to be able to execute. 
*/

#pragma once
#ifndef BANK_H_
#define BANK_H_
#include "account.h"
#include "binary_search_tree.h"
//#include "fund.h"
#include "transaction.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;
//string stream class to help us tokenize strings
#include <sstream>

class Bank
{
public:
	Bank();
	~Bank();

	//Reads the transactions from a file and put it into the queue
	bool ReadTransactions(const string& file_name);
	//The banker execute all the transactions
	bool Banker();
	//Display all transaction and account info
	void DisplayAccounts();
	//Gets the size of the queue
	void QueueSize();

	//This is just here to test the file reading function
	bool Print(const string& file_name);

private:
	//The queue that holds all the transaction in order
	queue<Transaction> transactions;
	//The binary tree that is going to hold all accounts for this bank
	BinarySearchTree AccountList;
};
#endif