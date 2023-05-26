#include "mylib.h"
#include <iostream>
#include <string>

using namespace std;


template<typename T>
void DoublyLinkedList<T>::Iterator::setToBegin()  {
    current = head;
}

template<typename T>
bool DoublyLinkedList<T>::Iterator::isEnd()  {
    return current == nullptr;
}

template<typename T>
T DoublyLinkedList<T>::Iterator::getValue()  {
    if (current != nullptr) {
        return current->data;
    }
}

template<typename T>
void DoublyLinkedList<T>::Iterator::moveToNext() {
    if (current != nullptr) {
        current = current->next;
    }
}

template<typename T>
void DoublyLinkedList<T>::Iterator::moveToPrevious() {
    if (current != nullptr) {
        current = current->prev;
    }
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), size(0) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
int DoublyLinkedList<T>::getSize()  {
    return size;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty()  {
    return size == 0;
}

template<typename T>
void DoublyLinkedList<T>::insert(const T& value, int position) {

    Node* newNode = new Node(value);

    if (position == 0) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    size++;
}

template<typename T>
T DoublyLinkedList<T>::getElementAt(int position)  {
    position -=1;
    Node* current = head;
    for (int i = 0; i < position ; i++) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
int DoublyLinkedList<T>::findPositionOf(const T& value)  {
    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

template<typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::getIterator()  {
    return Iterator(head, head);
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}



template<typename T>
void processDoublyLinkedList() {
    DoublyLinkedList<T> myList;
    T value;
    int length;

    cout<<endl << "Enter the length of the Doubly Linked List: ";
    cin >> length;

    cout << "Enter the elements of the Doubly Linked List :\n";
    for (int i = 0; i < length; ++i) {
        cout<<"The "<<i+1<<" element is: ";
        cin >> value;
        myList.insert(value, myList.getSize());
    }


    cout <<endl << "List size: " << myList.getSize() << endl;

    cout << "List contains: " << endl;
    typename DoublyLinkedList<T>::Iterator iterator = myList.getIterator();
    iterator.setToBegin();
    cout<<"[ ";
    for (int i = 0; i < length-1; ++i) {
        cout << iterator.getValue() << ", ";
        iterator.moveToNext();
    }
    cout<< iterator.getValue()<<" ]"<<endl;

    cout<<endl;

    int position;
    do{
        cout << "Enter the position of an element to show its value: ";
        cin >> position;
        
        if (position >= 1 && position <= myList.getSize()) {
            T element = myList.getElementAt(position);
            cout << "Value of an element at position " << position << " is: " << element << endl;
        } else {
            cout << "There is no element at position: " << position << endl;
        }
    }while(position < 1 || position > myList.getSize());

    cout<<endl;
    T searchValue;
    int searchPosition;
    do{
        cout << "Enter the value of an element to find its position: ";
        cin >> searchValue;
        searchPosition = myList.findPositionOf(searchValue);
        if (searchPosition != -1) {
            cout << "Element " << searchValue << " found at position: " << searchPosition << endl;
        } else {
            cout << "Element " << searchValue << " not found in the list" << endl;
        }
    }while(searchPosition==-1);

    cout<<endl;
    T newEl;
    cout << "Enter the value of the new element to insert it in the list: ";
    cin >> newEl;
    int newPos;
    do{
        cout << "Enter the position of the new element to insert it in the list: ";
        cin >> newPos;
        if(newPos<=0 || newPos >myList.getSize()+1){
            cout<<"Position of the new element should be from 1 to "<<myList.getSize()+1<<endl;
        }
    }while(newPos<=0 || newPos >myList.getSize()+1);
    myList.insert(newEl, newPos-1);

    cout << "List size: " << myList.getSize() << endl;

    cout << "List contains: " << endl;
    typename DoublyLinkedList<T>::Iterator iterator1 = myList.getIterator();
    iterator1.setToBegin();
    length=myList.getSize();
    cout<<"[ ";
    for (int i = 0; i < length-1; ++i) {
        cout << iterator1.getValue() << ", ";
        iterator1.moveToNext();
    }
    cout<< iterator1.getValue()<<" ]"<<endl;
}

template void processDoublyLinkedList<int>();
template void processDoublyLinkedList<char>();
template void processDoublyLinkedList<double>();
template void processDoublyLinkedList<string>();