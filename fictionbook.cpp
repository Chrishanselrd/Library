#include "fictionbook.h"

//----------------------------------------------------------------------------
// FictionBook()
// constructor
FictionBook::FictionBook() { available = 5; }

//----------------------------------------------------------------------------
// ~FictionBook()
// destructor
FictionBook::~FictionBook() {}

//----------------------------------------------------------------------------
// print()
// prints book info
void FictionBook::print() const
{
    const FictionBook &fictionBook = static_cast<const FictionBook &>(*this);
    cout << setw(10) << fictionBook.available << setw(35) << fictionBook.author
         << setw(35) << fictionBook.title
         << setw(10) << fictionBook.year << endl;
}

//----------------------------------------------------------------------------
// create()
// creates a new Fiction Book
Item *FictionBook::create() const
{
    return new FictionBook();
}

//----------------------------------------------------------------------------
// setData()
// sets data for Fiction Book (for reading books)
void FictionBook::setData(ifstream &infile)
{
    infile.get();                 // get the space
    getline(infile, author, ','); // Read the author name
    infile.get();                 // get the space
    getline(infile, title, ',');  // Read the title
    infile >> year;               // Read the year
}

//----------------------------------------------------------------------------
// setDataCommand()
// sets data for Fiction Book (for reading command)
void FictionBook::setDataCommand(ifstream &infile)
{
    infile.get();                 // get the space
    getline(infile, author, ','); // Read the author name
    infile.get();                 // get the space
    getline(infile, title, ',');  // Read the title
}

//----------------------------------------------------------------------------
// countAvailable()
// Returns the number of available copies of the book
int FictionBook::countAvailable() const
{
    return available;
}

//----------------------------------------------------------------------------
// countCheckedOut()
// Returns the number of checked out copies of the book
int FictionBook::countCheckedOut() const
{
    return checkedOut;
}

//----------------------------------------------------------------------------
// checkedOut()
// Checks out a copy of the book
void FictionBook::checkOut()
{
    if (available > 0)
    {
        available--;
        checkedOut++;
        print();
    }
    else
    {
        cout << "Sorry, there are no more available copies of " << title << "." << endl;
    }
}

//----------------------------------------------------------------------------
// returnBook()
// Returns a copy of the book
void FictionBook::returnBook()
{
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
bool FictionBook::operator<(const Item &other) const
{
    // casts the object
    const FictionBook &rhs = static_cast<const FictionBook &>(other);

    // Compare author then title
    // if author is equal
    if (author == rhs.author)
    {
        // compare the title
        return title < rhs.title;
    }
    // if not equal
    else
    {
        // return author comparison
        return author < rhs.author;
    }
}

//----------------------------------------------------------------------------
// operator>
bool FictionBook::operator>(const Item &other) const
{
    const FictionBook &rhs = static_cast<const FictionBook &>(other);
    if (author == rhs.author)
    {
        return title > rhs.title;
    }
    else
    {
        return author > rhs.author;
    }
}

//----------------------------------------------------------------------------
// operator<=
bool FictionBook::operator<=(const Item &other) const
{
    const FictionBook &rhs = static_cast<const FictionBook &>(other);
    if (author == rhs.author)
    {
        return title <= rhs.title;
    }
    else
    {
        return author <= rhs.author;
    }
}

//----------------------------------------------------------------------------
// operator>=
bool FictionBook::operator>=(const Item &other) const
{
    const FictionBook &rhs = static_cast<const FictionBook &>(other);
    if (author == rhs.author)
    {
        return title >= rhs.title;
    }
    else
    {
        return author >= rhs.author;
    }
}

//----------------------------------------------------------------------------
// operator==
bool FictionBook::operator==(const Item &other) const
{
    const FictionBook &rhs = static_cast<const FictionBook &>(other);
    return author == rhs.author && title == rhs.title;
}

//----------------------------------------------------------------------------
// operator!=
bool FictionBook::operator!=(const Item &other) const
{
    const FictionBook &rhs = static_cast<const FictionBook &>(other);
    return !(*this == rhs);
}
