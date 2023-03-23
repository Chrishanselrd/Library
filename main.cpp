#include "library.h"

using namespace std;

int main()
{
    Library *lib = new Library();

    // Read
    cout << "READING BOOKS" << endl;
    lib->readBooks("data4books.txt");

    cout << "READING USERS" << endl;
    lib->readUsers("data4patrons.txt");

    cout << "READING COMMANDS" << endl;
    lib->readActions("data4commands.txt");

    delete lib;
    return 0;
}