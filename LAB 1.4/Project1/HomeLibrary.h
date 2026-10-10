#pragma once
#include "Book.h"
#include <vector>
#include <string>

class HomeLibrary {
private:
    std::vector<Book> books;

public:
    void AddBook(const Book& book);
    bool DeleteBook(const std::string& title);

    void SearchByTitle(const std::string& title) const;
    void SearchByAuthor(const std::string& author) const;
    void SearchByYear(int year) const;

    void SortByTitle();
    void SortByAuthor();
    void SortByYear();

    void DisplayAll() const;
    int GetCount() const;
};