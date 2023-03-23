#include "bintree.h"
#include <string>

//----------------------------------------------------------------
// BinTree()
// Constructor
BinTree::BinTree() : root(nullptr) {}

//----------------------------------------------------------------
// ~BinTree()
// Destructor
BinTree::~BinTree()
{
   makeEmpty();
}

//----------------------------------------------------------------
// display()
// displays the data inside the binary tree
void BinTree::display() const
{
   displayHelper(root);
}

void BinTree::displayHelper(Node *n) const
{
   if (n == nullptr)
   {
      return;
   }
   // display left node
   displayHelper(n->left);

   // display node
   n->data->print();

   // display right node
   displayHelper(n->right);
}

//----------------------------------------------------------------
// makeEmpty()
// deletes the elements of the tree
// and frees the memory associated with them.
void BinTree::makeEmpty()
{
   makeEmptyHelper(root);
}

void BinTree::makeEmptyHelper(Node *&current)
{
   if (current != nullptr)
   {
      // empty left
      makeEmptyHelper(current->left);

      // empty right
      makeEmptyHelper(current->right);

      // delete data on node
      delete current->data;
      current->data = nullptr;

      // delete node
      delete current;
      current = nullptr;
   }
}

//----------------------------------------------------------------
// isEmpty()
// checks whether the tree is empty
bool BinTree::isEmpty() const
{
   return (root == nullptr);
}

//----------------------------------------------------------------
// insert()
// inserts an Item pointer inside the BST
bool BinTree::insert(Item *item)
{
   return insertHelper(root, item);
}

bool BinTree::insertHelper(Node *&current, Item *newItem)
{
   // checks if BST is empty
   if (current == nullptr)
   {
      // creates a new node and initialize left and right
      current = new Node();
      current->data = newItem;
      current->left = current->right = nullptr;
      return true;
   }
   // if item already exist
   else if (*newItem == *current->data)
   {
      return false;
   }
   // if item smaller than current (go left)
   else if (*newItem < *current->data)
   {
      return insertHelper(current->left, newItem);
   }
   // if item bigger than current (go right)
   else
   {
      return insertHelper(current->right, newItem);
   }
}

//----------------------------------------------------------------
// retrieve()
// retrieves an Item pointer from the BST
Item *BinTree::retrieve(Item *target) const
{
   return retrieveHelper(root, target);
}

Item *BinTree::retrieveHelper(const Node *current, Item *target) const
{
   // if current is empty
   if (current == nullptr)
   {
      return nullptr;
   }
   // if found
   else if (*current->data == *target)
   {
      return current->data;
   }
   // if target is smaller than current
   else if (*current->data > *target)
   {
      return retrieveHelper(current->left, target);
   }
   // if target is bigger than current
   else if (*current->data < *target)
   {
      return retrieveHelper(current->right, target);
   }

   return nullptr;
}