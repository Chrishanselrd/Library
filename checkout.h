#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <fstream>
#include <iostream>
#include "action.h"

//---------------------------------------------------------------------------
// Checkout: Checkout is a child class of action. It is created in the action
//           factory and it executes the action of checking out a book

// Implementation and assumptions:
//   -- Be able to create from action factory
//   -- implements its parent class Action
//   -- Be able to go to Patron, Item, Library, and itemfactory

using namespace std;

// Forward declaration
class Patron;
class Item;
class ItemFactory;

class CheckOut : public Action
{

public:
    // Constructor and destructor
    CheckOut();
    ~CheckOut();

    // set data
    virtual bool setData(ifstream &, ItemFactory &, Library *);

    // create checkout
    virtual Action *create();

    // execute checkout
    virtual void execute();

private:
    Item *currentItem;
    Item *targetItem;
    Patron *currentPatron;
    int currentUserId;
};
#endif