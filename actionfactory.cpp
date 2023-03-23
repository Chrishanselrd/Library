#include "actionfactory.h"
#include "action.h"
#include "history.h"
#include "checkout.h"
#include "return.h"
#include "display.h"

//----------------------------------------------------------------------------
// ActionFactory()
// Factory constructor
ActionFactory::ActionFactory()
{
    // Initialize all pointers to nullptr
    for (int i = 0; i < 26; i++)
    {
        actFactory[i] = nullptr;
    }

    // Initialize object to index
    actFactory[2] = new CheckOut(); // C = 2
    actFactory[3] = new Display();  // D = 3
    actFactory[7] = new History();  // H = 7
    actFactory[17] = new Return();  // R = 17
}

//----------------------------------------------------------------------------
// ~ActionFactory()
// Factory destructor
ActionFactory::~ActionFactory()
{
    // loops through the array
    for (int i = 0; i < 26; i++)
    {
        // deletes pointer if not null
        if (actFactory[i] != nullptr)
        {
            delete actFactory[i];
            actFactory[i] = nullptr;
        }
    }
}

//----------------------------------------------------------------------------
// hash()
// Returns an index based on the code
int ActionFactory::hash(char code) const
{
    // checks for a valid code
    if (code == 'D' || code == 'H' || code == 'C' || code == 'R')
    {
        return code - 'A';
    }
    else
    {
        cout << "ERROR: " << code << " is not a valid Library Action type" << endl;
        return 0;
    }
    return 0;
}

//----------------------------------------------------------------------------
// subscript()
int ActionFactory::subscript(char code)
{
    return hash(code);
}

//----------------------------------------------------------------------------
// createAction()
// creates an action object based on the specific code
Action *ActionFactory::createAction(const char code) const
{
    // Get the index of the item
    int subscript = hash(code);

    // Error check code
    if (code < 'A' || code > 'Z')
    {
        return nullptr;
    }

    // Error check if item available
    if (actFactory[subscript] == nullptr)
    {
        return nullptr;
    }

    // If item is available,
    // create a new item and return it's pointer
    else
    {
        Action *item = actFactory[subscript]->create();
        return item;
    }
}
