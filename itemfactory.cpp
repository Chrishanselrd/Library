#include "itemfactory.h"
#include "item.h"
#include "childrenbook.h"
#include "periodical.h"
#include "fictionbook.h"

//----------------------------------------------------------------------------
// ItemFactory()
// Factory constructor
ItemFactory::ItemFactory()
{
    // Initialize all pointers to nullptr
    for (int i = 0; i < 26; i++)
    {
        itemFactory[i] = nullptr;
    }

    // Initialize object to index
    itemFactory[2] = new ChildrenBook(); // C = 2
    itemFactory[5] = new FictionBook();  // F = 5
    itemFactory[15] = new Periodical();  // P = 15
}

//----------------------------------------------------------------------------
// ~ItemFactory()
// Factory destructor
ItemFactory::~ItemFactory()
{
    // loops through the array
    for (int i = 0; i < 26; i++)
    {
        // deletes pointer if not null
        if (itemFactory[i] != nullptr)
        {
            delete itemFactory[i];
            itemFactory[i] = nullptr;
        }
    }
}

//----------------------------------------------------------------------------
// hash()
// Returns an index based on the code
int ItemFactory::hash(char code) const
{
    if (code == 'C' || code == 'F' || code == 'P')
    {
        return code - 'A';
    }
    else
    {
        cout << "ERROR: " << code << " is not a valid Library Item type" << endl;
        return 0;
    }
    return 0;
}

//----------------------------------------------------------------------------
// subscript()
int ItemFactory::subscript(char code)
{
    return hash(code);
}

//----------------------------------------------------------------------------
// createItem()
// creates an item object based on the specific code
Item *ItemFactory::createItem(const char code) const
{
    // Get the index of the item
    int subscript = hash(code);

    // Error check code
    if (code < 'A' || code > 'Z')
    {
        return nullptr;
    }

    // Error check if item available
    if (itemFactory[subscript] == nullptr)
    {
        return nullptr;
    }

    // If item is available,
    // create a new item and return it's pointer
    else
    {
        Item *item = itemFactory[subscript]->create();
        return item;
    }
}