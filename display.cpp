#include "display.h"
#include "itemfactory.h"

//----------------------------------------------------------------------------
// Display()
// constructor
Display::Display() {}

//----------------------------------------------------------------------------
// ~Display()
// destructor
Display::~Display() {}

//----------------------------------------------------------------------------
// setData()
// sets data for Display (for command)
bool Display::setData(ifstream &infile, ItemFactory &itemFactory, Library *lib)
{
    // sets library
    if (lib != nullptr)
    {
        currentLibrary = lib;
        return true;
    }
    return false;
}

//----------------------------------------------------------------------------
// create()
// creates a new Display obj
Action *Display::create()
{
    return new Display();
}

//----------------------------------------------------------------------------
// execute()
// execute Display
void Display::execute()
{
    if (currentLibrary != nullptr)
    {
        currentLibrary->displayBooks();
    }
}
