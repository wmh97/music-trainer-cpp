#include <iostream>
#include "linkedList.h"

Node::Node(int value)
{
    this->data = value;
}

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::LinkedList(int value)
{
    Node* newNode = new Node(value);
    this->head = newNode;
    this->tail = newNode;
    this->size++;
}

void LinkedList::addNodeValue(int value)
{
    Node* nextNode = new Node(value);
    if(!this->head && !this->tail)
    {
        this->head = nextNode;
        this->tail = nextNode;
        this->size++;
        return;
    }

    this->tail->next = nextNode;
    this->tail = nextNode;
    this->size++;

}

void LinkedList::addNodeValueAtIndex(int value, int index)
{
    Node* beforeAdd = this->head;

    index -= 1;
    while(index-- && beforeAdd)
    {
        beforeAdd = beforeAdd->next;
    }

    Node* newNode = new Node(value);
    Node* afterAdd = beforeAdd->next;

    beforeAdd->next = newNode;
    newNode->next = afterAdd;

    this->size++;
}

void LinkedList::deleteNodeAtIndex(int index)
{
    Node* beforeDelete = this->head;

    index -= 1;
    while(index-- && beforeDelete)
    {
        beforeDelete = beforeDelete->next;
    }

    Node* afterDelete = beforeDelete->next->next;
    beforeDelete->next->next = nullptr;

    delete beforeDelete->next;
    beforeDelete->next = afterDelete;

    this->size--;
}

int LinkedList::getSize()
{
    return this->size;
}

int LinkedList::getHead()
{
    return this->head->data;
}

int LinkedList::getTail()
{
    return this->tail->data;
}

void LinkedList::printList()
{
    Node* tempHead = this->head;
    while(tempHead)
    {
        std::cout << tempHead->data << std::endl;
        tempHead = tempHead->next;
    }
}

