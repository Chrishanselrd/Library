#ifndef DISPLAY_H
#define DISPLAY_H
#include <fstream>
#include <iostream>
#include "action.h"

using namespace std;

//---------------------------------------------------------------------------
// Display: Display is a child class of action. It is created in the action
//           factory and it executes the action of displaying all the books

// Implementation and assumptions:
//   -- Be able to create from action factory
//   -- implements its parent class Action
//   -- Be able to go to library

// forward declaration
class Library;

class Display : public Action
{

public:
    // Constructor and destructor
    Display();
    ~Display();

    // set data
    virtual bool setData(ifstream &, ItemFactory &, Library *);

    // create display
    virtual Action *create();

    // executes display
    virtual void execute();

private:
    Library *currentLibrary;
};
#endif