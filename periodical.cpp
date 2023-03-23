#include "periodical.h"

//----------------------------------------------------------------------------
// Periodical()
// constructor
Periodical::Periodical() { available = 1; }

//----------------------------------------------------------------------------
// ~Periodical()
// destructor
Periodical::~Periodical() {}

//----------------------------------------------------------------------------
// print()
// prints book info
void Periodical::print() const
{
    const Periodical &periodical = static_cast<const Periodical &>(*this);
    cout << left << setw(10) << periodical.available
         << setw(10) << periodical.month
         << setw(10) << periodical.year
         << setw(35) << periodical.title
         << endl;
}

//----------------------------------------------------------------------------
// create()
// creates a new periodical
Item *Periodical::create() const
{
    return new Periodical();
}

//----------------------------------------------------------------------------
// setData()
// sets data for periodical (for reading books)
void Periodical::setData(ifstream &infile)
{
    infile.get();                // get the space
    getline(infile, title, ','); // Read the title
    infile >> month;             // Read the month
    infile >> year;              // Read the year
}

//----------------------------------------------------------------------------
// setDataComman()
// sets data for periodical (for reading command)
void Periodical::setDataCommand(ifstream &infile)
{
    infile.get();                // get the space
    infile >> year;              // Read the year
    infile >> month;             // Read the month
    infile.get();                // get the space
    getline(infile, title, ','); // Read the title
}

//----------------------------------------------------------------------------
// countAvailable()
// Returns the number of available copies of the book
int Periodical::countAvailable() const
{
    return available;
}

//----------------------------------------------------------------------------
// countCheckedOut()
// Returns the number of checked out copies of the book
int Periodical::countCheckedOut() const
{
    return checkedOut;
}

//----------------------------------------------------------------------------
// checkedOut()
// Checks out a copy of the book
void Periodical::checkOut()
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
void Periodical::returnBook()
{
    if (checkedOut > 0)
    {
        available++;
        checkedOut--;
    }
    else
    {
        cout << "Error: Attempted to return a periodical that wasn't checked out." << endl;
    }
}

//----------------------------------------------------------------------------
// operator<
bool Periodical::operator<(const Item &other) const
{
    // casts the object
    const Periodical &rhs = static_cast<const Periodical &>(other);

    // Compare date then title
    // if year is equal
    if (year == rhs.year)
    {
        // checks month
        // if equal
        if (month == rhs.month)
        {
            // compares title
            return title < rhs.title;
        }
        // if not equal
        else
        {
            // compares month
            return month < rhs.month;
        }
    }
    // if year not equal
    else
    {
        // compares year
        return year < rhs.year;
    }
}

//----------------------------------------------------------------------------
// operator>
bool Periodical::operator>(const Item &other) const
{
    const Periodical &rhs = static_cast<const Periodical &>(other);
    if (year == rhs.year)
    {
        if (month == rhs.month)
        {
            return title > rhs.title;
        }
        else
        {
            return month > rhs.month;
        }
    }
    else
    {
        return year > rhs.year;
    }
}

//----------------------------------------------------------------------------
// operator<=
bool Periodical::operator<=(const Item &other) const
{
    const Periodical &rhs = static_cast<const Periodical &>(other);
    if (year == rhs.year)
    {
        if (month == rhs.month)
        {
            return title <= rhs.title;
        }
        else
        {
            return month <= rhs.month;
        }
    }
    else
    {
        return year <= rhs.year;
    }
}

//----------------------------------------------------------------------------
// operator>=
bool Periodical::operator>=(const Item &other) const
{
    const Periodical &rhs = static_cast<const Periodical &>(other);
    if (year == rhs.year)
    {
        if (month == rhs.month)
        {
            return title >= rhs.title;
        }
        else
        {
            return month >= rhs.month;
        }
    }
    else
    {
        return year >= rhs.year;
    }
}

//----------------------------------------------------------------------------
// operator==
bool Periodical::operator==(const Item &other) const
{
    const Periodical &rhs = static_cast<const Periodical &>(other);
    return year == rhs.year && month == rhs.month && title == rhs.title;
}

//----------------------------------------------------------------------------
// operator!=
bool Periodical::operator!=(const Item &other) const
{
    const Periodical &rhs = static_cast<const Periodical &>(other);
    return !(*this == rhs);
}
