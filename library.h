#include "book.h"
#ifndef LIBRARY_H
#define LIBRARY_H

class Library
{
    private:
        Book books[];
    public:
        Library(string file);
        void Add(Book book);
        void Delete(int id);
        void Modify(int id, Book book);
        Book * Search(/*! idk develop a solution */);
        void Sort(string attr, bool ascending = true);
        bool Issue(string isbn);
        bool Return(string isbn);
};

#endif // LIBRARY_H
