#include <string>
#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book
{
    private:
        int id;
        string author;
        string title;
        string year;
        string isbn;
        string publisher;
        string llc;
        int num;
    public:
        Book(int id, string author, string title, string year, string isbn, string publisher, string llc, string num);
        bool isEqual(string author, string title, string year, string isbn, string publisher, string llc);
        void setId(int id);
        void setId(string id);
        string getId();
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
        void setNum(string num);
        int getNum();
        string toString();
        string toCSV();
};

#endif // BOOK_H
