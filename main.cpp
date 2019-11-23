#include "library.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <limits>

using namespace std;

int main()
{
    string input;
    bool repeat_commands = false;
    bool repeat_elements = false;
    bool repeat_error = false;
    cout << "WELCOME TO THE LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "Please, enter the path to the CSV file >>" << endl;
    getline(cin, input);
    Library library;
    do
    {
        try
        {
            library = Library(input);
            repeat_error = false;
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;
            cout << "Enter the path to the CSV file >>" << endl;
            getline(cin, input);
            repeat_error = true;
        }
    } while (repeat_error);
    string author, title, year, isbn, publisher, llc, num;
    int id;
    do
    {
        cout << "List of available commands:" << endl;
        cout << "1: Add" << endl;
        cout << "2: Delete" << endl;
        cout << "3: Modify" << endl;
        cout << "4: Search" << endl;
        cout << "5: Sort" << endl;
        cout << "6: Issue" << endl;
        cout << "7: Return" << endl;
        cout << "8: Output the library" << endl;
        cout << "9: Save the library" << endl;
        int command, element, temp;
        cout << "Type in the command number >>" << endl;
        cin >> command;
        while (cin.fail())
        {
            cout << "The number has to be an integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> command;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (command)
        {
        case 1:
            cout << "ADD A BOOK" << endl;
            cout << "Type in the author of the book >>" << endl;
            getline(cin, author);
            cout << "Type in the title of the book >>" << endl;
            getline(cin, title);
            cout << "Type in the year the book was published >>" << endl;
            getline(cin, year);
            cout << "Type in the ISBN of the book >>" << endl;
            getline(cin, isbn);
            cout << "Type in the publisher of the book >>" << endl;
            getline(cin, publisher);
            cout << "Type in the LLC of the book >>" << endl;
            getline(cin, llc);
            cout << "Type in the number of these books in stock >>" << endl;
            cin >> temp;
            while (cin.fail())
            {
                cout << "The number has to be an integer" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> temp;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            num = static_cast<ostringstream*>( &(ostringstream() << temp) )->str();
            library.Add(Book(library.getCount(), author, title, year, isbn, publisher, llc, num));
            cout << title << " written by " << author << " has been added to the library!" << endl;
            break;
        case 2:
            cout << "DELETE A BOOK" << endl;
            cout << "Choose the book to be deleted. Enter its ID in the database >>" << endl;
            cin >> id;
            while (cin.fail())
            {
                cout << "The number has to be an integer" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> id;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            library.Delete(id);
            cout << "The book has been deleted from the library" << endl;
            break;
        case 3:
            cout << "MODIFY A BOOK" << endl;
            cout << "Choose the book to be modified. Enter its ID in the database >>" << endl;
            cin >> id;
            while (cin.fail())
            {
                cout << "The number has to be an integer" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> id;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            do
            {
                cout << "Choose the element to be modified" << endl;
                author = library.getBook(id).getAuthor();
                title = library.getBook(id).getTitle();
                year = library.getBook(id).getYear();
                isbn = library.getBook(id).getIsbn();
                publisher = library.getBook(id).getPublisher();
                llc = library.getBook(id).getLlc();
                num = static_cast<ostringstream*>( &(ostringstream() << library.getBook(id).getNum()) )->str();
                cout << "1: Author = " << author << endl;
                cout << "2: Title = " << title << endl;
                cout << "3: Year = " << year << endl;
                cout << "4: ISBN = " << isbn << endl;
                cout << "5: Publisher = " << publisher << endl;
                cout << "6: LLC = " << llc << endl;
                // static_cast was used because of a compiler error with the to_string method
                cout << "7: Stock number = " << num << endl;
                cout << "Type in the element number >>" << endl;
                cin >> element;
                while (cin.fail())
                {
                    cout << "The number has to be an integer" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> element;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (element)
                {
                    case 1:
                        cout << "Enter the new author >>" << endl;
                        getline(cin, author);
                        break;
                    case 2:
                        cout << "Enter the new title >>" << endl;
                        getline(cin, title);
                        break;
                    case 3:
                        cout << "Enter the new year >>" << endl;
                        getline(cin, year);
                        break;
                    case 4:
                        cout << "Enter the new ISBN >>" << endl;
                        getline(cin, isbn);
                        break;
                    case 5:
                        cout << "Enter the new publisher >>" << endl;
                        getline(cin, publisher);
                        break;
                    case 6:
                        cout << "Enter the new LLC >>" << endl;
                        getline(cin, llc);
                        break;
                    case 7:
                        cout << "Enter the number of these books in stock >>" << endl;
                        cin >> temp;
                        while (cin.fail())
                        {
                            cout << "The number has to be an integer" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin >> temp;
                        }
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        num = static_cast<ostringstream*>( &(ostringstream() << temp) )->str();
                        break;
                    default:
                        cout << "There is no such element" << endl;
                        break;
                }
                library.Modify(Book(id, author, title, year, isbn, publisher, llc, num));
                cout << "The book was modified!" << endl;
                cout << "Input y to change a different element or input any other character to terminate >>" << endl;
                getline(cin, input);
                repeat_elements = input == "y";
            } while (repeat_elements);
            break;
        case 4: {
            cout << "SEARCH THE LIBRARY" << endl;
            cout << "*If you do not wish to input an element press Enter " << endl;
            cout << "Type in the author of the book >>" << endl;
            getline(cin, author);
            cout << "Type in the title of the book >>" << endl;
            getline(cin, title);
            cout << "Type in the year the book was published >>" << endl;
            getline(cin, year);
            cout << "Type in the ISBN of the book >>" << endl;
            getline(cin, isbn);
            cout << "Type in the publisher of the book >>" << endl;
            getline(cin, publisher);
            cout << "Type in the LLC of the book >>" << endl;
            getline(cin, llc);
            vector<Book> searchResult = library.Search(author, title, year, isbn, publisher, llc);
            for(unsigned int j = 0; j < searchResult.size(); j++)
                cout << searchResult[j].toString() <<endl;
            break;
        }
        case 5:
            cout << "SORT THE LIBRARY" << endl;
            cout << "Choose the element to be used as the sorting attribute" << endl;
            cout << "1: Author" << endl;
            cout << "2: Title" << endl;
            cout << "3: Year" << endl;
            cout << "4: ISBN" << endl;
            cout << "5: Publisher" << endl;
            cout << "6: LLC" << endl;
            cout << "Type in the element number >>" << endl;
            cin >> element;
            while (cin.fail())
            {
                cout << "The number has to be an integer" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> element;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input y to do an ascending sort or enter any other character to do a descending sort >>" << endl;
            getline(cin, input);
            library.Sort(element, input == "y");
            cout << "The library is now sorted!" << endl;
            break;
        case 6:
            cout << "ISSUE A BOOK" << endl;
            cout << "Type in the ISBN of the book >>" << endl;
            getline(cin, isbn);
            if (library.Issue(isbn))
            {
                cout << "The book was successfully issued" << endl;
            } else
            {
                cout << "This book could not be found in the database or there are none in stock" << endl;
            }
            break;
        case 7:
            cout << "RETURN A BOOK" << endl;
            cout << "Type in the ISBN of the book >>" << endl;
            getline(cin, isbn);;
            if (library.Return(isbn))
                cout << "The book was successfully returned" << endl;
            else
                cout << "This book could not be found in the database" << endl;
            break;
        case 8:
            cout << "THE LIBRARY:" << endl;
            for(int j = 1; j < library.getCount(); j++)
            {
                cout << library.getBook(j).toString() << endl;
            }
            break;
        case 9:
            cout << "SAVE THE LIBRARY" << endl;
            cout << "Enter the name of the new CSV file (do not forget to write \'.csv\' or \'.txt\') >>" << endl;
            getline(cin, input);
            library.Save(input);
            cout << "The library has been successfully saved to " << input << endl;
            break;
        default:
            cout << "There is no such command" << endl;
            break;
        }
        cout << "Input y to do a different command or input any other character to save and terminate >>" << endl;
        getline(cin, input);
        repeat_commands = input == "y";
    } while (repeat_commands);
    return 0;
}
