#include "pch.h"
#include "Book.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cctype>

using namespace std;

namespace {
    bool IsValidText(const string& text) {
        for (unsigned char c : text) {
            if (!isspace(c))
                return true;
        }
        return false;
    }

    int CurrentYear() {
        time_t now = time(nullptr);
        tm localTime{};

#ifdef _WIN32
        localtime_s(&localTime, &now);
#else
        localtime_r(&now, &localTime);
#endif

        return localTime.tm_year + 1900;
    }
}

Book::Book() : title("Unknown"), author("Unknown"), year(1) {}

Book::Book(const string& title, const string& author, int year)
    : Book() {
    Init(title, author, year);
}

string Book::GetTitle() const {
    return title;
}

string Book::GetAuthor() const {
    return author;
}

int Book::GetYear() const {
    return year;
}

bool Book::SetTitle(const string& title) {
    if (!IsValidText(title))
        return false;

    this->title = title;
    return true;
}

bool Book::SetAuthor(const string& author) {
    if (!IsValidText(author))
        return false;

    this->author = author;
    return true;
}

bool Book::SetYear(int year) {
    if (year < 1 || year > CurrentYear())
        return false;

    this->year = year;
    return true;
}

void Book::Init(const string& title,
    const string& author, int year) {
    SetTitle(title);
    SetAuthor(author);
    SetYear(year);
}

void Book::Read() {
    string input;
    int value;

    do {
        cout << "Enter book title: ";
        getline(cin, input);

        if (!SetTitle(input))
            cout << "Error: title cannot be empty.\n";
    } while (!IsValidText(input));

    do {
        cout << "Enter author: ";
        getline(cin, input);

        if (!SetAuthor(input))
            cout << "Error: author cannot be empty.\n";
    } while (!IsValidText(input));

    while (true) {
        cout << "Enter publication year: ";

        if (cin >> value) {
            cin.ignore(10000, '\n');

            if (SetYear(value))
                break;

            cout << "Error: invalid publication year.\n";
        }
        else {
            cout.clear();
            cin.ignore(10000, '\n');
            cout << "Error: enter an integer.\n";
        }
    }
}

void Book::Display() const {
    cout << toString() << '\n';
}

string Book::toString() const {
    ostringstream out;

    out << "Title: " << title
        << " | Author: " << author
        << " | Year: " << year;

    return out.str();
}