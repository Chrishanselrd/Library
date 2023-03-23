#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <iostream>
#include <fstream>
#include "patron.h"
#include "library.h"

//---------------------------------------------------------------------------
// Action:  Action is an object that implements an action for the library.
//          It is the parent class of 4 types of actions including display,
//          history, checkout, and return.
//
// Implementation and assumptions:
//   -- Be able to create the Action class
//   -- Be able to execute the Action
//   -- Be able to read data from .txt file into the action
//   -- has access to item factory to create item

using namespace std;

// Forward declaration
class ItemFactory;
class Library;

class Action
{
public:
    // Constructor and Destructor
    Action(){};
    virtual ~Action(){};

    // Pure virtual create
    virtual Action *create() = 0;

    // Pure virtual execute
    virtual void execute() = 0;

    // Pure virtual set data
    virtual bool setData(ifstream &, ItemFactory &, Library *) = 0;
};
#endif
