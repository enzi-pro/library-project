#include "book.h"
#include <sstream>

Book::Book(string author, string title, string year, string isbn, string publisher, string llc, int num)
{
    this->author = author;
    this->title = title;
    this->year = year;
    this->isbn = isbn;
    this->publisher = publisher;
    this->llc = llc;
    this->num = num;
}

void Book::setAuthor(string author)
{
    this->author = author;
}

string Book::getAuthor()
{
    return this->author;
}

void Book::setTitle(string title)
{
    this->title = title;
}

string Book::getTitle()
{
    return this->title;
}

void Book::setYear(string year)
{
    this->year = year;
}

string Book::getYear()
{
    return this->year;
}

void Book::setIsbn(string isbn)
{
    this->isbn = isbn;
}

string Book::getIsbn()
{
    return this->isbn;
}

void Book::setPublisher(string publisher)
{
    this->publisher = publisher;
}

string Book::getPublisher()
{
    return this->publisher;
}

void Book::setLlc(string llc)
{
    this->llc = llc;
}

string Book::getLlc()
{
    return this->llc;
}

void Book::setNum(int num)
{
    this->num = num;
}

int Book::getNum()
{
    return this->num;
}

string Book::toString()
{
    Book book = *this;
    return book.getAuthor() + ", " + book.getTitle() + ", " + book.getYear() + ", " + book.getIsbn() + ", "
        + book.getPublisher() + ", " + book.getLlc() + ", " + "Stock: " + static_cast<ostringstream*>( &(ostringstream() << book.getNum()) )->str();
}
