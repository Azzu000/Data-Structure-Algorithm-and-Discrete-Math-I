#include <iostream>
#include "library.h"
using namespace std;

//No Args constructor (auto)
Library::Library()
{
    this->count_books = 0;
    this->library_name = "library name not set";
}

//Arugument constructor for library name
Library::Library(string name)
{
    this->count_books = 0;
    this->library_name = name;
}

//Gets the name of library
string Library::name()
{
    return this->library_name;
}

//Gets the count of books in library
int Library::count()
{
    return this->count_books;
}

//PRE-CONDITION: The library must not be full. If the library is full a message will notify user that the library is full and no more books can be added.
//Adds a book to the library, no same two books
bool Library::AddBook(const string& name)
{
    
    /*last_index is the last index of our array that is empty. Note: we can use count books to find the empty last spot in the array
    *because the array last index that is filled is always one less than the count
    */
    int last_index = count_books;
    //keeps track of the current index we are on
    int current_index = 0;

    //If the array is already full
    if ((last_index) == MAX) {
        cout << "Error: the library is full..." << endl;
        return false;
    }

    //this is to check if the book already exists in library, we don't want duplicates.
    for (int i = 0; i < last_index; i++) {
        
        if (library[i] == name) {
            cout << "Book is already in library." << endl;
            return false;
        }
    }

    library[last_index] = name;
    count_books = count_books + 1;

    return true;
}

//PRE-CONDITION: Library must not be empty. If empty a message will notify the user that the library is empty.
//Removes a book from the library
bool Library::RemoveBook(const string& name)
{
    //The last empty index of our array 
    int last_index = count_books;
    //This will keep track of the index we are on
    int current_index = 0;
    
    //If there is no books in the library then we can't remove any books
    if (count_books == 0) {
        cout << "No books in the library, cannot remove anything." << endl;
        return false;
    }

    while (library[current_index] != name) {
        //if the current book is not the book we are looking for then we move to the next index
        current_index = current_index + 1;

        //if we are already on the last index we know the book does not exist in our library
        if (current_index == last_index) {
            cout << "Searched the whole library. Cannot remove book not in library." << endl;
            return false;
        }
    }

    cout << "Removing book " << name << " from the shelf." << endl;
    //We will loop from the index the book is found to the last index
    for (int i = current_index; i < last_index - 1; i++) {
        if (current_index == last_index) {
            return true;
        }
        //Moves all the array back so there is no blank space in between the array
        library[i] = library[i + 1];
    }

    //Since the last_index constains the index of the last EMPTY slot, we have to do -1 in order to get the last_index that is not empty.
    library[last_index - 1] = "";
    count_books = count_books - 1;
    return true;
}

//PRE-CONDITION: The library mus tnot be empty. If the library is empty a message will notify the user that the library is empty.
//List all the books in a library
void Library::ListAllBooks() const
{
    //Check if library is empty
    if (count_books == 0) {
        cout << " No books in library. Cannot list any books." << endl;
    }

    //The last empty index of our array that is empty.
    int last_index = count_books;
    for (int i = 0; i < last_index + 1; i++) {
        cout << library[i] << endl;
    }
}

//PRE-CONDITION: The library must not be empty. If the library is empty then a message will notify the user that the library is empty.
//Check if book is in library.
bool Library::IsInLibrary(const string& name) const
{
    //Check if library is empty
    if (count_books == 0) {
        cout << " No books in library so book is not in library." << endl;
        return false;
    }

    int last_index = count_books;
    int current_index = 0;
    //Look at the whole array until the book is found
    while (library[current_index] != name) {
        current_index = current_index + 1;

        if (current_index == last_index) {
            cout << "Sorry, book is not in this Library." << endl;
            return false;
        }
    }

    cout << "Book " << name << " found in index " << current_index << "! " << endl;
    return true;
}

//PRE-CONDITION: The library must not be empty. If the library is empty then a message will notify the user that the library is empty.
//Finds the book in library return index of book if found, return -1 if not found
int Library::FindBook(const string& name) const
{
    //Check if library is empty
    if (count_books == 0) {
        cout << " No books in library therefore cannot find book." << endl;
        return -1;
    }

    //The last empty index
    int last_index = count_books;
    //The current index we are on
    int current_index = 0;

    while (library[current_index] != name) {
        current_index = current_index + 1;
        
        //if the book is not found
        if (current_index == last_index) {
            return -1;
        }
    }
    return current_index;
}

//PRE-CONDITION: The library must not be empty. If the library is empty then a message will notify the user that the library is empty.
//ostream operator overload
ostream& operator<<(ostream& out, const Library& lib)
{

    //Check if library is empty
    if (lib.count_books == 0) {
        out << lib.library_name << " has these books: \n" << endl;
        out << "No books in library." << endl;
    }

    //The last empty index of our array that is empty.
    int last_index = lib.count_books;
    out << lib.library_name << " has these books: \n" << endl;

    for (int i = 0; i < last_index; i++) {
        out << lib.library[i] << endl;
    }

    return out;
}
