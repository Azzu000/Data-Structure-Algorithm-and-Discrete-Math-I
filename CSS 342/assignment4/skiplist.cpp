/*By Ruiqi Huang
* 
* 2/26/2023
* 
* This is where all the implementation of SkipList is located at. All the description of the SKipList class is located in the header file skiplsit.h
*/
#include "skiplist.h"

//Construtor of SkipList. Default depth = 1. We need to initiate 3 things: depth, frontGuards, and rearGuards
SkipList::SkipList(int depth)
{ 
	this->depth = depth;
	frontGuards = new SNode * [depth];
	rearGuards = new SNode * [depth];
	
	for (int i = 0; i < depth; i++) {
		//Checking if it is our first depth, if it is we have to first initiate our first level before going up or down the list. 
		if (i == 0) {
			//We have to set the front and rear guard for L0
			frontGuards[0] = new SNode(INT_MIN);
			rearGuards[0] = new SNode(INT_MAX);

			//Now we put the front and rear guard in L0 of list
			frontGuards[0]->next = rearGuards[0];
			rearGuards[0]->prev = frontGuards[0];
		}
		else {
			//Adding the values of front and rear guard. 
			frontGuards[i] = new SNode(INT_MIN);
			rearGuards[i] = new SNode(INT_MAX);

			//Set the up level of previous guards to the current guards
			frontGuards[i-1]->upLevel = frontGuards[i];
			rearGuards[i-1]->upLevel = rearGuards[i];

			//Set the down level of the current guards to the previous guards
			frontGuards[i]->downLevel = frontGuards[i - 1];
			rearGuards[i]->downLevel = rearGuards[i - 1];

			//Setting up the fornt guards and rear guards
			frontGuards[i]->next = rearGuards[i];
			rearGuards[i]->prev = frontGuards[i];
		}
	}
}

//Pre-condition: If we have a empty list
//Destructor of SkipList. empty list and delete frontGuards and rearGuards
SkipList::~SkipList()
{
	//We are going to delete the frontGuard after deleting all the nodes in between
	SNode* current = frontGuards[0]->next;
	SNode* temp;

	//Traversing the list to delete all the nodes in between frontGuard and rearGuard
	while (current != rearGuards[0]) {
		temp = current->next;
		//Help us remove all the data from all levels
		Remove(current->data);
		current = temp;
	}

	int current_level = 0;
	//Now we delete all the frontGuards and the rearGuards of all depth
	while (current_level != depth - 1) {
		delete frontGuards[current_level];
		delete rearGuards[current_level];
		current_level = current_level + 1;
	}

	//Deleting the guards altogether
	delete[] frontGuards;
	delete[] rearGuards;
}

//Pre-condition: No duplicates can be added. The data added have to be in between INT_MAX and INT_MIN.
//Return true if the node has successfully been added and false otherwise
bool SkipList::Add(int data)
{
	SNode* new_node = new SNode(data);

	//check if the data is already in the list. If so we return false because we can't have duplicates
	if (Contains(data) == true) {
		cerr << "Duplicate data, fail to add." << endl;
		return false;
	}

	SNode* current = frontGuards[0];

	//traversing the list at level 0 to find a palce for the new data
	while ((current != nullptr) && (current->data < new_node->data)) {
		current = current->next;
	}//Gets out of while loop if data is bugger than the new_node or current is a nullptr

	addBefore(new_node, current);

	//We already added data to level 0 so we move to level 1
	int current_level = 1;

	//The downNode is going to be our new node with the data in every level. It is called down node because it is located in the downLevel.
	//The downNode is always going to stay the same, we just need to set the topNode to the downNode every level.
	SNode* downNode = new_node;

	//while alsoHigher saids the value should go in the next level
	while (alsoHigher() == true && current_level < depth) {
		current = frontGuards[current_level];
		//adding the data to the next level
		SNode* topNode = new SNode(data);
		//Adding in the top node topNode 
		topNode->downLevel = downNode;
		downNode->upLevel = topNode;

		//Same thing as what we did for level 0 except we are also doing it for other levels too
		//traverse the list to find the place for the new node
		while ((current != nullptr) && (current->data < new_node->data)) {
			current = current->next;
		}

		if ((current != nullptr) && (current->data > new_node->data)) {
			addBefore(topNode, current);
		}
		current_level = current_level + 1;
	}

	return true;
	
}

//Pre-condition: Cannot remove a node that does not exist in the SkipList. The data that is removed have to be in between INT_MIN and INT_MAX.
//Return true if node was successfully removed and return false otherwise
bool SkipList::Remove(int data)
{
	//Before we try to remove the data we should check if the data even exists in the list
	if (Contains(data) == false) {
		cerr << "Data does not exist, cannot remove" << endl;
		return false;
	}

	SNode* current = nullptr;

	//going down the levels
	for (int i = depth - 1; i >= 0; i--) {
		current = frontGuards[i];

		//while the current does not equal data we continue to traverse the list
		while ((current != nullptr) && (current->data != data)) {
			current = current->next;
		}

		//If we found the data and the current is not null
		if ((current != nullptr) && (current->data = data)) {
			//define the next and prev node
			SNode* next = current->next;
			SNode* prev = current->prev;

			//Now exclude the node we want to delete from list
			next->prev = prev;
			prev->next = next;
		}
		/*else if((current != nullptr) && (current->next == nullptr)) {
			SNode* next = nullptr;
			SNode* prev = current->prev;
			//set the rearGuard to the previous node
			rearGuards[i] = prev;
			prev->next = next;
		} 
		*/
		//We assume that if the current data is not the data we want to remove at this point then the current data is null.
	}
	return true;
}

//Return true if the data exist in list and return false otherwise
//We only need to check level 0 and see if it contains the data because level 0 have all teh values the others levels have.
bool SkipList::Contains(int data)
{
	SNode* current = frontGuards[0];

	while (current->next != nullptr) {
		current = current->next;
		if (current->data == data) {
			return true;
		}
	}

	//return false if the value is not found
	return false;
}

//Adds new node before the next node
void SkipList::addBefore(SNode* newNode, SNode* nextNode)
{
	//Set the new node next pointer to the nextNode and the prev pointer to the prev node of nextNode
	newNode->next = nextNode;
	newNode->prev = nextNode->prev;

	//Now we have to change the pointer of the nextNode
	nextNode->prev->next = newNode;
	nextNode->prev = newNode;
}

//Return true 50% of the time and return false the other 50% of the time
bool SkipList::alsoHigher() const
{
	return rand() % 2 == 1;
}

//Constructor of SNode. Sets the data of the node to the data in the argument. 
SkipList::SNode::SNode(int data)
{
	this->data = data;
	upLevel = nullptr;
	downLevel = nullptr;
	next = nullptr;
	prev = nullptr;
}
