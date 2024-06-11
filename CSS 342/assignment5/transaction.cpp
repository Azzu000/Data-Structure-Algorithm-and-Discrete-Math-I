#include "transaction.h"


//Auto-gennerated constructor
Transaction::Transaction()
{
	//These are just auto-generated values we are not going to use but we have to set
	this->action_ = 'S';
	this->account_id = 0;
	this->transfer_account_id = 0;
	this->transaction_fund = 0;
	this->tranfer_transaction_fund = 0;
	this->transaction_amount = 0;
	this->fail = fail;

}

//The Constructor for Deposit and Withdrawal
Transaction::Transaction(char action, int id, int amount, bool fail)
{
	//These are temporary variables to fold the id and the fund until we are able to split them. 
	int temp_id = id;
	int temp_fund = id;
	//These math will get us the fund
	temp_fund = temp_fund % 10000;
	temp_fund = temp_fund % 1000;
	temp_fund = temp_fund % 100;
	temp_fund = temp_fund % 10;

	//These math will get us the id
	temp_id = (temp_id - temp_fund) / 10;

	this->action_ = action;
	this->account_id = temp_id;
	this->transaction_fund = temp_fund;
	this->transaction_amount = amount;
	this->fail = fail;

	//don't need but have to initialize
	this->transfer_account_id = 0;
	this->tranfer_transaction_fund = 0;
}

//The Constructor for Transfer
Transaction::Transaction(char action, int id1, int id2, int amount, bool fail)
{
	int temp_id1 = id1;
	int temp_fund1 = id1;
	temp_fund1 = temp_fund1 % 10000;
	temp_fund1 = temp_fund1 % 1000;
	temp_fund1 = temp_fund1 % 100;
	temp_fund1 = temp_fund1 % 10;

	temp_id1 = (temp_id1 - temp_fund1) / 10;

	int temp_id2 = id2;
	int temp_fund2 = id2;
	temp_fund2 = temp_fund2 % 10000;
	temp_fund2 = temp_fund2 % 1000;
	temp_fund2 = temp_fund2 % 100;
	temp_fund2 = temp_fund2 % 10;

	temp_id2 = (temp_id2 - temp_fund2) / 10;

	this->action_ = action;
	this->account_id = temp_id1;
	this->transfer_account_id = temp_id2;
	this->transaction_fund = temp_fund1;
	this->tranfer_transaction_fund = temp_fund2;
	this->transaction_amount = amount;
	this->fail = fail;

}

//The Consdtructor for Printing Account History
Transaction::Transaction(char action, int id, bool fail)
{
	int temp_fund = id; 
	this->action_ = action;
	this->fail = fail;

	//If it is negative then it is a 4 digit number and if it is positive then it is a 5 digit number
	if ((id - 10000) > -1) {
		temp_fund = temp_fund % 10000;
		temp_fund = temp_fund % 1000;
		temp_fund = temp_fund % 100;
		temp_fund = temp_fund % 10;

		this->transaction_fund = temp_fund;
		this->account_id = (id - temp_fund) / 10;
	}
	else {
		//if the trnasaction fund is 10 then we want to print the accoutn history
		this->transaction_fund = 10;
		this->account_id = id;
	}

	//don't need but have to initialize
	this->transfer_account_id = 0;
	this->tranfer_transaction_fund = 0;
	this->transaction_amount = 0;

}

//To open account we don't need to change the id to int because we know when they open an account they have to just apply the id. 
//The Constructor for Openning Account
Transaction::Transaction(char action, int id, string last_name, string first_name, bool fail)
{
	this->action_ = action;
	this->account_id = id;
	this->account_first_name = first_name;
	this->account_last_name = last_name;
	this->fail = fail;
}

//Destructor
Transaction::~Transaction()
{

}

//From here it is the implementation of the getter methods:
int Transaction::GetAccountID() const
{
	int temp_id = account_id;
	return temp_id;
}

int Transaction::GetTransferAccountID() const
{
	int temp_transfer_id = this->transfer_account_id;
	return temp_transfer_id;
}

int Transaction::GetTransactionAmount() const
{
	int temp_amount = this->transaction_amount;
	return temp_amount;
}

int Transaction::GetTransactionFund() const
{
	int temp_fund = transaction_fund;
	return temp_fund;
}

int Transaction::GetTranferFund() const
{
	int temp_transfer_fund = tranfer_transaction_fund;
	return temp_transfer_fund;
}

char Transaction::GetAction() const
{
	char temp_action = this->action_;
	return temp_action;
}

string Transaction::GetFirstName() const
{
	string temp_first = this->account_first_name;
	return temp_first;
}

string Transaction::GetLastName() const
{
	string temp_last = account_last_name;
	return temp_last;
}

string Transaction::GetFullName() const
{
	string temp_name = this->account_first_name + " " + this->account_last_name;
	return temp_name;
}

string Transaction::GetFundName() const
{
	string fund;
	if (transaction_fund == 0) {
		fund = "Money Market";
	}
	else if (transaction_fund == 1) {
		fund = "Prime Money Markey";
	}
	else if (transaction_fund == 2) {
		fund = "Long-Term Bond";
	}
	else if (transaction_fund == 3) {
		fund = "Short-Term Bond";
	}
	else if (transaction_fund == 4) {
		fund = "500 Index Fund";
	}
	else if (transaction_fund == 5) {
		fund = "Capital Value Fund";
	}
	else if (transaction_fund == 6) {
		fund = "Growth Equity Fund";
	}
	else if (transaction_fund == 7) {
		fund = "Growth Index Fund";
	}
	else if (transaction_fund == 8) {
		fund = "Value Fund";
	}
	else if (transaction_fund == 9) {
		fund = "Value Stock Index";
	}
	return fund;
}

//Sets fail to false if the transaction did not fail and set the fail to true if the transactio  have failed
void Transaction::setFail(bool fail_)
{
	this->fail = fail_;
}

//This method checks if the transactio have failed or now
bool Transaction::CheckFail()
{
	if (fail == true) {
		cout << "true" << endl;
		return true;
	}
	else {
		cout << "false" << endl;
		return false;
	}
}

//Prints all the transactions
void Transaction::PrintTransaction()
{
	if (fail == false) {
		if (GetAction() == 'D') {
			cout << "  " << GetAction() << " " << GetAccountID() << " " << GetTransactionFund() << " " << GetTransactionAmount() << endl;
		}
		else if (GetAction() == 'W') {
			cout << "  " << GetAction() << " " << GetAccountID() << " " << GetTransactionFund() << " " << GetTransactionAmount() << endl;
		}
		else if (GetAction() == 'T') {
			cout << "  " << GetAction() << " " << GetAccountID() << " " << GetTransactionFund() << " " << GetTransferAccountID() << " "
				<< GetTranferFund() << " " << GetTransactionAmount() << endl;
		}
	}
	else {
		if (GetAction() == 'D') {
			cout << "  " << GetAction() << " " << GetAccountID() << " " << GetTransactionFund() << " " << GetTransactionAmount() << " (FAIL)" << endl;
		}
		else if (GetAction() == 'W') {
			cout << "  " << GetAction() << " " << GetAccountID() << " " << GetTransactionFund() << " " << GetTransactionAmount() << " (FAIL)" << endl;
		}
		else if (GetAction() == 'T') {
			cout << "  " << GetAction() << " " << GetAccountID() << " " << GetTransactionFund() << " " << GetTransferAccountID() << " "
				<< GetTranferFund() << " " << GetTransactionAmount() << " (FAIL)" << endl;
		}
	}
}
