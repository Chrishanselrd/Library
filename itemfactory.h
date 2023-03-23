/*
 * This is a factory for class Book
 * The factory will produce different children objects of Book for the library
 * to create
 */
#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

class Item;

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//---------------------------------------------------------------------------
// ItemFactory:  The Item factory class represents a factory that creates
//        items in the library system. It is shold be able to make different
//        types of items

// Implementation and assumptions:
//   -- has an array with index corresponding to specified item types
//   -- takes in data of various form
//   -- create different types of item

class ItemFactory
{
private:
    // contains array of each book correlating index to alphabet
    // A = 0, B = 1, C = 2
    Item *itemFactory[26];

    // hash function
    int hash(char) const;

public:
    // Constructor
    ItemFactory();

    // Destructor
    ~ItemFactory();

    // Returns index of code
    int subscript(char code);

    // Creates a corresponding item based on the data provided
    // Takes a character code
    // Returns a pointer to the created item
    Item *createItem(const char code) const;
};

#endif