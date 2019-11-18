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
        cout << "Enter the path to the csv file >>" << endl;
        cin >> input;
        Library library(input);
        string author, title, year, isbn, publisher, llc, num;
        int id;
        cout << "List of available commands:" << endl;
        cout << "1: Add" << endl;
        cout << "2: Delete" << endl;
        cout << "3: Modify" << endl;
        cout << "4: Search" << endl;
        cout << "5: Sort" << endl;
        cout << "6: Issue" << endl;
        cout << "7: Return" << endl;
        cout << "8: Output the library" << endl;
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
            library.Add(Book(library.getCount() + 1, author, title, year, isbn, publisher, llc, num));
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
                cout << "Choose the element to be modified" << endl;
                cout << "1: Author = " << library.getBook(id).getAuthor() << endl;
                cout << "2: Title = " << library.getBook(id).getTitle() << endl;
                cout << "3: Year = " << library.getBook(id).getYear() << endl;
                cout << "4: ISBN = " << library.getBook(id).getIsbn() << endl;
                cout << "5: Publisher = " << library.getBook(id).getPublisher() << endl;
                cout << "6: LLC = " << library.getBook(id).getLlc() << endl;
                cout << "7: Stock number = " << static_cast<ostringstream*>( &(ostringstream() << library.getBook(id).getNum()) )->str() << endl;
                cout << "Type in the element number >>" << endl;
                cin >> element;
                switch (element)
                {
                    case 1:
                        cout << "Enter the new author >>" << endl;
                        getline(cin, input);
                        library.getBook(id).setAuthor(input);
                    case 2:
                        cout << "Enter the new title >>" << endl;
                        getline(cin, input);
                        library.getBook(id).setTitle(input);
                    case 3:
                        cout << "Enter the new year >>" << endl;
                        getline(cin, input);
                        library.getBook(id).setAuthor(input);
                    case 4:
                        cout << "Enter the new ISBN >>" << endl;
                        getline(cin, input);
                        library.getBook(id).setIsbn(input);
                    case 5:
                        cout << "Enter the new publisher >>" << endl;
                        getline(cin, input);
                        library.getBook(id).setPublisher(input);
                    case 6:
                        cout << "Enter the new LLC >>" << endl;
                        getline(cin, input);
                        library.getBook(id).setLlc(input);
                    case 7:
                        cout << "Enter the number of these books in stock >>" << endl;
                        getline(cin, input);
                        library.getBook(id).setNum(input);
                    default:
                        cout << "There is no such element" << endl;
                        break;
                }
                cout << "Would you like to do a change a different element? (y) >>" << endl;
                cin >> input;
                repeat_2 = input == "y";
            } while (repeat_2);
            break;
            /*
        case 4:
            in the works
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
            */
        case 8:
            for(int j = 1; j < library.getCount(); j++)
            {
                cout<<library.getBook(j).toString()<<endl;
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
