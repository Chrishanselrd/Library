#ifndef ACTIONFACTORY_H
#define ACTIONFACTORY_H

#include <string>
#include <iostream>
#include <fstream>

//---------------------------------------------------------------------------
// Action Factory:  Action Factory is a factory that creates action objects

// Implementation and assumptions:
//   -- Be able to create the Action class
//   -- has an array that corresponds a code to a certain index
//   -- has a hash function

class Action;

using namespace std;

class ActionFactory
{
private:
    Action *actFactory[26];
    int hash(char) const; // hash function
public:
    // Constructor and Destructor
    ActionFactory();
    ~ActionFactory();

    int subscript(char);

    // Creates a corresponding item based on the information provided
    Action *createAction(const char code) const;
};

#endif