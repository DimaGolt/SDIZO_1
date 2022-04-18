#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap() {
    headerPtr = nullptr;
    size = 0;
}

Heap::~Heap() {
    if (headerPtr != nullptr) {
        delete[] headerPtr;
    }
}

void Heap::add(int var) {
    int *newHeadPtr = new int[size + 1];
    newHeadPtr[size] = var;

    for (int i = 0; i < size; i++) {
        newHeadPtr[i] = headerPtr[i];
    }

    delete[] headerPtr;
    headerPtr = newHeadPtr;
    size++;
    Heap::correctHeap();
}

bool Heap::contains(int var) {
    for (int i = 0; i < size; i++) {
        if (headerPtr[i] == var) {
            cout << "Found " << var << " at " << i << endl;
            return true;
        }
    }

    cout << "Heap does not contain " << var << endl;
    return false;
}

void Heap::remove(int var) {
    int index = indexOf(var);

    if(index == -1)
        return;

    swap(headerPtr[index], headerPtr[size - 1]);

    int *newHeaderPtr = new int[size - 1];

    for (int i = 0; i < size - 1; ++i)
        newHeaderPtr[i] = headerPtr[i];

    delete[] headerPtr;
    headerPtr = newHeaderPtr;
    size--;

    correctHeap();
}

void Heap::correctHeap() {
    int childIndex = size - 1;
    int parentIndex = (childIndex - 1) / 2;
    bool swapped = true;
    while (childIndex != 0 && swapped) {
        if (headerPtr[childIndex] > headerPtr[parentIndex]) {
            swap(headerPtr[childIndex], headerPtr[parentIndex]);
            swapped = true;
        } else
            swapped = false;
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

void Heap::print() {
    if (headerPtr != nullptr) {
        cout << "Heap contains: " << endl;
        for (int i = 0; i < size; i++) {
            cout << " [" << i << "] " << headerPtr[i] << endl;
        }
    } else {
        cout << "Heap is empty" << endl;
    }
}

int Heap::indexOf(int var) {
    for (int i = 0; i < size; i++) {
        if (headerPtr[i] == var) {
            cout << "Found " << var << " at " << i << endl;
            return i;
        }
    }

    cout << "Heap does not contain " << var << endl;
    return -1;
}