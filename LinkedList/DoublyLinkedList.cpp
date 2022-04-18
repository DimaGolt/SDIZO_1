#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    firstNode = nullptr;
    lastNode = nullptr;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    ListNode *currentNode = firstNode;

    while (firstNode != nullptr) {
        firstNode = currentNode->next;
        delete currentNode;
        currentNode = firstNode;
    }
}

void DoublyLinkedList::addFront(int var) {
    if (size == 0) {
        createFirstNode();
        return;
    }

    firstNode->previous = new ListNode(var, firstNode, nullptr);
    firstNode = firstNode->previous;
    size++;
}

void DoublyLinkedList::addBack(int var) {
    if (size == 0) {
        createFirstNode();
        return;
    }

    lastNode->next = new ListNode(var, nullptr, lastNode);
    lastNode = lastNode->next;
    size++;
}

void DoublyLinkedList::addAt(int var, int index) {
    int middleIndex = size / 2;
    if (index > size || index < 0) {
        cout << "Can't add element at index " << index << ", out of bounds" << endl;
        return;
    } else if (index == 0) {
        addFront(var);
        return;
    } else if (index == size) {
        addBack(var);
        return;
    } else if (index < middleIndex) {
        addFromFront(var);
        return;
    } else {
        addFromBack(var);
        return;
    }
}

void DoublyLinkedList::contains(int var) {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    }

    ListNode* foo = firstNode;

    do{
        if(foo->value == var)
            cout << "Found " << var << endl;
        foo = foo->next;
    } while (foo->next != nullptr);
}

void DoublyLinkedList::removeFront() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    } else if (size == 1){
        delete firstNode;
        firstNode = lastNode = nullptr;
        size--;
        return;
    } else {
        firstNode = firstNode->next;
        delete firstNode->previous;
        firstNode->previous = nullptr;
        size--;
        return;
    }
}

void DoublyLinkedList::removeBack() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    } else if (size == 1){
        delete firstNode;
        firstNode = lastNode = nullptr;
        size--;
        return;
    } else {
        lastNode = lastNode->previous;
        delete lastNode->next;
        lastNode->next = nullptr;
        size--;
        return;
    }
}

void DoublyLinkedList::removeAt(int index) {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    } else if (index >= size || index < 0) {
        cout << "Index out of bounds" << endl;
        return;
    } else if ()
}