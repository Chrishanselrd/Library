#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "item.h"
#include "book.h"
#include <fstream>
#include <iostream>
#include <iomanip>

//---------------------------------------------------------------------------
// Periodical:  The FictionBook class represents an item in the library
//                 system. It inherits from the Item and Book class and
//                 includes additional data members specific to periodical
//                 , such as title, month, year

// Implementation and assumptions:
//   -- inherits item class
//   -- takes in data in the form of title author then year
//   -- SORTED by date(year, month) then by title
//   -- has operator for storing

class Periodical : public Book
{
private:
    string title;
    int month;
    int year;
    char code = 'P';

public:
    // Constructors
    Periodical();

    // Destructor
    virtual ~Periodical();

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

    // create item
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
