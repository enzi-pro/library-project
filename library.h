#include "book.h"
#include <vector>
#include <fstream>
#include <iostream>
#ifndef LIBRARY_H
#define LIBRARY_H

using namespace std;

class Library
{
    private:
        vector<Book> books;
    public:
        Library();
        Library(string file);
        void Add(Book book);
        void Delete(int id);
        void Modify(Book book);
        void Sort(int attr, bool ascending);
        vector<Book> Search(string author, string title, string year, string isbn, string publisher, string llc);
        bool Issue(string isbn);
        bool Return(string isbn);
        void Save(string name);
        Book getBook(int id);
        int getCount();
};

#endif // LIBRARY_H
