#include "doublelinklist.h"
#include <iostream>
#include"cctype"

using namespace std;

template<class ItemType>
doublelinklist<ItemType>::doublelinklist()
{
    front= NULL;
    rear = NULL;

}



//Task-3
template<class ItemType>
bool doublelinklist<ItemType>::isEmpty()
{
   return front==NULL && rear==NULL;

}

//Task-2
template<class ItemType>
bool doublelinklist<ItemType>::isFull()
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;

    }
    catch(bad_alloc& exception)
    {
        return true;

    }
}

//Task-1
template<class ItemType>
void doublelinklist<ItemType>::MakeEmpty()
{
        NodeType* temp;
        while(front!=NULL)
        {
            temp=front;
            front = front->next;
             delete temp;
            front->prev = NULL;


        }
        rear= NULL;

}

//Task-6
template<class ItemType>
void doublelinklist<ItemType>::InsertItemAtFront(ItemType item)
{
    NodeType* newNode;
    newNode= new NodeType;
    newNode->info = item;
    newNode->next = NULL;
    newNode->prev= NULL;


    if(front == NULL)
    {
        front= newNode;
        return;
    }
    else{
    front ->prev = newNode;
    newNode->next=front;
    front= newNode;
    }

}
//Task-7
template<class ItemType>
void doublelinklist<ItemType>::InsertItemAtRear(ItemType item)
{
     NodeType *newNode,*nodePtr;
    newNode = new NodeType;
    newNode->info=item;
    newNode->next = NULL;
    newNode->prev = NULL;
    nodePtr = front;
    if(front==NULL)
        front = newNode;
    else
    {
        while(nodePtr->next!=NULL)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
        nodePtr->next->prev = nodePtr;
    }

}

//Task-12
template<class ItemType>
void doublelinklist<ItemType>::Print()
{
    NodeType* temp = front;

    while(temp!=NULL)
    {
        cout<<temp->info<<endl;
        temp= temp->next;

    }

}



//Task-13
template<class ItemType>
void doublelinklist<ItemType>::PrintReverse()
{
    NodeType *p1, *p2;
    p1= front;
    p2= p1->next;
    p1->next=NULL;
    p2->prev= p2;
    while(p2!= NULL)
    {
        p2->prev=p2->next;
        p2->next= p1;
        p1= p2;
        p2 =p2->prev;
    }
    front=p1;
    cout<<"List is reversed"<<endl;
    while(p1!=NULL)
    {
        cout<<p1->info<<endl;
        p1= p1->next;

    }

}

//Task-9
template<class ItemType>
void doublelinklist<ItemType>::DeleteItem(int position)
{
    NodeType* current = front;
    NodeType* previous = front;

    while(current)
    {
        if(current->info == position)
        {
            if(front== rear)
            {
                front= NULL;
                rear = NULL;
                delete current;
                cout << "Deleting : "<<position<<endl;
                return;
            }
            else if(current==front)
            {
                front= current->next;
                front->prev =NULL;
                delete current;
                cout<<"Deleting : "<<position<<endl;
                return;
            }
            else if (current==rear)
            {
                previous->next= NULL;
                rear= previous;
                delete current;
                cout<<"Deleting : "<<position<<endl;
                return;

            }
            else
            {
                previous->next=current->next;
                current->next->prev=previous;
                delete current;
                cout<<"Deleting : "<<position<<endl;
                return;

            }
        }
        previous= current;
        current = current->next;
    }

}

//Task-10
template<class ItemType>
void doublelinklist<ItemType>::DeleteItemAtFront()
{
    front= front->next;
    front->prev = NULL;
    cout<<"Delete the first Node "<<endl;
}

//Task-11
template<class ItemType>
void doublelinklist<ItemType>::DeleteAllItem()
{
    front=NULL;
    rear=NULL;



}

//Task-4
template<class ItemType>
int doublelinklist<ItemType>::lengthIs()
{
    int count = 0;
    NodeType* node;

    node = front;
    if (front==NULL)
        cout<<"the list is empty "<<endl;
    else
    {
        while(node!= NULL)
        {
            node= node->next;
            count++;
        }

    }
    cout<<"The Number of items in the list: "<<count<<endl;
}

//Task-5
template<class ItemType>
void doublelinklist<ItemType>::RetrieveItem(ItemType& item, bool& found)
{


    NodeType* location ;
    location= front;
  bool moreToSearch = (location != NULL);
  found = false;
  while (moreToSearch && !found)
  {
    if (item == location->info)
      found = true;
    else if (item < location->info)
    {
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else
      moreToSearch = false;
  }

}









