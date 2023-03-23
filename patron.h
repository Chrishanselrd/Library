#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iomanip>
#include "item.h"

using namespace std;

//---------------------------------------------------------------------------
// Patron:  The Patron class represents a user in the library
//        system. It has the data of patrons including the history.

// Implementation and assumptions:
//   -- has a container for the patron's history
//   -- has a unique id
//   -- be able to checkout, return, display history

class Patron
{
private:
    int id;
    string lastName;
    string firstName;
    vector<pair<string, Item *>> history;

public:
    // constructor and destructor
    Patron();
    Patron(int id, string lastName, string firstName);
    virtual ~Patron();

    // print patron data
    void print() const;

    // displays patron history
    void displayHistory() const;

    // checksout a book
    void checkOut(Item *book);

    // returns a book
    void returnBook(Item *book);

    // returns the user id
    int getId();
};

#endif