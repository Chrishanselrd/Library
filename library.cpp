#include "library.h"

//----------------------------------------------------------------------------
// readBooks()
// create and stores book from a .txt file
void Library::readBooks(const string &filename)
{
    // Opens file
    ifstream infile(filename);
    if (!infile)
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    // infinite loop
    while (true)
    {
        char code;
        // takes in the code or book type
        infile >> code;

        // checks for end of file
        if (infile.eof())
        {
            break;
        }

        // creates a new item based on its type (fiction book, children book, periodical)
        Item *current = itmFactory.createItem(code);

        // Checks if it is a valid item
        if (current == nullptr)
        {
            // gets rid of the whole line
            string dummy;
            getline(infile, dummy);
        }
        else
        {
            // sets data to the item
            current->setData(infile);

            // inserts the item to book container
            bool success = bookContainer[itmFactory.subscript(code)].insert(current);
            if (!success)
            {
                delete current;
                current = nullptr;
                break;
            }
        }
    }
}

//----------------------------------------------------------------------------
// readUsers()
// create and stores patron from a .txt file
void Library::readUsers(const string &filename)
{
    // Opens file
    ifstream infile(filename);
    if (!infile)
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    // infinite loop
    while (true)
    {
        int id;
        string lastName;
        string firstName;

        // takes in id, last name, and first name
        infile >> id >> lastName >> firstName;

        // checks for end of file
        if (infile.eof())
        {
            break;
        }

        // verify a valid id
        if (id < 0 || id > 9999)
        {
            cout << "Error: Invalid ID" << endl;
            continue;
        }

        // creates a new patron
        Patron *current = new Patron(id, lastName, firstName);

        // checks for a valid patron
        if (current == nullptr)
        {
            continue;
        }
        else
        {
            // insert new patron to container
            userContainer.insert(current);
        }
    }
}

//----------------------------------------------------------------------------
// readActions()
// create and executes Actions from a .txt file
void Library::readActions(const string &filename)
{
    // Opens file
    ifstream infile(filename);
    if (!infile)
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    // infinite loop
    while (true)
    {
        char action;

        // takes in the action (D, H, C, R)
        infile >> action;

        // checks for end of file
        if (infile.eof())
        {
            break;
        }

        // creates a new action based on the action code (Display, History, CheckOut, Return)
        Action *current = actFactory.createAction(action);

        // Checks if it is a valid item
        if (current == nullptr)
        {
            // get rids of the following text
            string dummy;
            getline(infile, dummy);
        }
        else
        {
            // sets data to the action
            if (current->setData(infile, itmFactory, this))
            {
                // execute the action and then deletes it
                current->execute();
                delete current;
                current = nullptr;
            }
            // if fail to setdata
            else
            {
                // get remaining text and delete the action object
                string dummy;
                getline(infile, dummy);
                delete current;
            }
        }
    }
}

//----------------------------------------------------------------------------
// displayBooks()
// display all of the books in the library
void Library::displayBooks() const
{
    // loops through the book container
    for (int i = 0; i < 26; i++)
    {
        // checks if the container is empty
        if (!bookContainer[i].isEmpty())
        {
            if (i == 2)
            {
                cout << "Children Book" << endl;
                cout << left << setw(10) << "AVAIL" << setw(35) << "AUTHOR" << setw(35) << "TITLE" << setw(10) << "YEAR" << endl;
                bookContainer[i].display();
                cout << endl;
            }
            else if (i == 5)
            {
                cout << "Fiction Book" << endl;
                cout << left << setw(10) << "AVAIL" << setw(35) << "AUTHOR" << setw(35) << "TITLE" << setw(10) << "YEAR" << endl;
                bookContainer[i].display();
                cout << endl;
            }
            else if (i == 15)
            {
                cout << "Periodical" << endl;
                cout << left << setw(10) << "AVAIL" << setw(10) << "MONTH" << setw(10) << "YEAR" << setw(35) << "TITLE" << endl;
                bookContainer[i].display();
                cout << endl;
            }
            else
            {
                cout << "Add more Types" << endl;
            }
        }
    }
    cout << endl;
}

//----------------------------------------------------------------------------
// displayUsers()
// display all of the patrons in the library
void Library::displayUsers() const
{
    userContainer.displayPatrons();
}

//----------------------------------------------------------------------------
// retrievePatron()
// retrieve a Patron pointer from the container
Patron *Library::retrievePatron(int id) const
{
    return userContainer.retrieve(id);
}

//----------------------------------------------------------------------------
// retrieveBook()
// retrieve a Item pointer from the container
Item *Library::retrieveBook(char type, Item *target) const
{
    return bookContainer[type - 'A'].retrieve(target);
}