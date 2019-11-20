#include "book.h"
#include <sstream>
#include <cstdlib>

using namespace std;

Book::Book(){
    id = 0;
    num = -100;
}

Book::Book(int id, string author, string title, string year, string isbn, string publisher, string llc, string num)
{
    this->id = id;
    this->author = author;
    this->title = title;
    this->year = year;
    this->isbn = isbn;
    this->publisher = publisher;
    this->llc = llc;
    this->num = atoi(num.c_str());
}

void Book::setId(int id)
{
    this->id = id;
}

void Book::setId(string id)
{
    this->id = atoi(id.c_str());;
}

string Book::getId()
{
    return static_cast<ostringstream*>( &(ostringstream() << this->id) )->str();
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

bool good(string a, string b) {
    string s;
    for (int i = 0; i < a.size(); i++) {
        if (isdigit(a[i])) {
            s += a[i];
        } else {
            if (s == b) return true;
            s = "";
        }
    }
    if (s == b) return true;
    return false;
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

void Book::setNum(string num)
{
    this->num = atoi(num.c_str());;
}

bool Book::same_as(string author, string title, string year, string isbn, string publisher, string llc, string num)
{
    if (!author.empty() && this->author != author)
        return false;
    if (!title.empty() && this->title != title)
        return false;
    if (!year.empty() && !good(this->year, year))
        return false;
    if (!isbn.empty() && !good(this->isbn, isbn))
        return false;
    if (!publisher.empty() && this->publisher != publisher)
        return false;
    if (!llc.empty() && this->llc != llc)
        return false;
    if (!num.empty() && this->num != atoi(num.c_str()))
        return false;
    return true;
}

int Book::getNum()
{
    //return static_cast<ostringstream*>( &(ostringstream() << this->num) )->str();
    return this->num;
}


string Book::toString()
{
    Book book = *this;
    return book.getId() + ": " + book.getAuthor() + ", " + book.getTitle() + ", " + book.getYear() + ", " + book.getIsbn() + ", "
           + book.getPublisher() + ", " + book.getLlc() + ", " + "Stock: " + to_string(book.getNum());
}
