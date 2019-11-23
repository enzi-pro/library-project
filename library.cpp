#include "library.h"
#include "book.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

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

bool cmp_isbn(Book one, Book two) {
    return one.getIsbn() < two.getIsbn();
}

vector<string> split(string line)
{
    vector<string> lines;
    string minilines="";
    for(unsigned int i=0; i<line.size(); i++)
    {
        if(line[i] !=';')
        {
            minilines += line[i];
        }
        else
        {
            lines.push_back(minilines);
            minilines="";
        }
    }
    return lines;
}

Library::Library(){}

Library::Library(string file_path)
{
    string line;
    vector<string> lines;
    fstream file(file_path, ios::in);
    if(!file){
        throw invalid_argument("This file does not exist");
    }
    while(getline(file, line))
    {
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
    for(int j = id; j <= this->getCount(); j++)
    {
        books[j].setId(atoi(books[j].getId().c_str()) - 1);
    }
}

void Library::Modify(Book book)
{
    books[atoi(book.getId().c_str())] = book;
}

void Library::Sort(int attr, bool ascending)
{
    if(attr == 1) {
        sort(books.begin(), books.end(), cmp_author);
    }
    else if(attr == 2) {
        sort(books.begin(), books.end(), cmp_title);
    }
    else if(attr == 3) {
        sort(books.begin(), books.end(), cmp_year);
    }
    else if(attr == 4) {
        sort(books.begin(), books.end(), cmp_isbn);
    }
    else if(attr == 5) {
        sort(books.begin(), books.end(), cmp_publisher);
    }
    else if(attr == 6) {
        sort(books.begin(), books.end(), cmp_llc);
    }
    else
    {
        return;
    }
    if(!ascending)
    {
        reverse(books.begin(), books.end());
    }
    for(int j = 0; j < this->getCount(); j++)
    {
        books[j].setId(j);
    }
}

vector<Book> Library::Search(string author, string title, string year, string isbn, string publisher, string llc)
{
    vector<Book> searchResult;
    for(int i = 1; i != this->getCount(); i++)
    {
        if (books[i].isEqual(author, title, year, isbn, publisher, llc))
        {
            searchResult.push_back(books[i]);
        }
    }
    return searchResult;
}

bool Library::Issue(string isbn)
{
    for(auto i = books.begin(); i != books.end(); i++)
    {
        if(i->getIsbn().find(isbn) != string::npos)
        {
            if(i->getNum() > 0)
            {
                i->setNum(i->getNum() - 1);
                return true;
            }
            else
                return false;
        }
    }
    return false;
}

bool Library::Return(string isbn)
{
    for(auto i = books.begin(); i != books.end(); i++)
    {
        if(i->getIsbn().find(isbn) != string::npos)
        {
            i->setNum(i->getNum() + 1);
            return true;
        }
    }
    return false;
}

void Library::Save(string name)
{
    ofstream newfile;
    newfile.open(name);
    newfile<<"#;Author;Title;Year;ISBN;Publisher;LLC;Stock;;;;;"<<endl;
    for(int j = 1; j < books.size(); j++)
        newfile << getBook(j).toCSV() << endl;
    newfile.close();
}

Book Library::getBook(int id)
{
    return books[id];
}

int Library::getCount()
{
    return books.size();
}
