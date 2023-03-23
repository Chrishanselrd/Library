#include "patron.h"

//----------------------------------------------------------------------------
// Patron()
// default constructor
Patron::Patron() : id(0), lastName(""), firstName("") {}

//----------------------------------------------------------------------------
// Patron()
// constructor with parameters
Patron::Patron(int id, string lastName, string firstName) : id(id), lastName(lastName), firstName(firstName) {}

//----------------------------------------------------------------------------
// ~Patron()
// destructor
Patron::~Patron()
{
    // Clears the vector
    history.clear();
}

//----------------------------------------------------------------------------
// print()
// prints patron info
void Patron::print() const
{
    cout << left << setw(10) << id
         << setw(25) << firstName << " "
         << lastName << endl;
}

//----------------------------------------------------------------------------
// displayHistory()
// prints patron's history
void Patron::displayHistory() const
{
    // Checks for books that are checked out
    if (history.size() == 0)
    {
        cout << "No books checked out." << endl;
    }
    else
    {
        // Display the user info
        cout << left << setw(6) << id << lastName << ", " << firstName << endl;

        // Display history
        for (auto &pair : history)
        {
            cout << setw(10) << pair.first
                 << "  ";
            pair.second->print();
        }
    }
}

//----------------------------------------------------------------------------
// checkOut()
// Checks out a book
void Patron::checkOut(Item *book)
{
    history.push_back(make_pair("CheckOut", book));
}

//----------------------------------------------------------------------------
// returnBook()
// Returns a book
void Patron::returnBook(Item *book)
{
    // If history is empty
    if (history.size() == 0)
    {
        cout << "No books checked out" << endl;
    }
    else
    {
        // Checks for an existing book
        for (auto &pair : history)
        {
            if (pair.first == "CheckOut" && pair.second == book)
            {
                history.push_back(make_pair("Return", book));
                cout << "Successfully returned book" << endl;
            }
            else
            {
                cout << "This book was not checked out" << endl;
            }
        }
    }
}

//----------------------------------------------------------------------------
// getId()
// returns user id
int Patron::getId()
{
    return id;
}