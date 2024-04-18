/*
Name: Vladislav Korneev and Ryan McGee
Class: CPSC 122, Section 1
Date Submitted: March 22, 2024
Assignment: Writing a Linked List Class
Description: The Functions of the Linked List Class, allowing to use the linked list and delete/add from/to it
*/

#include <iostream>
using namespace std;

#include "3-ListT.h"

/*
pre: None. This is the constructor function, invoked like this from the
client program:
List lst;
or
List* lst1 = new List;
post: an instance of List exists
*/
ListT::ListT()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

/*

   pre: An instance of ListT exists.  This is the destructor function, automatically
        invoked in the case of a static declaration, explicitly invoked, using the delete
        key word, in the case of a dynamic declaration.
   post: All dynamically declared memory, i.e., the memory for all nodes, has been
        returned to the heap.
*/
ListT::~ListT()
{
    while(length > 0)
    {
        DeleteItemH();
    }
}

//Head-related functions
/*
pre: an instance of List exists
post: node containing itemIn is at the head of the list
*/
void ListT::PutItemH(const itemType itemIn)
{
    node* tmp = new node;
    tmp->item = itemIn;
    tmp->next = head;

    if(length == 0)
    {
        tail = tmp;
    }

    head = tmp;


    length++;
}

/*
pre: an instance of List exists and is not empty
post: Returns the contents pointed to by the head of the list
*/
itemType ListT::GetItemH() const
{
    node* cur = head;
    return cur->item;
}

/*
pre: an instance of List exists and is not empty
post: Returns the contents pointed to by the tail of the list
*/
itemType ListT::GetItemT() const
{
    node* cur = tail;
    return cur->item;
}

/*
pre: an instance of list exists and is not empty
post: Node pointed to by head is deleted
*/
void ListT::DeleteItemH()
{
    node* tmp = head;
    head = head->next;
    delete tmp;
    tmp = NULL;
    length--;
}

/*
pre: an instance of list exists and is not empty
post: Node pointed to by head is deleted
*/
void ListT::DeleteItemT()
{
    node* tmp = tail;
    node* prev = head;
    for (int i = 1; i < length - 1; i++)
    {
        prev = prev->next;
    }
    prev->next = NULL;
    tail = prev;

    delete tmp;
    tmp = NULL;
    prev = NULL;
    length--;
}

//General operations on List,  starting with the easiest
/*
pre: an instance of List exists
post: returns true if list is empty, false otherwise
*/
bool ListT::IsEmpty() const
{
    if (length == 0)
        return true;
    return false;
}

/*
pre: an instance of List exists
post: returns length of the list
*/
int ListT::GetLength() const
{
    return length;
}

/*
pre: an instance of list exists and is not empty
post: contents of list nodes are displayed on subsequent lines, head to tail.
*/
void ListT::Print() const
{
    node* cur = head;
    while(cur != NULL)
    {
        cout << cur->item << endl;
        cur = cur->next;
    }
}

/*
pre: an instance of List exists and is not empty
post: returns the number of nodes in the list that stores target
*/
int ListT::FindItem(const itemType target) const
{
    node* cur = head;
    int count = 0;

    while(cur != NULL)
    {
        if(cur->item == target)
        {
            count ++;
        }

        cur = cur->next;
    }

    return count;
}

/*
pre:  an instance of List exists and is not empty
post: deletes all nodes that store target.  Returns
      the number of nodes deleted
*/
int ListT::DeleteItem(const itemType target)
{
    node* tmp;
    int count = 0;

    while (head->item == target)
    {
        DeleteItemH();
        count++;
    }

    while (tail->item == target)
    {
        DeleteItemT();
        count++;
    }

    node* cur = head;
    while(cur->next != NULL)
    {
        if(cur->next->item == target)
        {
            tmp = cur->next;
            cur->next = cur->next->next;
            delete(tmp);
            count++;
        }
        else
            cur = cur->next;
    }

    return count;
}

/*
   pre: an instance of listT exists
   post: node containing itemIn is at the tail of the list
*/
void ListT::PutItemT(itemType item)
{
    node* tmp = new node;
    tmp->item = item;

    if(length == 0)
    {
        head = tmp;
        tail = tmp;
    }else
    {
        tail->next = tmp;
        tail = tmp;
    }

    length++;
}