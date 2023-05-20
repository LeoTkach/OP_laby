#include <iostream>
#include <string>
#include "mylib.h"
using namespace std;




int main() {
    cout << "Enter the type of the Doubly Linked List (int, double, char, string): ";
    string type;
    cin >> type;

    if (type == "int") {
        processDoublyLinkedList<int>();
    } else if (type == "double") {
        processDoublyLinkedList<double>();
    } else if (type == "char") {
        processDoublyLinkedList<char>();
    } else if (type == "string") {
        processDoublyLinkedList<string>();
    } else {
        cout << "Unsupported type" << endl;
    }

    return 0;
}