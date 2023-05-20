#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;
        Node(const T &value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node *head;
    int size;

public:
    class Iterator
    {
    private:
        Node *current;
        Node *head;

    public:
        Iterator(Node *node, Node *listHead) : current(node), head(listHead) {}

        void setToBegin();
        
        bool isEnd();

        T getValue();

        void moveToNext();

        void moveToPrevious();
    };

    DoublyLinkedList();

    ~DoublyLinkedList();

    int getSize();

    bool isEmpty();

    void insert(const T &value, int position);

    T getElementAt(int position);

    int findPositionOf(const T &value);

    Iterator getIterator();

    void clear();
};

template <typename T>
void processDoublyLinkedList();