#include <iostream>

class Node
{
public:

    int data;
    Node* next = nullptr;

    Node(int value);

};


class LinkedList
{
public:

    Node* head;
    Node* tail;
    int size = 0;

    LinkedList();

    LinkedList(int value);

    void addNodeValue(int value);

    void addNodeValueAtIndex(int value, int index);

    void deleteNodeAtIndex(int index);

    int getSize();

    int getHead();

    int getTail();

    void printList();

};