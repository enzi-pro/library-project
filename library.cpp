#include "library.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> split(string line)
{
    vector<string> lines;
    string subString="";
    for(unsigned int i=0;i<line.size();i++)
    {
        if(line[i] !=';')
        {
            subString += line[i];
        }
        else
        {
            lines.push_back(subString);
            subString="";
        }
    }
    return lines;
}

Library::Library(string file_path)
{
    string line;
    vector<string> lines;
    fstream file(file_path, ios::in);
    if(!file){
        cout<<"Sorry, this file does not exist"<<endl;
    }
    for (int i=0;i<=127;i++)
    {
        getline(file, line);
        lines = split(line);
        books.push_back(Book(books.size(),lines[1],lines[2],lines[3],lines[4],lines[5],lines[6],lines[7]));
    }
}

void Library::Add(Book book)
{
    books.push_back(book);
}

void Library::Delete(int id)
{
    books.erase(books.begin() + id);
}

/*
int * Library::Search(! idk develop a solution )
{
    yerdaulet: the function should get (1-6) attributes for author, title, year, isbn, publisher and llc
    idk how to implement the getting of the functions, come up with a solution and lets discuss it in our whatsapp group
    when you check the strings use string.find(value)!=string::npos (google find() method online), instead of ==
    returns the findings as an array of book ids in the books
}

void Library::Sort(int attr, bool ascending = true)
{
    yerdaulet: the function should get the attribute id (1 author, 2 title, 3 year, 4 isbn, 5 publisher, 6 llc)
    and sort the books of this instance
    if ascending it should sort in ascending order, if NOT ascending it should sort in descending order
}

bool Library::Issue(string isbn)
{
    temirlan: the function should get the isbn number and decrement the num of the book instance found in the db using search() function
    returns true if there is 1 or more num in the book, returns false if the book was not found or its num is 0
    return true;
}

bool Library::Return(string isbn)
{
    temirlan: the function should get the isbn number and increment the num of the book instance found in the db using search() function
    returns false if the book was not found, otherwise return true
    return true;
}
*/

Book Library::getBook(int id)
{
    return books[id];
}

int Library::getCount()
{
    return books.size();
}
