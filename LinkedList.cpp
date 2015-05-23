#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
    first_ = 0;
    last_ = 0;
    listLen_ = 0;

}

LinkedList::~LinkedList()
{
    //Deconstructor is declared in header but is not needed.
}

void LinkedList::AddLinkToBack(void* ptr)       //Add node to end of list
{
        Node *newNode = new Node();
        if(newNode == 0)    //Abort is memory allocation fails.
        {
            std::cout << "Memory allocation failed.\n";
            return;
        }
        newNode->data_ = ptr;
        newNode->next_ = 0;     //since node is at the end, next points to 0
        if(listLen_ == 0)       //If no stars are loaded this node will be the first and last node
        {
            first_ = newNode;
            last_ = newNode;
        }
        else        //Append existing list
        {
            last_->next_ = newNode;
            last_ = newNode;
        }
        listLen_++;
}

void* LinkedList::RemoveLinkFromFront()
{
    void *ptr = 0;
    if(first_->data_ != 0)      //If first_->data_ == 0 there are no Nodes to return
    {
        ptr = first_->data_;    //store first star in temp pointer
        Node *nextFirst = first_->next_;     //Store second entry in list
        delete first_;
        first_ = nextFirst;     //Set first_ to second element (new first element) of list
        listLen_--;
    }
    return ptr;     //Return ptr to the removed node.
}

Node* LinkedList::GetFirstNode()
{
    return first_;
}

long LinkedList::GetListLength()
{
    return listLen_;
}
