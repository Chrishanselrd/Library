#ifndef LIBRARY_H
#define LIBRARY_H

#include "item.h"
#include "book.h"
#include "patron.h"
#include "childrenbook.h"
#include "fictionbook.h"
#include "periodical.h"
#include "bintree.h"
#include "hashtable.h"
#include "itemfactory.h"
#include "actionfactory.h"
#include "action.h"

//---------------------------------------------------------------------------
// Library:  This is a library class that manages users and books and keeps
//           track their relationship to one another. It performs actions
//           based on what it reads from the text file it receives in
//           readActions() to assign books and users to one another

// Implementation and assumptions:
//   -- be able to read create and store data
//   -- connects everything
//   -- has factories to create item and action

using namespace std;

class Library
{
private:
    // Factories
    ItemFactory itmFactory;
    ActionFactory actFactory;

    // Containers
    // An array of BST that correlates to each item
    BinTree bookContainer[26];

    // user container
    HashTable userContainer;

    // Current Pointers
    Patron *currentPatron;
    Item *currentItem;

public:
    // Constructor
    Library(){};

    // Destructor
    ~Library(){};

    // Processes text files
    void readUsers(const string &filename);
    void readBooks(const string &filename);
    void readActions(const string &filename);

    // Display
    void displayBooks() const;
    void displayUsers() const;
    void displayB() const;

    // retrieves patron based on id
    Patron *retrievePatron(int id) const;

    // retrieves book based on title and author
    Item *retrieveBook(char type, Item *target) const;
};
#endif