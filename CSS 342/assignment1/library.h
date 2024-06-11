/*Assignment 1: Library CSS 342	
* Programmed by: Ruiqi Huang
* 1/11/2023
* 
*The Library class has all the functions of a library. You can add, remove and look for books. There is a max number of 100 books you can put in the library 
* before the library is full. If you try to put too much many a message will appear notifying you that the library is full. There will also be messages through 
* the program notifying you when the library is empty, when the book you want to find is not there, when the book you want to remove is not there and etc. This 
* library also keeps track of the nunber of books you currently have in the library. All you have to do to create a library is give the library a name.
*/

#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <iostream>
#include <string>
#include <array>
using namespace std;

class Library
{
public:
	//Constructors
	Library(); //Default constructor
	Library(string name);
	
	//Getters
	//gets the name of the library
	string name();
	//gets the number of books in library
	int count();

	//Add a new book into library
	bool AddBook(const string& name);
	//Removes a book from the library
	bool RemoveBook(const string& name);
	//List all books in library
	void ListAllBooks() const;
	//Return true i book is in library, false otherwise
	bool IsInLibrary(const string& name) const;
	//friend function. Print the library name and a list of books
	friend ostream& operator<<(ostream& out, const Library& lib);

	//FindBook is public because I intend to use this method to check if the index of the items are in the right place. I did not use this method for anything else.
	//Help find a book from the library and prints out the index of the book in the array
	int FindBook(const string& name) const;

private: 
	//The max books can be in the library
	static int const MAX = 100;
	//The string array that holds the book in library
	string library[MAX];
	//The number of books in library
	int count_books = 0;
	//The library name
	string library_name;
};
#endif