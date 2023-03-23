#ifndef BOOK_H
#define BOOK_H

#include "item.h"
#include <string>

//---------------------------------------------------------------------------
// Book:  The Book class represents a collection of a given book in the
//        library system. The Book class serves as the parent class for more
//        specific book types, such as ChildrenBook, FictionBook, and
//        Periodical.

// Implementation and assumptions:
//   -- Be able to create the Book class

using namespace std;

class Book : public Item
{
protected:
    int checkedOut;

public:
    // Default constructor
    Book(){};

    // Destructor
    virtual ~Book(){};
};

#endif