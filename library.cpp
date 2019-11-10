#include "library.h"

Library::Library(string file)
{
    //! maksut: read the file inputted to the books array
}

void Library::Add(Book book)
{
    //! maksut: the function should get a book instance and append it to the end of the books array
}

void Library::Delete(int id)
{
    //! maksut: the function should get an id of the element (index starts from 0) to be deleted and delete the book instance at that id in books
}

void Library::Modify(int id, Book book)
{
    //! maksut: the function should get an id of the element (index starts from 0) to be modified and replace it with the inputted book instance
}

int * Library::Search(/*! idk develop a solution */)
{
    //! temirlan: the function should get (1-6) attributes for author, title, year, isbn, publisher and llc
    //! idk how to implement the getting of the functions, come up with a solution and lets discuss it in our whatsapp group
    //! when you check the strings use string.find(value)!=string::npos (google find() method online), instead of ==
    //! returns the findings as an array of book ids in the books
}

void Library::Sort(int attr, bool ascending = true)
{
    //! yerdaulet: the function should get the attribute id (1 author, 2 title, 3 year, 4 isbn, 5 publisher, 6 llc)
    //! and sort the books of this instance
    //! if ascending it should sort in ascending order, if NOT ascending it should sort in descending order
}

bool Library::Issue(string isbn)
{
    //! maksut: the function should get the isbn number and decrement the num of the book instance found in the db using search() function
    //! returns true if there is 1 or more num in the book, returns false if the book was not found or its num is 0
    return true;
}

bool Library::Return(string isbn)
{
    //! maksut: the function should get the isbn number and increment the num of the book instance found in the db using search() function
    //! returns false if the book was not found, otherwise return true
    return true;
}

Book Library::getBook(int id)
{
    return books[id];
}
