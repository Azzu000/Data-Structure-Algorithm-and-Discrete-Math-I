#pragma once
/*By Ruiqi Huang
* 
* Funds is a simple class that will keep track of the funds balance. This will be used for the Account class to keep track of different type of 
* funds.
*/
#ifndef FUND_H_
#define FUND_H_
#include <iostream>
#include <string>
#include<vector>

using namespace std;

class Fund
{
public:
	//Constructors
	Fund();
	~Fund();

	//Getters
	//string getFundType();
	int getBalance() const;

	//Actions
	//Add money to balance
	bool Add(int amount);
	//Minus money from balance 
	bool Minus(int amount);

private:
	//string fund_type;
	int balance;

};
#endif