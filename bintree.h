//-----------------------------------------------------------------------------
// The BinTree class is a binary search tree that stores item objects.
// The class provides methods for inserting, removing,
// and retrieving NodeData objects from the tree.
// The class also provides methods for checking if the tree is empty,
// displaying the tree
// sideways, and getting the sibling and parent of an item object in the tree.
// The class also has a copy constructor, assignment operator,
// and methods for converting
// the tree to an array and vice versa.
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <string>
#include "item.h"

using namespace std;

class BinTree
{

public:
    // constructor
    BinTree();

    // copy constructor
    BinTree(const BinTree &);

    // Destructor
    ~BinTree();

    // Checks whether the tree is empty
    bool isEmpty() const;

    // Makes the tree empty
    void makeEmpty();

    // Inserts item
    bool insert(Item *);

    // Retrieve the node data
    Item *retrieve(Item *) const;

    // Remove a node from the tree
    bool remove(const Item &, Item *&);

    // Displays the tree sideways
    void displaySideways() const;

    // Get the sibling node
    bool getSibling(const Item &, Item &) const;

    // Get the parent node
    bool getParent(const Item &, Item &) const;

    // Convert BST to Array
    void bstreeToArray(Item *[]);

    // Convert Array to BST
    void arrayToBSTree(Item *[]);

    // Display
    void display() const;

private:
    struct Node
    {
        Item *data;  // pointer to item object
        Node *left;  // left subtree pointer
        Node *right; // right subtree pointer
    };
    Node *root; // root of the tree

    // Helper functions
    void displayHelper(Node *) const;
    void inorderHelper(Node *) const;
    bool insertHelper(Node *&current, Item *itemInserting);
    void sidewaysHelper(Node *, int) const;
    void copyHelper(Node *current, Node *otherCurrent);
    void makeEmptyHelper(Node *&);
    bool isEqual(Node *, Node *) const;
    Item *retrieveHelper(const Node *current, Item *target) const;
};
#endif