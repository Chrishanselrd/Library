#ifndef HISTORY_H
#define HISTORY_H

#include "action.h"
#include "book.h"
#include "patron.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//---------------------------------------------------------------------------
// History: History is a child class of action. It is created in the action
//          factory and it executes the action of displaying the history of
//          a patron

// Implementation and assumptions:
//   -- Be able to create from action factory
//   -- implements its parent class Action
//   -- Be able to go to patron

class History : public Action
{
public:
    // constructor and destructor
    History();
    ~History();

    // set data
    virtual bool setData(ifstream &, ItemFactory &, Library *);

    // Create action
    virtual Action *create();

    // executes display history
    virtual void execute();

private:
    Patron *currentPatron;
    int currentUserId;
};

#endif