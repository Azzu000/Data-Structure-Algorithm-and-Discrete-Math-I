// JollyBank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "bank.h"
#include "transaction.h"
//#include "account.h";
#include "fund.h"
#include "binary_search_tree.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*This is just the driver of the JollyBank
*/

int main()
{

    Bank bank;

    bank.ReadTransactions("BankTransIn.txt");
    bank.QueueSize();
    bank.Banker();
    bank.DisplayAccounts();


}