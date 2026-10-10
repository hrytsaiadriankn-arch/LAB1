#pragma once
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    Book();
    Book(const std::string& title,
        const std::string& author, int year);

    std::string GetTitle() const;
    std::string GetAuthor() const;
    int GetYear() const;

    bool SetTitle(const std::string& title);
    bool SetAuthor(const std::string& author);
    bool SetYear(int year);

    void Init(const std::string& title,
        const std::string& author, int year);
    void Read();
    void Display() const;
    std::string toString() const;
};