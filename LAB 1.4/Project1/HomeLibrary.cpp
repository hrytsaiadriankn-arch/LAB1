#include "pch.h"
#include "HomeLibrary.h"
#include <iostream>
#include <algorithm>

using namespace std;

void HomeLibrary::AddBook(const Book& book) {
    for (const Book& current : books) {
        if (current.GetTitle() == book.GetTitle() &&
            current.GetAuthor() == book.GetAuthor() &&
            current.GetYear() == book.GetYear()) {
            cout << "This book already exists.\n";
            return;
        }
    }

    books.push_back(book);
    cout << "Book added successfully.\n";
}

bool HomeLibrary::DeleteBook(const string& title) {
    auto it = find_if(books.begin(), books.end(),
        [&](const Book& book) {
            return book.GetTitle() == title;
        });

    if (it == books.end()) {
        cout << "Book not found.\n";
        return false;
    }

    books.erase(it);
    cout << "Book deleted successfully.\n";
    return true;
}

void HomeLibrary::SearchByTitle(const string& title) const {
    bool found = false;

    for (const Book& book : books) {
        if (book.GetTitle() == title) {
            book.Display();
            found = true;
        }
    }

    if (!found)
        cout << "Book not found.\n";
}

void HomeLibrary::SearchByAuthor(const string& author) const {
    bool found = false;

    for (const Book& book : books) {
        if (book.GetAuthor() == author) {
            book.Display();
            found = true;
        }
    }

    if (!found)
        cout << "Books by this author not found.\n";
}

void HomeLibrary::SearchByYear(int year) const {
    bool found = false;

    for (const Book& book : books) {
        if (book.GetYear() == year) {
            book.Display();
            found = true;
        }
    }

    if (!found)
        cout << "Books from this year not found.\n";
}

void HomeLibrary::SortByTitle() {
    sort(books.begin(), books.end(),
        [](const Book& a, const Book& b) {
            return a.GetTitle() < b.GetTitle();
        });

    cout << "Books sorted by title.\n";
}

void HomeLibrary::SortByAuthor() {
    sort(books.begin(), books.end(),
        [](const Book& a, const Book& b) {
            return a.GetAuthor() < b.GetAuthor();
        });

    cout << "Books sorted by author.\n";
}

void HomeLibrary::SortByYear() {
    sort(books.begin(), books.end(),
        [](const Book& a, const Book& b) {
            return a.GetYear() < b.GetYear();
        });

    cout << "Books sorted by year.\n";
}

void HomeLibrary::DisplayAll() const {
    if (books.empty()) {
        cout << "Library is empty.\n";
        return;
    }

    for (const Book& book : books)
        book.Display();

    cout << "Total books: " << books.size() << '\n';
}

int HomeLibrary::GetCount() const {
    return static_cast<int>(books.size());
}