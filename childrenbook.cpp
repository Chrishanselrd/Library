#include "childrenbook.h"

//----------------------------------------------------------------------------
// ChildrenBook()
// constructor
ChildrenBook::ChildrenBook() { available = 5; }

//----------------------------------------------------------------------------
// ~ChildrenBook()
// destructor
ChildrenBook::~ChildrenBook() {}

//----------------------------------------------------------------------------
// print()
// prints book info
void ChildrenBook::print() const
{
    const ChildrenBook &childrenbook = static_cast<const ChildrenBook &>(*this);
    cout << left << setw(10) << childrenbook.available
         << setw(35) << childrenbook.author
         << setw(35) << childrenbook.title
         << setw(10) << childrenbook.year << endl;
}

//----------------------------------------------------------------------------
// create()
// creates a new Children Book
Item *ChildrenBook::create() const
{
    return new ChildrenBook();
}

//----------------------------------------------------------------------------
// setData()
// sets data for children book (for reading books)
void ChildrenBook::setData(ifstream &inputFile)
{
    inputFile.get();                 // get the space
    getline(inputFile, author, ','); // Read the author name
    inputFile.get();                 // get the space
    getline(inputFile, title, ',');  // Read the title
    inputFile >> year;               // Read the year
}

//----------------------------------------------------------------------------
// setDataCommand()
// sets data for children book (for reading command)
void ChildrenBook::setDataCommand(ifstream &inputFile)
{
    inputFile.get();                 // get the space
    getline(inputFile, title, ',');  // Read the author name
    inputFile.get();                 // get the space
    getline(inputFile, author, ','); // Read the title
}

//----------------------------------------------------------------------------
// countAvailable()
// Returns the number of available copies of the book
int ChildrenBook::countAvailable() const
{
    return available;
}

//----------------------------------------------------------------------------
// countCheckedOut()
// Returns the number of checked out copies of the book
int ChildrenBook::countCheckedOut() const
{
    return checkedOut;
}

//----------------------------------------------------------------------------
// checkOut()
// Checks out a copy of the book
void ChildrenBook::checkOut()
{
    // checks if book is still available
    if (available > 0)
    {
        available--;
        checkedOut++;
        print();
    }
    // if book is not available
    else
    {
        cout << "Sorry, there are no more available copies of " << title << "." << endl;
    }
}

//----------------------------------------------------------------------------
// returnBook()
// Returns a copy of the book
void ChildrenBook::returnBook()
{
    // checks if there is a book checked out
    if (checkedOut > 0)
    {
        available++;
        checkedOut--;
    }
    else
    {
        cout << "Error: Attempted to return a book that wasn't checked out." << endl;
    }
}

//----------------------------------------------------------------------------
// operator<
bool ChildrenBook::operator<(const Item &other) const
{
    // casts the object
    const ChildrenBook &rhs = static_cast<const ChildrenBook &>(other);

    // Compare title then author
    // if title is equal
    if (title == rhs.title)
    {
        // compare the author
        return author < rhs.author;
    }
    // if not equal
    else
    {
        // return title comparison
        return title < rhs.title;
    }
}

//----------------------------------------------------------------------------
// operator>
bool ChildrenBook::operator>(const Item &other) const
{
    const ChildrenBook &rhs = static_cast<const ChildrenBook &>(other);
    if (title == rhs.title)
    {
        return author > rhs.author;
    }
    else
    {
        return title > rhs.title;
    }
}

//----------------------------------------------------------------------------
// operator<=
bool ChildrenBook::operator<=(const Item &other) const
{
    const ChildrenBook &rhs = static_cast<const ChildrenBook &>(other);
    if (title == rhs.title)
    {
        return author <= rhs.author;
    }
    else
    {
        return title <= rhs.title;
    }
}

//----------------------------------------------------------------------------
// operator>=
bool ChildrenBook::operator>=(const Item &other) const
{
    const ChildrenBook &rhs = static_cast<const ChildrenBook &>(other);
    if (title == rhs.title)
    {
        return author >= rhs.author;
    }
    else
    {
        return title >= rhs.title;
    }
}

//----------------------------------------------------------------------------
// operator==
bool ChildrenBook::operator==(const Item &other) const
{
    const ChildrenBook &rhs = static_cast<const ChildrenBook &>(other);
    return title == rhs.title && author == rhs.author;
}

//----------------------------------------------------------------------------
// operator!=
bool ChildrenBook::operator!=(const Item &other) const
{
    const ChildrenBook &rhs = static_cast<const ChildrenBook &>(other);
    return !(*this == rhs);
}
