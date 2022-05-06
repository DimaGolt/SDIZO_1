#include <iostream>
#include <fstream>
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
    correctHeap();
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

    //swap searched variable with last element of heap
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
    int startIndex = (size / 2) -1;

    for (int i = startIndex; i >= 0; i--)
        heapify(i);
}

void Heap::heapify(int i) {
    int biggest {i}, left {2*i+1}, right {2*i +2};

    if(left < size && headerPtr[left] > headerPtr[biggest])
        biggest = left;

    if(right < this->size && headerPtr[right] > headerPtr[biggest])
        biggest = right;

    if(biggest != i){
        swap(headerPtr[i], headerPtr[biggest]);

        heapify(biggest);
    }
}

void Heap::print() {
    if (headerPtr != nullptr) {
        int amountOnLevel = 1;
        int currentLevelNum = 0;
        cout << "Heap contains: " << endl;
        for (int i = 0; i < size; i++) {
            cout << " [" << i << "] " << headerPtr[i] << " ";
            currentLevelNum++;
            if (currentLevelNum == amountOnLevel){
                cout << endl;
                currentLevelNum = 0;
                amountOnLevel *= 2;
            }
        }
        cout << endl;
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

void Heap::fromFile(string fileName) {
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
        add(newTable[i]);
    }
}