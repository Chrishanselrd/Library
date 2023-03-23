#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include "item.h"
#include "book.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

//---------------------------------------------------------------------------
// Fiction Book:  The FictionBook class represents an item in the library
//                 system. It inherits from the Item and Book class and
//                 includes additional data members specific to fiction
//                 books, such as title, author, year

// Implementation and assumptions:
//   -- inherits item class
//   -- takes in data in the form of title author then year
//   -- SORTED by Author then title
//   -- has operator for storing

class FictionBook : public Book
{
private:
    string author;
    string title;
    int year;
    char code = 'F';

public:
    // Constructor
    FictionBook();

    // Destructor
    virtual ~FictionBook();

    // Prints info
    void print() const;

    // Sets data
    void setData(ifstream &);

    void setDataCommand(ifstream &infile);

    // Counts available copies
    int countAvailable() const;

    // Counts checked out copies
    int countCheckedOut() const;

    // Checks out a copy of the book for a given patron
    void checkOut();

    // Returns a book that is checked out
    void returnBook();

    // creates item
    virtual Item *create() const;

    // Overloaded operators
    bool operator<(const Item &other) const;
    bool operator>(const Item &other) const;
    bool operator<=(const Item &other) const;
    bool operator>=(const Item &other) const;
    bool operator==(const Item &other) const;
    bool operator!=(const Item &other) const;
};

#endif