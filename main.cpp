#include "library.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
    string input;
    //Add sort
    bool repeat_1 = false;
    bool repeat_2 = false;
    do
    {
        cout << "Enter the path to the xls file >>" << endl;
        cin >> input;
        Library library(input);
        string author, title, year, isbn, publisher, llc;
        int num, id;
        cout << "List of available commands:" << endl;
        cout << "1: Add" << endl;
        cout << "2: Delete" << endl;
        cout << "3: Modify" << endl;
        cout << "4: Search" << endl;
        cout << "5: Sort" << endl;
        cout << "6: Issue" << endl;
        cout << "7: Return" << endl;
        cout << "Type in the command number >>" << endl;
        int command, element;
        cin >> command;
        switch (command)
        {
        case 1:
            cout << "Type in the author of the book >>" << endl;
            cin >> author;
            cout << "Type in the title of the book >>" << endl;
            cin >> title;
            cout << "Type in the year the book was published >>" << endl;
            cin >> year;
            cout << "Type in the ISBN of the book >>" << endl;
            cin >> isbn;
            cout << "Type in the publisher of the book >>" << endl;
            cin >> publisher;
            cout << "Type in the LLC of the book >>" << endl;
            cin >> llc;
            cout << "Type in the number of these books in stock >>" << endl;
            cin >> num;
            library.Add(Book(author, title, year, isbn, publisher, llc, num));
            break;
        case 2:
            cout << "Choose the book to be deleted. Enter its ID in the database (0 indexed)" << endl;
            cout << "*If you do not know the ID of the use the search command (enter exit to return) >>" << endl;
            cin >> input;
            library.Delete(atoi(input.c_str()));
            break;
        case 3:
            cout << "Choose the book to be modified. Enter its ID in the database (0 indexed)" << endl;
            cout << "*If you do not know the ID of the use the search command (enter exit to return) >>" << endl;
            cin >> input;
            id = atoi(input.c_str());
            do
            {
                author = library.getBook(id).getAuthor();
                title = library.getBook(id).getTitle();
                year = library.getBook(id).getYear();
                isbn = library.getBook(id).getIsbn();
                publisher = library.getBook(id).getPublisher();
                llc = library.getBook(id).getLlc();
                num = library.getBook(id).getNum();
                cout << "Choose the element to be modified" << endl;
                cout << "1: Author = " << author << endl;
                cout << "2: Title = " << title << endl;
                cout << "3: Year = " << year << endl;
                cout << "4: ISBN = " << isbn << endl;
                cout << "5: Publisher = " << publisher << endl;
                cout << "6: LLC = " << llc << endl;
                cout << "7: Stock number = " << static_cast<ostringstream*>( &(ostringstream() << num) )->str() << endl;
                cout << "Type in the element number >>" << endl;
                cin >> element;
                switch (element)
                {
                    case 1:
                        cout << "Enter the new author >>" << endl;
                        getline(cin, input);
                        author = input;
                    case 2:
                        cout << "Enter the new title >>" << endl;
                        getline(cin, input);
                        title = input;
                    case 3:
                        cout << "Enter the new year >>" << endl;
                        getline(cin, input);
                        year = input;
                    case 4:
                        cout << "Enter the new ISBN >>" << endl;
                        getline(cin, input);
                        isbn = input;
                    case 5:
                        cout << "Enter the new publisher >>" << endl;
                        getline(cin, input);
                        publisher = input;
                    case 6:
                        cout << "Enter the new LLC >>" << endl;
                        getline(cin, input);
                        llc = input;
                    case 7:
                        cout << "Enter the number of these books in stock >>" << endl;
                        getline(cin, input);
                        num = atoi(input.c_str());
                    default:
                        cout << "There is no such element" << endl;
                        break;
                }
                cout << "Would you like to do a change a different element? (y) >>" << endl;
                cin >> input;
                repeat_2 = input == "y";
            } while (repeat_2);
            library.Modify(id, Book(author, title, year, isbn, publisher, llc, num));
            break;
        case 4:
            //! in the works
            break;
        case 5:
            cout << "Choose the element to be used as the sorting attribute" << endl;
            cout << "1: Author" << endl;
            cout << "2: Title" << endl;
            cout << "3: Year" << endl;
            cout << "4: ISBN" << endl;
            cout << "5: Publisher" << endl;
            cout << "6: LLC" << endl;
            cout << "7: Stock number" << endl;
            cout << "Type in the element number >>" << endl;
            cin >> element;
            cout << "Would you like the database to be sorted in ascending order? (y otherwise descending) >>" << endl;
            cin >> input;
            library.Sort(element, input == "y");
            break;
        case 6:
            cout << "Type in the ISBN of the book >>" << endl;
            cin >> isbn;
            if (library.Issue(isbn))
            {
                cout << "The book was successfully issued" << endl;
            } else
            {
                cout << "This book could not be found in the database or there are none in stock" << endl;
            }
            break;
        case 7:
            cout << "Type in the ISBN of the book >>" << endl;
            cin >> isbn;
            if (library.Return(isbn))
            {
                cout << "The book was successfully returned" << endl;
            } else
            {
                cout << "This book could not be found in the database" << endl;
            }
            break;
        default:
            cout << "There is no such command" << endl;
            break;
        }
        cout << "Would you like to do a different command? (y) >>" << endl;
        cin >> input;
        repeat_1 = input == "y";
    } while (repeat_1);
    return 0;
}
