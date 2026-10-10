#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "D:/2 курс 1 семестр/LAB 1.4/Project1/Book.h"
#include "D:/2 курс 1 семестр/LAB 1.4/Project1/HomeLibrary.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(BookTests)
    {
    public:

        TEST_METHOD(TestDefaultConstructor)
        {
            Book book;

            Assert::IsTrue(book.GetTitle() == "Unknown");
            Assert::IsTrue(book.GetAuthor() == "Unknown");
            Assert::AreEqual(1, book.GetYear());
        }

        TEST_METHOD(TestParameterizedConstructor)
        {
            Book book("Kobzar", "Shevchenko", 1840);

            Assert::IsTrue(book.GetTitle() == "Kobzar");
            Assert::IsTrue(book.GetAuthor() == "Shevchenko");
            Assert::AreEqual(1840, book.GetYear());
        }

        TEST_METHOD(TestSetters)
        {
            Book book;

            Assert::IsTrue(book.SetTitle("Kobzar"));
            Assert::IsTrue(book.SetAuthor("Shevchenko"));
            Assert::IsTrue(book.SetYear(1840));

            Assert::IsTrue(book.GetTitle() == "Kobzar");
            Assert::IsTrue(book.GetAuthor() == "Shevchenko");
            Assert::AreEqual(1840, book.GetYear());
        }

        TEST_METHOD(TestInvalidValues)
        {
            Book book("Kobzar", "Shevchenko", 1840);

            Assert::IsFalse(book.SetTitle(""));
            Assert::IsFalse(book.SetAuthor("   "));
            Assert::IsFalse(book.SetYear(0));
            Assert::IsFalse(book.SetYear(3000));

            Assert::IsTrue(book.GetTitle() == "Kobzar");
            Assert::IsTrue(book.GetAuthor() == "Shevchenko");
            Assert::AreEqual(1840, book.GetYear());
        }

        TEST_METHOD(TestInit)
        {
            Book book;
            book.Init("1984", "George Orwell", 1949);

            Assert::IsTrue(book.GetTitle() == "1984");
            Assert::IsTrue(book.GetAuthor() == "George Orwell");
            Assert::AreEqual(1949, book.GetYear());
        }

        TEST_METHOD(TestToString)
        {
            Book book("1984", "George Orwell", 1949);

            string result = book.toString();

            Assert::IsTrue(result.find("1984") != string::npos);
            Assert::IsTrue(result.find("George Orwell") != string::npos);
            Assert::IsTrue(result.find("1949") != string::npos);
        }

        TEST_METHOD(TestInitRejectsInvalidValues)
        {
            Book book("1984", "George Orwell", 1949);
            book.Init("", "", 0);

            Assert::IsTrue(book.GetTitle() == "1984");
            Assert::IsTrue(book.GetAuthor() == "George Orwell");
            Assert::AreEqual(1949, book.GetYear());
        }
    };

    TEST_CLASS(HomeLibraryTests)
    {
    public:

        TEST_METHOD(TestAddBook)
        {
            HomeLibrary library;
            Book book("Kobzar", "Shevchenko", 1840);

            library.AddBook(book);

            Assert::AreEqual(1, library.GetCount());
        }

        TEST_METHOD(TestDuplicateBook)
        {
            HomeLibrary library;
            Book book("Kobzar", "Shevchenko", 1840);

            library.AddBook(book);
            library.AddBook(book);

            Assert::AreEqual(1, library.GetCount());
        }

        TEST_METHOD(TestDeleteBook)
        {
            HomeLibrary library;
            library.AddBook(Book("Kobzar", "Shevchenko", 1840));

            Assert::IsTrue(library.DeleteBook("Kobzar"));
            Assert::AreEqual(0, library.GetCount());
        }

        TEST_METHOD(TestDeleteMissingBook)
        {
            HomeLibrary library;

            Assert::IsFalse(library.DeleteBook("Unknown"));
            Assert::AreEqual(0, library.GetCount());
        }

        TEST_METHOD(TestSortByTitle)
        {
            HomeLibrary library;

            library.AddBook(Book("Zebra", "Author A", 2000));
            library.AddBook(Book("Apple", "Author B", 2001));

            library.SortByTitle();

            Assert::AreEqual(2, library.GetCount());
        }

        TEST_METHOD(TestSortByAuthor)
        {
            HomeLibrary library;

            library.AddBook(Book("Book A", "Zebra", 2000));
            library.AddBook(Book("Book B", "Apple", 2001));

            library.SortByAuthor();

            Assert::AreEqual(2, library.GetCount());
        }

        TEST_METHOD(TestSortByYear)
        {
            HomeLibrary library;

            library.AddBook(Book("New", "Author A", 2000));
            library.AddBook(Book("Old", "Author B", 1900));

            library.SortByYear();

            Assert::AreEqual(2, library.GetCount());
        }
    };
}