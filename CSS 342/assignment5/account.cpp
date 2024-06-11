#include "account.h"
#include <iostream>
#include <string>
#include <vector>

//Constructor
Account::Account(int id, string first, string last)
{
	this->ID = id;
	this->first_name = first;
	this->last_name = last;
}

//Destructor shell
Account::~Account()
{
	
}

//Operator overload of ==. Return true id the account is equal and false otherwise.
bool Account::operator==(const Account& account) const
{
	if ((this->ID == account.ID) && (this->first_name == account.first_name) && (this->last_name == account.last_name)) {
		return true;
	}

	return false;
}

//Getters: 
int Account::getID() const
{
	int current_id = ID;
	return current_id;
}

string Account::getFirstName() const
{
	string current_first_name = first_name;
	return current_first_name;
}

string Account::getLastName() const
{
	string current_last_name = last_name;
	return current_last_name;
}

string Account::getName() const
{
	string current_name = first_name + " " + last_name;
	return current_name;
}

int Account::getFundBalance(int fund_type) const
{
	return funds[fund_type].getBalance();
}

//Withdraw money from the account. 
//Pre-conditions: The fund exists (One of the 10 funds) and the amount is not negative
bool Account::Withdraw(int fund_type, int amount)
{
	if ((fund_type > 9) || (fund_type < 0)) {
		cerr << "ERROR: The fund cannot be found." << endl;
		return false;
	}
	if (amount <= 0) {
		cerr << "ERROR: You cannot add zero or a negative amount to Account." << endl;
		return false;
	}

	if (funds[fund_type].getBalance() < amount) {
		//If the first fund type is our Money Market then we can check if the Prime Money Market balance + Money Market balance is more than or equal to amount. If yes then we can withdraw from both. 
		if ((fund_type == 0) && (funds[fund_type].getBalance() + funds[1].getBalance() >= amount)) {
			//The totla balance of Money Market
			int total_balance = funds[fund_type].getBalance();
			//The amount needed to be withdraw decreases
			funds[fund_type].Minus(total_balance);
			amount = amount - total_balance;
			//Take the rest from Prime Money Market
			funds[1].Minus(amount);
			return true;
		}
		//If the first fund type is our Prime Money Market then we can check if the Money Market balance + Prime Money Market balance is more than or equal to the amount. If yes then we can withdraw from both.
		else if ((fund_type == 1) && (funds[fund_type].getBalance() + funds[0].getBalance() >= amount)) {
			//The total balance of Prine Money Market
			int total_balance = funds[fund_type].getBalance();
			//The amount needed to be withdraw decreases
			funds[fund_type].Minus(total_balance);
			amount = amount - total_balance;
			//Take the rest from Money Market
			funds[0].Minus(amount);
			return true;
		}

		//if both aboce is not true
		cerr << "ERROR: Not enough money in funds." << endl;
		return false;
	}

	funds[fund_type].Minus(amount);
	return true;
}

//Deposit money from this account
//Pre-conditions: The fund exists (One of the 10 funds) and the amount is not negative
bool Account::Deposit(int fund_type, int amount)
{
	if ((fund_type > 9) || (fund_type < 0)) {
		cerr << "ERROR: The fund cannot be found." << endl;
		return false;
	}
	if (amount <= 0) {
		cerr << "ERROR: You cannot add zero or a negative amount to Account." << endl;
		return false;
	}

	funds[fund_type].Add(amount);
	return true;
}

//Put the transaction to this account in the record_transaction vector
void Account::RecordTransaction(Transaction& transaction) {
	record_transactions.push_back(transaction);
}

//Prints the Account informations
void Account::PrintAccount()
{
	cout << "Account ID: " << ID << " - " << "Account Name: " << first_name << " " << last_name << endl;
	cout << "Money Market Balance: " << "$" << funds[0].getBalance() << endl;
	cout << "Prime Monay Market Balance: " << "$" << funds[1].getBalance() << endl;
	cout << "Long-term Bond Balance: " << "$" << funds[2].getBalance() << endl;
	cout << "Short-term Bond Balance: " << "$" << funds[3].getBalance() << endl;
	cout << "500 Index Fund Balance: " << "$" << funds[4].getBalance() << endl;
	cout << "Capital Value Fund Balance: " << "$" << funds[5].getBalance() << endl;
	cout << "Growth Equity Fund Balance: " << "$" << funds[6].getBalance() << endl;
	cout << "Growth Index Fund Balance: " << "$" << funds[7].getBalance() << endl;
	cout << "Value Fund Balance: " << "$" << funds[8].getBalance() << endl;
	cout << "Value Stock Index Balance: " << "$" << funds[9].getBalance() << endl;
}

//Prints that one chosen fund information for this account. 
void Account::PrintFund(int fund_type)
{
	cout << "Account ID: " << ID << " - " << "Account Name: " << first_name << " " << last_name << endl;
	if (fund_type == 0) {
		cout << "Money Market Balance: " << "$" << funds[0].getBalance() << endl;
	}
	else if (fund_type == 1) {
		cout << "Prime Monay Market Balance: " << "$" << funds[1].getBalance() << endl;
	}
	else if (fund_type == 2) {
		cout << "Long-term Bond Balance: " << "$" << funds[2].getBalance() << endl;
	}
	else if (fund_type == 3) {
		cout << "Short-term Bond Balance: " << "$" << funds[3].getBalance() << endl;
	}
	else if (fund_type == 4) {
		cout << "500 INdex Fund Balance: " << "$" << funds[4].getBalance() << endl;
	}
	else if (fund_type == 5) {
		cout << "Capital Value Fund Balance: " << "$" << funds[5].getBalance() << endl;
	}
	else if (fund_type == 6) {
		cout << "Growth Equity Fund Balance: " << "$" << funds[6].getBalance() << endl;
	}
	else if (fund_type == 7) {
		cout << "Growth Index Fund Balance: " << "$" << funds[7].getBalance() << endl;
	}
	else if (fund_type == 8) {
		cout << "Value Fund Balance: " << "$" << funds[8].getBalance() << endl;
	}
	else if (fund_type == 9) {
		cout << "Value Stock Index: " << "$" << funds[9].getBalance() << endl;
	}
	else {
		//Assuming that if the fund_type is none of the above then the fund is not valid.
		cout << "Fund not found..." << endl;
	}

}

void Account::PrintTransactionHistory()
{
	for (int i = 0; i < record_transactions.size(); i++) {
		record_transactions[i].PrintTransaction();
	}
}

//Pre-conditions:
//Prints the fund history recored in the record_transaction[] (vector)
void Account::PrintFundHistory(int fund_type)
{
	//Seeing which account to print
	for (int i = 0; i < record_transactions.size(); i++) {
		//Check if the account is the original account
		if ((record_transactions[i].GetAccountID() == getID()) && (record_transactions[i].GetTransactionFund() == fund_type)) {
			record_transactions[i].PrintTransaction();
		}
		//Checking if the account the account being transfer to
		else if ((record_transactions[i].GetTransferAccountID() == getID()) && (record_transactions[i].GetTranferFund() == fund_type)) {
			record_transactions[i].PrintTransaction();
		}
	}
}

/*int Account::GetAccountTransactionSize() const
{
	int size = record_transactions.size();
	return size;
}
*/

std::ostream& operator<<(std::ostream& stream, const Account& account)
{
	stream << "Account ID: " << account.getID() << " - " << "Account Name: " << account.getFirstName() << " " << account.getLastName() << endl;
	stream << "Money Market Balance: " << "$" << account.getFundBalance(0) << endl;
	stream << "Prime Monay Market Balance: " << "$" << account.getFundBalance(1) << endl;
	stream << "Long-term Bond Balance: " << "$" << account.getFundBalance(2) << endl;
	stream << "Short-term Bond Balance: " << "$" << account.getFundBalance(3) << endl;
	stream << "500 Index Fund Balance: " << "$" << account.getFundBalance(4) << endl;
	stream << "Capital Value Fund Balance: " << "$" << account.getFundBalance(5) << endl;
	stream << "Growth Equity Fund Balance: " << "$" << account.getFundBalance(6) << endl;
	stream << "Growth Index Fund Balance: " << "$" << account.getFundBalance(7) << endl;
	stream << "Value Fund Balance: " << "$" << account.getFundBalance(8) << endl;
	stream << "Value Stock Index Balance: " << "$" << account.getFundBalance(9) << endl;
	//ADD FUNDS TO PRINT
	return stream;
}