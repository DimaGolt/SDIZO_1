#include <iostream>
#include <fstream>
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

void DoublyLinkedList::addEnd(int var) {
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
        addEnd(var);
    } else if (index < middleIndex) {
        addFromFront(index, var);
    } else {
        addFromEnd(index, var);
    }
}

void DoublyLinkedList::contains(int var) {
    if (size == 0) {
        cout << "List is empty" << endl;
    } else {
        ListNode *iter = firstNode;

        for (int i = 0; i < size; ++i) {
            if (iter->value == var)
                cout << "Found " << var << " in [" << i << "] node" << endl;
            iter = iter->next;
        }
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

void DoublyLinkedList::removeEnd() {
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
        removeEnd();
    } else if (index == 0) {
        removeFront();
    } else if (index < middleIndex) {
        removeFromFront(index);
    } else {
        removeFromEnd(index);
    }
}

void DoublyLinkedList::print() {
    if (size > 0) {
        ListNode *iter = firstNode;
        int index = 0;
        while (iter != nullptr) {
            cout << "[" << index << "] => " << iter->value << endl;
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

void DoublyLinkedList::addFromEnd(int index, int var) {
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

void DoublyLinkedList::removeFromEnd(int index) {
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

void DoublyLinkedList::fromFile(string fileName) {
    ifstream file(fileName); //otwieramy plik ze ścieżki podanej przez usera
    int elementsCount;
    string buff = "";
    getline(file, buff);
    elementsCount = stoi(buff); //pierwsza linia pliku zawiera ilość elementów w pliku

    int *newTable = new int[elementsCount]; //tworzymy pomocniczą dynamiczną tablicę

    for (int i = 0; i < elementsCount; i++) {     // uzupełniamy pomocniczą tablicę wartościami z pliku
        getline(file, buff);
        newTable[i] =
                std::stoi(buff);
    }

    for (int i = 0; i < elementsCount; ++i) {
        addEnd(newTable[i]);
    }
}

int DoublyLinkedList::getSize() {
    return size;
}
