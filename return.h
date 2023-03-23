#ifndef RETURN_H
#define RETURN_H
#include <fstream>
#include <iostream>
#include "action.h"

using namespace std;

//---------------------------------------------------------------------------
// Return: Return is a child class of action. It is created in the action
//         factory and it executes the action of return a book
//

// Implementation and assumptions:
//   -- Be able to create from action factory
//   -- implements its parent class Action
//   -- Be able to go to Patron, Item, Library, and itemfactory

// forward declaration
class Item;

class Return : public Action
{

public:
    // constructor and destructor
    Return();
    ~Return();

    // set data
    virtual bool setData(ifstream &, ItemFactory &, Library *);

    // create action
    virtual Action *create();

    // execute return
    virtual void execute();

private:
    Item *currentItem;
    Item *targetItem;
    Patron *currentPatron;
    int currentUserId;
};
#endif