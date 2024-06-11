#include "bank.h"

//Auto-generated Constructor
Bank::Bank()
{

}

//Destructor 
Bank::~Bank()
{

}

//Reads the transaction and put them into the transaction queue
//Pre-conditions: The file exists and the transaction is accurate (syntax and action is real)
bool Bank::ReadTransactions(const string& file_name)
{
	string temp_transaction;
	char transaction_action;
	ifstream file;
	file.open(file_name);
	//if we can't open the file
	if (!file.is_open()) {
		cerr << "ERROR: File " << file_name << " cannot be found." << endl;
		return false;
	}

	while (!file.eof()) {
		//We break the string transaction into tokens in order to make a transaction to store in our queue
		getline(file, temp_transaction);
		if (temp_transaction.empty()) {
			cerr << "ERROR: No transactions found." << endl;
			return false;
		}
		stringstream check(temp_transaction);
		check >> transaction_action;
		if (transaction_action == 'O') {
			int transaction_id;
			string last_name;
			string first_name;

			check >> last_name;
			check >> first_name;
			check >> transaction_id;
			Transaction open_trans(transaction_action, transaction_id, last_name, first_name, false);
			//Add transaction to queue
			transactions.push(open_trans);
		}
		else if (transaction_action == 'D') {
			int transaction_id;
			int transaction_amount;

			check >> transaction_id;
			check >> transaction_amount;
			Transaction deposit_trans(transaction_action, transaction_id, transaction_amount, false);
			transactions.push(deposit_trans);
		}
		else if (transaction_action == 'W') {
			int transaction_id;
			int transaction_amount;

			check >> transaction_id;
			check >> transaction_amount;
			Transaction withdraw_trans(transaction_action, transaction_id, transaction_amount, false);
			transactions.push(withdraw_trans);
		}
		else if (transaction_action == 'T') {
			int transaction_id;
			int transfer_id;
			int transaction_amount;

			check >> transaction_id;
			check >> transaction_amount;
			check >> transfer_id;
			Transaction transfer_trans(transaction_action, transaction_id, transfer_id, transaction_amount, false);
			transactions.push(transfer_trans);
		}
		//REPLACE WITH H
		else if (transaction_action == 'H') {
			int transaction_id;

			check >> transaction_id;
			Transaction print_all_trans(transaction_action, transaction_id, false);
			transactions.push(print_all_trans);
		}
		
		else {
			cerr << "ERROR: Unable to identify action." << endl;
			return false;
		}
	}
	return false;
}

//Executes all the transactions in the queue to each account and make sure everything is recorded
//Pre-condition: The transaction goes through (Syntax and action is correct)
bool Bank::Banker()
{
	while (transactions.empty() == false) {
		if (transactions.front().GetAction() == 'O') {
			//Open an account
			Account* new_account = new Account(transactions.front().GetAccountID(), transactions.front().GetFirstName(), transactions.front().GetLastName());
			AccountList.Insert(transactions.front().GetAccountID(), new_account);
			//We don't need to record when we open an account so we can jsut pop
			transactions.pop();
		}
		else if (transactions.front().GetAction() == 'D') {
			//Deposit to Account
			Account* old_account;
			if (AccountList.Retrieve(transactions.front().GetAccountID(), old_account) == true) {
				old_account->Deposit(transactions.front().GetTransactionFund(), transactions.front().GetTransactionAmount());
				if (old_account->Deposit(transactions.front().GetTransactionFund(), transactions.front().GetTransactionAmount()) == false) {
					transactions.front().setFail(true);
				}
				old_account->RecordTransaction(transactions.front());
				transactions.pop();
			}
			else {
				//If the account cannot be found then it failed
				transactions.front().setFail(true);
				old_account->RecordTransaction(transactions.front());
				transactions.pop();
			}
		}
		else if (transactions.front().GetAction() == 'W') {
			//Withdraw from Account
			Account* old_account;
			if (AccountList.Retrieve(transactions.front().GetAccountID(), old_account) == true) {
				old_account->Withdraw(transactions.front().GetTransactionFund(), transactions.front().GetTransactionAmount());
				if (old_account->Withdraw(transactions.front().GetTransactionFund(), transactions.front().GetTransactionAmount()) == false) {
					transactions.front().setFail(true);
				}
				old_account->RecordTransaction(transactions.front());
				transactions.pop();
			}
			else {
				//If the account cannot be found then it failed
				transactions.front().setFail(true);
				old_account->RecordTransaction(transactions.front());
				transactions.pop();
			}
		}
		else if (transactions.front().GetAction() == 'T') {
			Account* old_account;
			Account* old_transfer_account;

			if ((AccountList.Retrieve(transactions.front().GetAccountID(), old_account) == true) && (AccountList.Retrieve(transactions.front().GetTransferAccountID(), old_transfer_account) == true)) {
				old_account->Withdraw(transactions.front().GetTransactionFund(), transactions.front().GetTransactionAmount());
				if (old_account->Withdraw(transactions.front().GetTransactionFund(), transactions.front().GetTransactionAmount()) == false) {
					transactions.front().setFail(true);
				}
				old_account->Deposit(transactions.front().GetTranferFund(), transactions.front().GetTransactionAmount());
				if (old_account->Deposit(transactions.front().GetTranferFund(), transactions.front().GetTransactionAmount()) == false) {
					transactions.front().setFail(true);
				}
				old_account->RecordTransaction(transactions.front());
				old_transfer_account->RecordTransaction(transactions.front());
				transactions.pop();
			}
			else {
				//If the account cannot be found then it failed
				transactions.front().setFail(true);
				//If one of the accounts don't exist
				if (AccountList.Retrieve(transactions.front().GetAccountID(), old_account)) {
					old_account->RecordTransaction(transactions.front());
				}
				else if (AccountList.Retrieve(transactions.front().GetTransferAccountID(), old_transfer_account) == true) {
					old_transfer_account->RecordTransaction(transactions.front());
				}
				transactions.pop();
			}

		}
		else if (transactions.front().GetAction() == 'H') {
			if (transactions.front().GetTransactionFund() == 10) {
				Account* old_account;

				//If the account exist then we print every transaction in made account
				if (AccountList.Retrieve(transactions.front().GetAccountID(), old_account)) {
					//Make sure there is a indent to make things more readable
					cout << endl;
					cout << "Transaction History for " << old_account->getName() << endl;
					old_account->PrintAccount();
					cout << endl;
					cout << "Transactions: " << endl;
					old_account->PrintTransactionHistory();
				}
				else {
					//If we cannot find the accound we will jsut set the transaction as fail.
					transactions.front().setFail(true);
				}
				transactions.pop();
			} else {
				Account* old_account;
				//If the account exist then we print every transaction in made account
				if (AccountList.Retrieve(transactions.front().GetAccountID(), old_account) == true) {
					//Make sure there is a indent to make things more readable
					cout << endl;
					cout << "Transaction History for " << old_account->getName() << " in " << transactions.front().GetFundName() << endl;
					old_account->PrintFund(transactions.front().GetTransactionFund());
					old_account->PrintTransactionHistory();
				}
				else {
					transactions.front().setFail(true);
				}
				transactions.pop();
			}
		}
	}

	return false;
}

//Display the Accounts in Binary Tree 
void Bank::DisplayAccounts()
{
	//Make sure there is a indent to make things more readable
	cout << endl;
	cout << "FINAL BALANCES: " << endl;
	AccountList.Display();
}

//This help us display the amount of transactions we have gone through
void Bank::QueueSize()
{
	cout << "The number of transactions is: " << transactions.size() << endl;
}

//Testing print method used for testing purposes only. 
bool Bank::Print(const string& file_name)
{
	string line;
	ifstream file;
	file.open(file_name);
	if (!file.is_open()) {
		cerr << " ERROR: File is not openning" << endl;
		return false;
	}
	cout << " The transactions are " << endl;
	while (!file.eof()) {
		file >> line;
		cout << line << endl;
	}
	file.close();
	return false;
}
