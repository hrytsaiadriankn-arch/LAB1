#include "pch.h"
#include "Book.h"
#include "HomeLibrary.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int ReadInt(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: enter an integer.\n";
    }
}

int main() {
    HomeLibrary library;

    // 1. Default constructor and Init()
    Book first;
    first.Init("Kobzar", "Taras Shevchenko", 1840);

    // 2. Parameterized constructor
    Book second("Forest Song", "Lesya Ukrainka", 1911);

    // 3. Array of objects
    Book sampleBooks[2] = {
        Book("The Hobbit", "J. R. R. Tolkien", 1937),
        Book("1984", "George Orwell", 1949)
    };

    library.AddBook(first);
    library.AddBook(second);

    for (const Book& book : sampleBooks)
        library.AddBook(book);

    int choice;

    do {
        cout << "\n===== HOME LIBRARY =====\n";
        cout << "1. Display all books\n";
        cout << "2. Add a book\n";
        cout << "3. Delete a book\n";
        cout << "4. Search by title\n";
        cout << "5. Search by author\n";
        cout << "6. Search by year\n";
        cout << "7. Sort by title\n";
        cout << "8. Sort by author\n";
        cout << "9. Sort by year\n";
        cout << "10. Demonstrate Book methods\n";
        cout << "11. Show number of books\n";
        cout << "0. Exit\n";

        choice = ReadInt("Your choice: ");

        switch (choice) {
        case 1:
            library.DisplayAll();
            break;

        case 2: {
            Book book;
            book.Read();
            library.AddBook(book);
            break;
        }

        case 3: {
            string title;
            cout << "Enter title to delete: ";
            getline(cin, title);
            library.DeleteBook(title);
            break;
        }

        case 4: {
            string title;
            cout << "Enter title: ";
            getline(cin, title);
            library.SearchByTitle(title);
            break;
        }

        case 5: {
            string author;
            cout << "Enter author: ";
            getline(cin, author);
            library.SearchByAuthor(author);
            break;
        }

        case 6: {
            int year = ReadInt("Enter publication year: ");
            library.SearchByYear(year);
            break;
        }

        case 7:
            library.SortByTitle();
            library.DisplayAll();
            break;

        case 8:
            library.SortByAuthor();
            library.DisplayAll();
            break;

        case 9:
            library.SortByYear();
            library.DisplayAll();
            break;

        case 10: {
            Book book;
            book.Read();

            cout << "\nDisplay():\n";
            book.Display();

            cout << "\ntoString():\n";
            cout << book.toString() << '\n';

            cout << "\nGetters:\n";
            cout << "Title: " << book.GetTitle() << '\n';
            cout << "Author: " << book.GetAuthor() << '\n';
            cout << "Year: " << book.GetYear() << '\n';

            cout << "\nTesting setters:\n";

            cout << "SetTitle: "
                << (book.SetTitle("New Title") ? "OK" : "Error")
                << '\n';

            cout << "SetAuthor: "
                << (book.SetAuthor("New Author") ? "OK" : "Error")
                << '\n';

            cout << "SetYear: "
                << (book.SetYear(2020) ? "OK" : "Error")
                << '\n';

            cout << "Invalid title rejected: "
                << (!book.SetTitle("") ? "YES" : "NO") << '\n';

            cout << "Invalid author rejected: "
                << (!book.SetAuthor("   ") ? "YES" : "NO") << '\n';

            cout << "Invalid year rejected: "
                << (!book.SetYear(0) ? "YES" : "NO") << '\n';

            cout << "\nInit():\n";
            book.Init("Test Book", "Test Author", 2022);
            book.Display();

            cout << "\nFinal object:\n";
            book.Display();
            break;
        }

        case 11:
            cout << "Number of books: "
                << library.GetCount() << '\n';
            break;

        case 0:
            cout << "Program finished.\n";
            break;

        default:
            cout << "Invalid menu option.\n";
        }

    } while (choice != 0);

    return 0;
}