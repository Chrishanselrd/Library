#include "history.h"
#include "itemfactory.h"

//----------------------------------------------------------------------------
// History()
// constructor
History::History()
{
    currentPatron = nullptr;
    currentUserId = 0;
}

//----------------------------------------------------------------------------
// ~History()
// destructor
History::~History() {}

//----------------------------------------------------------------------------
// setData()
// sets data for History (for command)
bool History::setData(ifstream &infile, ItemFactory &itemFactory, Library *lib)
{
    // takes in user id
    infile >> currentUserId;

    // checks for a valid id
    if (currentUserId < 0 || currentUserId > 9999)
    {
        return false;
    }

    // retrieve patron
    currentPatron = lib->retrievePatron(currentUserId);

    // checks for a valid patron
    if (currentPatron == nullptr)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
// create()
// creates a new History obj
Action *History::create()
{
    return new History();
}

//----------------------------------------------------------------------------
// execute()
// execute History
void History::execute()
{
    if (currentPatron != nullptr)
    {
        currentPatron->displayHistory();
        cout << endl;
    }
}
