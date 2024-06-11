/*By Ruiqi Huang
* 2/16/2023
* 
* Description:
* SkipList is a 2 dimensional list where you have a upLevel, downLevel, next, and prev node from a point of the list. The list has a depth that is 
* defined using a constructor when you create a SkipList. Each depth is defined by levels. We start adding data from level 0 and all the data has a 50%
* chance of being added to the next level everytime. There is two restriction in adding data into the list. 1. You cannot add data that exceeds the INT_MAX
* and INT_MIN values. 2. You cannot add a duplicate number in the list. We can also remove data from the list. By using the remove function on a data, all 
* the levels that contain the data will have the data removed. The contain function help us see if the data is contained in the lsit or not. 
* 
* Individual description of each method is on top of each function in the header file. To know more about the implementation of each method, look at the 
* .cpp file comments for thorough explanations. 
*/

#pragma once
#include <iostream>
#include <string>
#include <climits>
using namespace std;

class SkipList
{
	//display all the elements in our list
	friend ostream& operator<<(ostream& os, const SkipList& list) {

		SNode* current = nullptr;

		//We have to print form the top layer in order to get the display we want. 
		for (int i = list.depth - 1; i >= 0; i--) {
			os << "Level: " << i << " -- ";
			current = list.frontGuards[i];

			//When we get to the rearGuards we know we are at the end of the list. 
			while (current != nullptr) {
				os << current->data << ", ";
				current = current->next;
			}
			os << endl;
		}
		return os;
	};

public:
	//default constructor of SkipList
	explicit SkipList(int depth = 1);
	//desctructor of SkipList
	virtual ~SkipList();

	//Actions
	//return true if successfully added, no duplicates allowed
	bool Add(int data);
	//return true if successfully removed
	bool Remove(int data);
	//reutrn true if data is found in SkipList
	bool Contains(int data);
private:
	class SNode {
	public:
		// SNode stores int as data
		explicit SNode(int data);
		// data for SNode
		int data;
		// link to next SNode
		SNode* next;
		// link to prev SNode
		SNode* prev;
		// link to up one level
		SNode* upLevel;
		// link to down one level
		SNode* downLevel;
	};

	//depth of SKipList, levels are 0 to depth-1
	int depth;
	//Guards the min value of the front of SkipList
	SNode** frontGuards;
	//guards the max value of the back of SkipList
	SNode** rearGuards;

	//place given SNode before the given NextNode
	void addBefore(SNode* newNode, SNode* nextNode);

	//return true 50% of the time
	//Each node has 50% chance of being higher level
	//return true if the node is also higher in the next SkipList. 
	bool alsoHigher() const;
};
