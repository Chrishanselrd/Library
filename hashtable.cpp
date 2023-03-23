#include "hashtable.h"

//----------------------------------------------------------------
// HashTable()
// constructor
HashTable::HashTable()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        patronArray[i] = nullptr;
    }
}

//----------------------------------------------------------------
// ~HashTable()
// destructor
HashTable::~HashTable()
{
    makeEmpty();
}

//----------------------------------------------------------------
// makeEmpty()
// empties the hash table
void HashTable::makeEmpty()
{
    // loops through the array
    for (int i = 0; i < MAX_SIZE; i++)
    {
        // deletes pointer if not null
        if (patronArray[i] != nullptr)
        {
            delete patronArray[i];
            patronArray[i] = nullptr;
        }
    }
}

//----------------------------------------------------------------
// isEmpty()
// checks if the table is empty
bool HashTable::isEmpty() const
{
    // loop through the array
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (patronArray[i] != nullptr)
        {
            return false;
        }
    }
    return true;
}

//----------------------------------------------------------------------------
// hash()
// Returns an index based on the code id
int HashTable::hash(int id) const
{
    return id % MAX_SIZE;
}

//----------------------------------------------------------------------------
// insert()
// inserts a new Patron object
bool HashTable::insert(Patron *user)
{
    // gets the index
    int index = hash(user->getId());

    // checks if the spot is available and valid index
    if (index < MAX_SIZE && index > 0 && patronArray[index] == nullptr)
    {
        patronArray[index] = user;
    }
    else
    {
        cout << index << endl;
        cout << "A user with the same id is already in the container / invalid index" << endl;
        return false;
    }
    return true;
}

//----------------------------------------------------------------------------
// remove()
// remove an existing Patron object
bool HashTable::remove(int id)
{
    // gets the index
    int index = hash(id);

    // if there is no existing patron
    if (patronArray[index] == nullptr)
    {
        cout << "Error: Unregistered Patron" << endl;
        return false;
    }
    else
    {
        delete patronArray[index];
        patronArray[index] = nullptr;
        return true;
    }
}

//----------------------------------------------------------------------------
// retrieve()
// retrieves and returns the patron pointer of a specific id
Patron *HashTable::retrieve(int id) const
{
    int index = hash(id);
    return patronArray[index];
}

//----------------------------------------------------------------------------
// displayPatrons()
// display all patrons in the table
void HashTable::displayPatrons() const
{
    cout << left << setw(10) << "Id" << setw(25) << "Name" << endl;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        // checks for a patron
        if (patronArray[i] != nullptr)
        {
            patronArray[i]->print();
        }
    }
}