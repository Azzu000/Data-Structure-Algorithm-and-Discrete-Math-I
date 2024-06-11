#include "fund.h"
#include <vector>
#include <string>
#include <iostream>

//All fund balance starts at 0.
Fund::Fund()
{
	balance = 0;
}

//Destructor
Fund::~Fund()
{

}

//Getter for the Balance
int Fund::getBalance() const
{
	int current_balance = balance;
	return current_balance;
}

//Add money to Fund
bool Fund::Add(int amount)
{
	if (amount <= 0) {
		cerr << "ERROR: You cannot add zero or a negative amount to a fund." << endl;
		return false;
	}

	balance += amount;
	return true;
}

//Minus money from Fund
//Pre-condition: the amount added cannot be less than zero, balance should be more than the amount being minus
bool Fund::Minus(int amount)
{
	if (amount <= 0) {
		cout << "Sorry, you cannot take zero or a negative amoutn from a fund." << endl;
		return false;
	}
	else if (amount > balance) {
		cout << "Sorry, you don't have enough money in your fund." << endl;
		return false;
	}

	balance -= amount;
	return false;
}
