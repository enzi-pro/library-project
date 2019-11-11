#include "book.h"
#ifndef LIBRARY_H
#define LIBRARY_H

class Library
{
    private:
        Book * books;
    public:
        Library(string file);
        void Add(Book book);
        void Delete(int id);
        void Modify(int id, Book book);
        int * Search(/*! idk develop a solution */);
        void Sort(int attr, bool ascending = true);
        bool Issue(string isbn);
        bool Return(string isbn);
        Book getBook(int id);
};

#endif // LIBRARY_H
