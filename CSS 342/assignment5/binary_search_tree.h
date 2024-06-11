#pragma once
#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
#include <iostream>
#include <string>
#include"account.h"

using namespace std;

class BinarySearchTree
{
public:
	BinarySearchTree();
	//Copy Constructor
	//BinarySearchTree(const BinarySearchTree& tree);
	~BinarySearchTree();

	//Operator Overloads
	//Copy assignment
	BinarySearchTree& operator=(const BinarySearchTree& tree);
	//friend ostream& operator<<(std::ostream& stream, const BinarySearchTree& tree);

	int getCount() const;

	bool is_empty() const;
	bool Insert(int acc_id, Account* account);


	bool Remove(int acc_id);
	//bool Contains(int acc_id) const;

	//We have to pass int the pointer by refernce so we can get access to the account
	bool Retrieve(int acc_id, Account*& p_account);
	void Display() const;

private:
	struct Node {
		int acc_id;
		Account* p_account;
		Node* right;
		Node* left;
	};
	Node* root_ = nullptr;

	//Keeps track of the number of account in Binary Tree
	int count = 0;
	void RecursiveDisplay(Node* node) const;
};

#endif