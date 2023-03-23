/*
 *
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "patron.h"
#include <string>

using namespace std;

//---------------------------------------------------------------------------
// hashTable:  This is a class that stores all of the users into a hash table
//             Has various hash table functions such as insert, search.
//             Hash Table is array of Patron pointers with one index for max
//             num of possibleusers. Deals with duplicates and has no
//             collision

// Implementation and assumptions:
//   -- stores Patron pointers
//   -- every patron should be inserted unique
//   -- has access to patron
//   -- has a hash function for storing
//   -- has a constant variable that could be change according to patrons

// Determines the size of array / number of id user
const int MAX_SIZE = 10000;

class HashTable
{
private:
    Patron *patronArray[MAX_SIZE];
    int hash(int) const; // hash function

public:
    // Constructor
    HashTable();

    // Destructor
    ~HashTable();

    // HashTable functions
    bool insert(Patron *);
    bool remove(int id);
    Patron *retrieve(int id) const;
    void makeEmpty();
    bool isEmpty() const;
    void displayPatrons() const;
};

#endif