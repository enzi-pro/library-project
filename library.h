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
        Library(string file);
        void Add(Book book);
        void Delete(int id);
        /*
        int * Search( idk develop a solution );
        void Sort(int attr, bool ascending = true);
        bool Issue(string isbn);
        bool Return(string isbn);
        */
        Book getBook(int id);
        int getCount();
};

#endif // LIBRARY_H
