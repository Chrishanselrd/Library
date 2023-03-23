#include "checkout.h"
#include "itemfactory.h"

//----------------------------------------------------------------------------
// CheckOut()
// constructor
CheckOut::CheckOut()
{
    currentItem = nullptr;
    currentPatron = nullptr;
    targetItem = nullptr;
    currentUserId = 0;
}

//----------------------------------------------------------------------------
// ~CheckOut()
// destructor
CheckOut::~CheckOut()
{
    if (targetItem != nullptr)
    {
        delete targetItem;
        targetItem = nullptr;
    }
}

//----------------------------------------------------------------------------
// setData()
// sets data for CheckOut (for command)
bool CheckOut::setData(ifstream &infile, ItemFactory &itemFactory, Library *lib)
{
    // takes in user id
    infile >> currentUserId;

    // checks for a valid id
    if (currentUserId < 0 || currentUserId > 9999)
    {
        return false;
    }
    else
    {
        // retrieve patron
        currentPatron = lib->retrievePatron(currentUserId);
        // checks for a valid patron
        if (currentPatron == nullptr)
        {
            return false;
        }
    }

    char type, format;
    // takes in type and format
    infile >> type >> format;

    // checks for a valid format
    if (format != 'H')
    {
        cout << "Error" << format << "is an unknown format" << endl;
        return false;
    }

    // creates an item for target
    targetItem = itemFactory.createItem(type);

    // checks for a valid target
    if (targetItem == nullptr)
    {
        return false;
    }

    // sets data for target
    targetItem->setDataCommand(infile);

    // retrieve book
    currentItem = lib->retrieveBook(type, targetItem);
    if (currentItem == nullptr)
    {
        return false;
    }
    return true;
}

//----------------------------------------------------------------------------
// create()
// creates a new CheckOut obj
Action *CheckOut::create()
{
    return new CheckOut();
}

//----------------------------------------------------------------------------
// execute()
// execute CheckOut
void CheckOut::execute()
{
    if (currentItem != nullptr && currentPatron != nullptr)
    {
        currentPatron->checkOut(currentItem);
        currentItem->checkOut();
    }
}
