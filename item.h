#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//---------------------------------------------------------------------------
// Item:  The Item class represents an item in the library
//        system. It is the parent class of Book class and
//        other specific books

// Implementation and assumptions:
//   -- pure virtual
//   -- takes in data of various form
//   -- create different types of item
//   -- has operator for storing

class Item
{
protected:
    int available; // The number of available copies of the item
public:
    // Constructor
    Item(){};

    // Virtual destructor
    virtual ~Item(){};

    // Print the info of item
    virtual void print() const = 0;

    // Creates item
    virtual Item *create() const = 0;

    // Counts remaining available copies
    virtual int countAvailable() const = 0;

    // Counts checked out copies
    virtual int countCheckedOut() const = 0;

    // Virtual function to checkout an item
    virtual void checkOut() = 0;

    virtual void returnBook() = 0;

    // Virtual function to set data to an item
    virtual void setData(ifstream &infile) = 0;

    // Virtual function to set data from command
    virtual void setDataCommand(ifstream &infile) = 0;

    // Comparison operators
    virtual bool operator==(const Item &other) const = 0;
    virtual bool operator<(const Item &other) const = 0;
    virtual bool operator>(const Item &other) const = 0;
    virtual bool operator<=(const Item &other) const = 0;
    virtual bool operator>=(const Item &other) const = 0;
};

#endif
