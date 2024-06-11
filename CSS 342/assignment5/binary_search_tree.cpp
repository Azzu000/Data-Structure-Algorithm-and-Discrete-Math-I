/*By Ruiqi Huang
* 
* This is a simple Binary Search Tree created for Accounts. It is implemented recursively as it is supposed to be. All the function of a Binary Search
* Tree is available in this Binary Search Tree as well. 
* It is important to note that the Remove function for the BinarySearchTree have not been fully tested since it was not used in our bank. It was implemented
* to make the BinarySearchTree more complete. 
*/

#include "binary_search_tree.h"
#include <string>
#include <iostream>

using namespace std;

//Auto-Generated contrustor for Binary Tree
BinarySearchTree::BinarySearchTree()
{

}

//Auto-Generated destructor for Binary Tree
BinarySearchTree::~BinarySearchTree()
{

}

//Get the count (used to keep track of how many accounts are in the Binary Search Tree
int BinarySearchTree::getCount() const
{
	int curr_count = count;
	return curr_count;
}

//Checks if the tree is empty.
bool BinarySearchTree::is_empty() const
{
	if (root_ == nullptr) {
		return true;
	}
	return false;
}

/*Pre-conditions:
* 1. If the account id we want to insert exists already.
* 2. If we are inserting the account at root.
*/
bool BinarySearchTree::Insert(int acc_id, Account* account)
{
	//Used to go through tree until it finds the spot the id belongs.
	Node* temp = root_;
	//The future parent node of the Account
	Node* parent = nullptr;

	//if the tree is empty
	if (root_ == nullptr) {
		root_ = new Node();
		root_->p_account = account;
		root_->acc_id = acc_id;
		root_->right = nullptr;
		root_->left = nullptr;
		count++;
		return true;
	}

	//while the temp node is not empty, we will move until the next temp node is nullptr.
	while ((temp != nullptr) && (temp->p_account != account)) {
		parent = temp;

		if (temp->acc_id < acc_id) {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}

	//We cannot have two same account
	if ((temp != nullptr) && (temp->p_account == account)) {
		cerr << "ERROR: Account already exists." << endl;
		return false;
	}
	//If account id is bigger than their future parent node
	if ((parent != nullptr) && (parent->acc_id < acc_id)) {
		Node* newnode = new Node();
		newnode->p_account = account;
		newnode->acc_id = acc_id;
		parent->right = newnode;
		count++;
		return true;
	}
	//if account id is smaller than their future parent node
	else if ((parent != nullptr) && (parent->acc_id > acc_id)) {
		Node* newnode = new Node();
		newnode->p_account = account;
		newnode->acc_id = acc_id;
		parent->left = newnode;
		count++;
		return true;
	}

	return false;
}

//An attempt to code Remove
/*Pre-conditions:
1. is empty
2. delete root (3 cases subcases - no children, one child, two child)
two children is hard - right smallest or left biggest. left far right. right far left.
3. All other nodes, you need to stop above the person you need to remove. (if the node we remove have children then we
consider the case of them having one children, two children, or no children.)
last 3 subcases
*/
bool BinarySearchTree::Remove(int acc_id)
{
	Node* temp = root_;
	Node* node = new Node();

	Account* account;
	//Check if the account can be retrieved, if not then it is not in list
	if (Retrieve(acc_id, account) == false) {
		cerr << "ERROR: Account not in list." << endl;
		return false;
	}

	if (root_ == nullptr) {
		return true;
	}

	//if the root node then either the children from far left or the children from far right becomes root.
	if (root_->acc_id == acc_id) {
		//subcases
		if ((temp->left == nullptr) && temp->right == nullptr) {
			delete root_;
			return true;
		}
		else if (temp->right == nullptr) {
			node = temp->left;
			delete root_;
			root_ == node;
		}
		else if (temp->left == nullptr) {
			node = temp->right;
			delete root_;
			root_ == node;
		}
		//both left and right is not null
		else {
			//we are going to find the left's biggest id to replace root
			temp = temp->left;
			while ((temp != nullptr) && (temp->right != nullptr)) {
				temp = temp->right;
			}
			delete root_;
			root_ = temp;
		}
	}

	//All the other possibilities
	//Will hold the previous node of temp
	Node* prev = temp;
	bool found = false;
	//We want temp to be one step ahead of prev so we have to move temp first
	if ((temp->acc_id > acc_id)) {
		temp = temp->left;
	}
	else if ((temp->acc_id < acc_id)) {
		temp = temp->right;
	}

	while ((temp != nullptr) && (found == false)) {
		if ((temp != nullptr) && (is_empty() == false) && (temp->acc_id == acc_id)) {
			found = true;
		}
		else if ((temp != nullptr) && (temp->acc_id > acc_id)) {
			prev = prev->left;
			temp = temp->left;
		}
		else if ((temp != nullptr) && (temp->acc_id < acc_id)) {
			prev = prev->right;
			temp = temp->right;
		}
	}

	if (temp->left == nullptr && temp->right == nullptr) {
		delete temp;
	}
	else if (temp->left == nullptr) {
		node = temp->right;
		delete temp;
		if (node->acc_id > prev->acc_id) {
			prev->right = node;
		}
		else {
			prev->left = node;
		}
	}
	else if (temp->right == nullptr) {
		node = temp->left;
		delete temp;
		if (node->acc_id > prev->acc_id) {
			prev->right = node;
		}
		else {
			prev->left = node;
		}
	}
	//The node we want to delete have both chrildens
	else {
		//Replace temp with the left childs biggest id
		node = temp;
		node = node->left;
		while (node->right != nullptr) {
			node = node->right;
		}
		delete temp;
		temp = node;
	}

	return false;
}

//Retrieves the Account from the Binary Search Tree
bool BinarySearchTree::Retrieve(int acc_id, Account*& p_account)
{
	//if found is true then we know we foudn the object
	bool found = false;
	Node* temp = root_;

	//While it is false we know we have not found the account
	while ((temp != nullptr) && (found == false)) {
		//if the root node is the account we are searching for
		if ((temp != nullptr) && (is_empty() == false) && (temp->p_account->getID() == acc_id)) {
			p_account = temp->p_account;
			found = true;
			return true;
		}
		//if the temp node is smaller than the account id we are looking for we go left
		else if ((temp != nullptr) && (temp->p_account->getID() > acc_id)) {
			temp = temp->left;
		}
		else if ((temp != nullptr) && (temp->p_account->getID() < acc_id)) {
			temp = temp->right;
		}
	}

	cerr << "ERROR: Account " << acc_id << " not found. Transaction refused." << endl;
	return false;
}

//Displays the Binary Search Tree
void BinarySearchTree::Display() const
{
	if (is_empty() == true) {
		//If the node is null thenw e print out this error.
		cerr << "ERROR: There is no accounts to display." << endl;
	}
	else {
		RecursiveDisplay(root_);
	}
}

//The recursive Display method that will be called in Display()
void BinarySearchTree::RecursiveDisplay(Node* node) const
{
	//if we know that both left and right of tree is not null
	if ((node->left != nullptr) && (node->right != nullptr)) {
		RecursiveDisplay(node->left);
		cout << *(node->p_account) << endl;
		RecursiveDisplay(node->right);
	}
	//If the top if statement is not true then either left or right contains all the accounts.
	else if (node->right != nullptr) {
		RecursiveDisplay(node->right);
		cout << *(node->p_account) << endl;
	}
	else if (node->left != nullptr) {
		RecursiveDisplay(node->left);
		cout << *(node->p_account) << endl;
	}
	//If both null we can just print
	else {
		cout << *(node->p_account) << endl;
	}

}
