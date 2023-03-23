#include "return.h"
#include "itemfactory.h"

//----------------------------------------------------------------------------
// Return()
// constructor
Return::Return()
{
    currentItem = nullptr;
    currentPatron = nullptr;
    targetItem = nullptr;
    currentUserId = 0;
}

//----------------------------------------------------------------------------
// ~Return()
// destructor
Return::~Return()
{
    if (targetItem != nullptr)
    {
        delete targetItem;
        targetItem = nullptr;
    }
}

//----------------------------------------------------------------------------
// setData()
// sets data for Return (for command)
bool Return::setData(ifstream &infile, ItemFactory &itemFactory, Library *lib)
{
    // takes in user id
    infile >> currentUserId;

    // checks for valid user id
    if (currentUserId < 0 || currentUserId > 9999)
    {
        return false;
    }
    else
    {
        // get patron pointer
        currentPatron = lib->retrievePatron(currentUserId);
        if (currentPatron == nullptr)
        {
            return false;
        }
    }

    char type, format;
    // takes in the type and format
    infile >> type >> format;

    // checks for invalid type
    if (format != 'H')
    {
        cout << "Error" << format << "is an unknown format" << endl;
        return false;
    }

    // checks for a valid item
    targetItem = itemFactory.createItem(type);
    if (targetItem == nullptr)
    {
        return false;
    }

    // sets the data for target item
    targetItem->setDataCommand(infile);

    // retrieve the book pointer
    currentItem = lib->retrieveBook(type, targetItem);
    if (currentItem == nullptr)
    {
        return false;
    }
    return true;
}

//----------------------------------------------------------------------------
// create()
// creates a new Return obj
Action *Return::create()
{
    return new Return();
}

//----------------------------------------------------------------------------
// execute()
// execute Return
void Return::execute()
{
    // checks for invalid user or item
    if (currentItem != nullptr && currentPatron != nullptr)
    {
        currentPatron->returnBook(currentItem);
        currentItem->returnBook();
    }
}
