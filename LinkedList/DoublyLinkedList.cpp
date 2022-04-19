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
        createFirstNode(var);
    } else {
        firstNode->previous = new ListNode(var, firstNode, nullptr);
        firstNode = firstNode->previous;
        size++;
    }
}

void DoublyLinkedList::addBack(int var) {
    if (size == 0) {
        createFirstNode(var);
    } else {
        lastNode->next = new ListNode(var, nullptr, lastNode);
        lastNode = lastNode->next;
        size++;
    }
}

void DoublyLinkedList::addAt(int var, int index) {
    int middleIndex = size / 2;

    if (index > size || index < 0) {
        cout << "Can't add element at index " << index << ", out of bounds" << endl;
    } else if (index == 0) {
        addFront(var);
    } else if (index == size) {
        addBack(var);
    } else if (index < middleIndex) {
        addFromFront(index, var);
    } else {
        addFromBack(index, var);
    }
}

void DoublyLinkedList::contains(int var) {
    if (size == 0) {
        cout << "List is empty" << endl;
    } else {
        ListNode *iter = firstNode;

        do {
            if (iter->value == var)
                cout << "Found " << var << endl;
            iter = iter->next;
        } while (iter->next != nullptr);
    }
}

void DoublyLinkedList::removeFront() {
    if (size == 0) {
        cout << "List is empty" << endl;
    } else if (size == 1) {
        delete firstNode;
        firstNode = lastNode = nullptr;
        size--;
    } else {
        firstNode = firstNode->next;
        delete firstNode->previous;
        firstNode->previous = nullptr;
        size--;
    }
}

void DoublyLinkedList::removeBack() {
    if (size == 0) {
        cout << "List is empty" << endl;
    } else if (size == 1) {
        delete firstNode;
        firstNode = lastNode = nullptr;
        size--;
    } else {
        lastNode = lastNode->previous;
        delete lastNode->next;
        lastNode->next = nullptr;
        size--;
    }
}

void DoublyLinkedList::removeAt(int index) {
    int middleIndex = size / 2;

    if (size == 0) {
        cout << "List is empty" << endl;
    } else if (index >= size || index < 0) {
        cout << "Index out of bounds" << endl;
    } else if (index == size - 1) {
        removeBack();
    } else if (index == 0) {
        removeFront();
    } else if (index < middleIndex) {
        removeFromFront(index);
    } else {
        removeFromBack(index);
    }
}

void DoublyLinkedList::print() {
    if (size > 0) {
        ListNode *iter = firstNode;
        int index = 0;
        while (iter != nullptr) {
            cout << index << " => " << iter->value << endl;
            iter = iter->next;
            index++;
        }
    } else {
        cout << "List is empty" << endl;
    }
}

void DoublyLinkedList::createFirstNode(int var) {
    firstNode = lastNode = new ListNode(var, nullptr, nullptr);
    size++;
}

void DoublyLinkedList::addFromFront(int index, int var) {
    int currentIndex = 0;
    ListNode *currentNode = firstNode;

    while (currentIndex < index) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    ListNode *nodeToAdd = new ListNode(var, currentNode, currentNode->previous);
    currentNode->previous->next = nodeToAdd;
    currentNode->previous = nodeToAdd;
    size++;
}

void DoublyLinkedList::addFromBack(int index, int var) {
    int currentIndex = size - 1;
    ListNode *currentNode = lastNode;

    while (currentIndex > index) {
        currentNode = currentNode->previous;
        currentIndex--;
    }

    ListNode *nodeToAdd = new ListNode(var, currentNode, currentNode->previous);
    currentNode->previous->next = nodeToAdd;
    currentNode->previous = nodeToAdd;
    size++;
}

void DoublyLinkedList::removeFromFront(int index) {
    int currentIndex = 0;
    ListNode *currentNode = firstNode;

    while (currentIndex < index) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    currentNode->previous->next = currentNode->next;
    currentNode->next->previous = currentNode->previous;
    size--;

    delete currentNode;
}

void DoublyLinkedList::removeFromBack(int index) {
    int currentIndex = size - 1;
    ListNode *currentNode = lastNode;

    while (currentIndex > index) {
        currentNode = currentNode->previous;
        currentIndex--;
    }

    currentNode->previous->next = currentNode->next;
    currentNode->next->previous = currentNode->previous;
    size--;

    delete currentNode;
}