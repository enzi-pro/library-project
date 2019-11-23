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
    cout << "Enter the path to the CSV file >>" << endl;
    getline(cin, input);
    Library library;
    try
    {
        library = Library(input);
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
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
        cout << "Type in the command number (the program will terminate if the input is not an integer) >>" << endl;
        try
        {
            if (!(cin >> command))
            {
                throw invalid_argument("The command has to be an integer");
            }
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;
            return -1;
        }
        cin.ignore();
        switch (command)
        {
        case 1:
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
            cout << "Type in the number of these books in stock (the program will terminate if the input is not an integer) >>" << endl;
            try
            {
                if (!(cin >> temp))
                {
                    throw invalid_argument("The number has to be an integer");
                }
            }
            catch (exception& e)
            {
                cerr << e.what() << endl;
                return -1;
            }
            cin.ignore();
            library.Add(Book(library.getCount(), author, title, year, isbn, publisher, llc, static_cast<ostringstream*>( &(ostringstream() << temp) )->str()));
            break;
        case 2:
            cout << "Choose the book to be deleted. Enter its ID in the database (the program will terminate if the input is not an integer) >>" << endl;
            try
            {
                if (!(cin >> id))
                {
                    throw invalid_argument("The ID has to be an integer");
                }
            }
            catch (exception& e)
            {
                cerr << e.what() << endl;
                return -1;
            }
            cin.ignore();
            library.Delete(id);
            break;
        case 3:
            cout << "Choose the book to be modified. Enter its ID in the database (the program will terminate if the input is not an integer) >>" << endl;
            try
            {
                if (!(cin >> id))
                {
                    throw invalid_argument("The ID has to be an integer");
                }
            }
            catch (exception& e)
            {
                cerr << e.what() << endl;
                return -1;
            }
            cin.ignore();
            do
            {
                cout << "Choose the element to be modified" << endl;
                author = library.getBook(id).getAuthor();
                title = library.getBook(id).getTitle();
                year = library.getBook(id).getYear();
                isbn = library.getBook(id).getIsbn();
                publisher = library.getBook(id).getPublisher();
                llc = library.getBook(id).getLlc();
                cout << "1: Author = " << author << endl;
                cout << "2: Title = " << title << endl;
                cout << "3: Year = " << year << endl;
                cout << "4: ISBN = " << isbn << endl;
                cout << "5: Publisher = " << publisher << endl;
                cout << "6: LLC = " << llc << endl;
                // static_cast was used because of a compiler error with the to_string method
                cout << "7: Stock number = " << static_cast<ostringstream*>( &(ostringstream() << library.getBook(id).getNum()) )->str() << endl;
                cout << "Type in the element number (the program will terminate if the input is not an integer) >>" << endl;
                try
                {
                    if (!(cin >> element))
                    {
                        throw invalid_argument("The element has to be an integer");
                    }
                }
                catch (exception& e)
                {
                    cerr << e.what() << endl;
                    return -1;
                }
                cin.ignore();
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
                        cout << "Enter the number of these books in stock (the program will terminate if the input is not an integer) >>" << endl;
                        try
                        {
                            if (!(cin >> temp))
                            {
                                throw invalid_argument("The number has to be an integer");
                            }
                        }
                        catch (exception& e)
                        {
                            cerr << e.what() << endl;
                            return -1;
                        }
                        cin.ignore();
                        break;
                    default:
                        cout << "There is no such element" << endl;
                        break;
                }
                library.Modify(Book(id, author, title, year, isbn, publisher, llc, static_cast<ostringstream*>( &(ostringstream() << temp) )->str()));
                cout << "Input y to change a different element or input any other character to terminate >>" << endl;
                getline(cin, input);
                repeat_elements = input == "y";
            } while (repeat_elements);
            break;
        case 4: {
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
            cout << "Choose the element to be used as the sorting attribute" << endl;
            cout << "1: Author" << endl;
            cout << "2: Title" << endl;
            cout << "3: Year" << endl;
            cout << "4: ISBN" << endl;
            cout << "5: Publisher" << endl;
            cout << "6: LLC" << endl;
            cout << "Type in the element number (the program will terminate if the input is not an integer) >>" << endl;
            try
            {
                if (!(cin >> element))
                {
                    throw invalid_argument("The element has to be an integer");
                }
            }
            catch (exception& e)
            {
                cerr << e.what() << endl;
                return -1;
            }
            cin.ignore();
            cout << "Input y to do an ascending sort or enter any other character to do a descending sort >>" << endl;
            getline(cin, input);
            library.Sort(element, input == "y");
            break;
        case 6:
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
            cout << "Type in the ISBN of the book >>" << endl;
            getline(cin, isbn);;
            if (library.Return(isbn))
                cout << "The book was successfully returned" << endl;
            else
                cout << "This book could not be found in the database" << endl;
            break;
        case 8:
            for(int j = 1; j < library.getCount(); j++)
            {
                cout << library.getBook(j).toString() << endl;
            }
            break;
        case 9:
            cout << "Enter the name of the new CSV file (do not forget to write .csv or .txt) >>" << endl;
            getline(cin, input);
            library.Save(input);
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
