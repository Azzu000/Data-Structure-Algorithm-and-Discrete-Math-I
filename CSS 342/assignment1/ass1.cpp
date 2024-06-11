/*This is our driver class. This class is used to run our library class. I use this class to test the library class and make sure the class works properly. 
*/
#include <iostream>
#include <cassert>
#include "library.h"

using namespace std;

//Tests from the Assignment 
void Test1() {
	Library libs("UWB");
	libs.AddBook("Don Quixote");
	libs.AddBook("In Search of Lost Time");
	libs.AddBook("Ulysses");
	libs.AddBook("The Odyssey");
	libs.ListAllBooks();
	//should generate already in library message and return true
	bool result = libs.IsInLibrary("The Odyssey");
	assert(result);

	//cannot add book twice, result should be false
	result = libs.AddBook("The Odyssey");
	assert(!result);

	//test remove, result should be true
	result = libs.RemoveBook("The Odyssey");
	assert(result);

	//not in library, result should be false
	result = libs.IsInLibrary("The Odyssey");
	assert(!result);

	//cannot remove twice, result should be false
	result = libs.RemoveBook("The Odyssey");
	assert(!result);
}

//My Tests I created
void MyTest() {
	Library lib1("Milton Library");

	cout << "\nTesting AddBook:" << endl;
	lib1.AddBook("The Great Way");
	lib1.AddBook("The Warrior");
	lib1.AddBook("Miss Walkers");
	lib1.AddBook("The Golden flower");
	lib1.AddBook("Sunflowers");

	//lib1.ListAllBooks();

	lib1.AddBook("The Keeper");
	//This test is adding the same book, should notify us that we can't do so.
	lib1.AddBook("Miss Walkers");
	lib1.AddBook("Secret Chamber");
	lib1.AddBook("I am the Villain");
	cout << lib1 << endl;

	cout << "\nTesting RemoveBook:" << endl;
	//testing RemoveBook method
	lib1.RemoveBook("Secret Chamber");
	lib1.RemoveBook("The Keeper");

	//lib1.IsInLibrary("Sunflowers");

	cout << lib1 << endl;

	cout << "\nTesting index of books:" << endl;
	//Should be in index 0 since it is the first element in array
	cout << "Index of last book: " << lib1.FindBook("The Great Way") << endl;
	//Should be in index 5 since that is the last element in array
	cout << "Index of last book: " << lib1.FindBook("I am the Villain") << endl;

	cout << "\nTesting Empty library:" << endl;

	//This library will remain empty to test the functions message output when library is empty.
	Library lib2("Empty Library");
	cout << "\n Message for empty library RemoveBook method:" << endl;
	lib2.RemoveBook("No Book");
	cout << "\n Message for empty library FindBook method:" << endl;
	lib2.FindBook("No Book");
	cout << "\n Message for empty library IsInLibrary method:" << endl;
	lib2.IsInLibrary("No Book");
	cout << "\n Message for empty library ListAllBooks method:" << endl;
	lib2.ListAllBooks();

	cout << "\nTesting ListAllBooks and IsInLibrary: " << endl;
	Library lib3("Seattle Library");
	lib3.AddBook("A");
	lib3.AddBook("New");
	lib3.AddBook("Book");
	lib3.ListAllBooks();
	//Should find the index of this book.
	lib3.IsInLibrary("A");
	//Should say not in library.
	lib3.IsInLibrary("Not in library");

	cout << "\nTesting Getters:" << endl;
	cout << lib1.name() << " currently have " << lib1.count() << " books." << endl;

}

void TestAll() {
	Test1();
	MyTest();
	cout << "Successfully completed all tests." << endl;
}

int main() {

	TestAll();
	
	return 0;
}