#ifndef CHILDRENBOOK_H
#define CHILDRENBOOK_H

#include "item.h"
#include "book.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

//---------------------------------------------------------------------------
// Children Book:  The ChildrenBook class represents an item in the library
//                 system. It inherits from the Item and Book class and
//                 includes additional data members specific to children
//                 books, such as title, author, date

// Implementation and assumptions:
//   -- inherits item class
//   -- takes in data in the form of author title then year
//   -- SORTED by Title then Author
//   -- has operator for storing

class ChildrenBook : public Book
{
private:
    string author;
    string title;
    int year;
    char code = 'C';

public:
    // Constructor
    ChildrenBook();

    // Destructor
    virtual ~ChildrenBook();

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