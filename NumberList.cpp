// Implementation file for the NumberList class
#include <iostream>  // For cout
#include "NumberList.h"
using namespace std;

//**************************************************
// appendNode appends a node containing the        *
// value pased into num, to the end of the list.   *
//**************************************************

void NumberList::appendNode(double num)
{
   ListNode *newNode;  // To point to a new node
   ListNode *nodePtr;  // To move through the list

   // Allocate a new node and store num there.
   newNode = new ListNode;
   newNode->value = num;
   newNode->next = nullptr;

   // If there are no nodes in the list
   // make newNode the first node.
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end.
   {
      // Initialize nodePtr to head of list.
      nodePtr = head;

      // Find the last node in the list.
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // Insert newNode as the last node.
      nodePtr->next = newNode;
   }
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void NumberList::displayList() const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      cout << "\t" << nodePtr->value << endl;

      // Move to the next node.
      nodePtr = nodePtr->next;
   }
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************

void NumberList::insertNode(double num)
{
   ListNode *newNode;					// A new node
   ListNode *nodePtr;					// To traverse the list
   ListNode *previousNode = nullptr;	// The previous node

   // Allocate a new node and store num there.
   newNode = new ListNode;
   newNode->value = num;
   
   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
      newNode->next = nullptr;
   }
   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to nullptr.
      previousNode = nullptr;

      // Skip all nodes whose value is less than num.
      while (nodePtr != nullptr && nodePtr->value < num)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == nullptr)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise insert after the previous node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void NumberList::deleteNode(double num)
{
    ListNode* nodePtr, * previousNode = nullptr; // Initialize previousNode to nullptr

    // If the list is empty, do nothing
    if (!head)
        return;

    // Determine if the first node is the one to delete
    if (head->value == num)
    {
        nodePtr = head;
        head = head->next;
        delete nodePtr;
    }
    else
    {
        // Initialize nodePtr to head
        nodePtr = head;

        // Traverse the list to find the value
        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr; // Move previousNode
            nodePtr = nodePtr->next;
        }

        // If the node was found, remove it
        if (nodePtr)
        {
            previousNode->next = nodePtr->next; // Use previousNode safely
            delete nodePtr;
        }
    }
}


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

NumberList::~NumberList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}

//**************************************************
// countNodes is a recursive function that returns *
// the number of nodes in the list.                *
//**************************************************

int NumberList::countNodes(ListNode *nodePtr) const
{
   if (nodePtr != nullptr)
      return 1 + countNodes(nodePtr->next);
   else
      return 0;
}

//****************************************************
// showReverse is a recursive function that displays *
// the values stored in the list in reverse. The     *
// function is called from DisplayBackwards.         *
//****************************************************

void NumberList::showReverse(ListNode *nodePtr) const
{
   if (nodePtr != nullptr)
   {
      showReverse(nodePtr->next);
      cout << nodePtr->value << " ";
   }
}

//****************************************************
// findMax is a recursive function that returns the  *
// largest value stored in the list.                 *
//****************************************************

double NumberList::findMax(ListNode* nodePtr) const
{
    if (!nodePtr)
        return -std::numeric_limits<double>::infinity(); // Base case: empty list
    if (!nodePtr->next)
        return nodePtr->value; // Base case: single node
    double maxOfRest = findMax(nodePtr->next); // Recursive step
    return (nodePtr->value > maxOfRest) ? nodePtr->value : maxOfRest;
}


