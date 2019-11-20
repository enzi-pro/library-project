#include "library.h"
#include "book.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool cmp_author(Book one, Book two) {
    return one.getAuthor() < two.getAuthor();
}
bool cmp_title(Book one, Book two) {
    return one.getTitle() < two.getTitle();
}
bool cmp_year(Book one, Book two) {
    return one.getYear() < two.getYear();
}
bool cmp_publisher(Book one, Book two) {
    return one.getPublisher() < two.getPublisher();
}
bool cmp_llc(Book one, Book two) {
    return one.getLlc() < two.getLlc();
}
bool cmp_num(Book one, Book two) {
    return one.getNum() < two.getNum();
}
bool cmp_isbn(Book one, Book two) {
    return one.getIsbn() < two.getIsbn();
}
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

void Library::printBook() {
    for(int i = 0; i < books.size(); i++) {
        cout << books[i].toString() << "\n";
    }
}
void Library::Add(Book book)
{
    books.push_back(book);
}

void Library::Delete(int id)
{
    books.erase(books.begin() + id);
    for(int j = id; j <= this->getCount(); j++)
    {
        books[j].setId(atoi(books[j].getId().c_str()) - 1);
    }
}
void Library::sortLibrary(int attr, string order)
{
    if(attr == 1) {
        sort(books.begin(), books.end(), cmp_author);
    }
    if(attr == 2) {
        sort(books.begin(), books.end(), cmp_title);
    }
    if(attr == 3) {
        sort(books.begin(), books.end(), cmp_year);
    }
    if(attr == 4) {
        sort(books.begin(), books.end(), cmp_isbn);
    }
    if(attr == 5) {
        sort(books.begin(), books.end(), cmp_publisher);
    }
    if(attr == 6) {
        sort(books.begin(), books.end(), cmp_llc);
    }
    if(attr == 7) {
        sort(books.begin(), books.end(), cmp_num);
    }
    if(order != "y") {
        reverse(books.begin(), books.end());
    }

}


void Library::Search(Book x)
{

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
