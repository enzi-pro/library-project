#include <string>
#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book
{
    private:
        string author;
        string title;
        string year;
        string isbn;
        string publisher;
        string llc;
        int num;
    public:
        Book(string author, string title, string year, string isbn, string publisher, string llc, int num);
        void setAuthor(string author);
        string getAuthor();
        void setTitle(string title);
        string getTitle();
        void setYear(string year);
        string getYear();
        void setIsbn(string isbn);
        string getIsbn();
        void setPublisher(string publisher);
        string getPublisher();
        void setLlc(string llc);
        string getLlc();
        void setNum(int num);
        int getNum();
        string toString();
};

#endif // BOOK_H
