#include <iostream>
#include "ManualTests.h"
#include "../Array/Array.h"
#include "MenuPrints.h"
#include "../Heap/Heap.h"
#include "../LinkedList/DoublyLinkedList.h"
#include "../Tree/Tree.h"

using namespace std;

ManualTests::ManualTests() : stopwatch(new Stopwatch()) {}

void ManualTests::arrayTest() {
    Array array;
    int option = 99;
    int var;
    int index;
    string fileName;

    while (option != 0) {
        MenuPrints::testArray();
        cin >> option;
        switch (option) {
            default:
                MenuPrints::badOption();
                break;
            case 0:
                break;
            case 1:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                array.addFront(var);
                stopwatch->stop();
                break;
            case 2:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                array.addEnd(var);
                stopwatch->stop();
                break;
            case 3:
                MenuPrints::giveVar();
                cin >> var;
                MenuPrints::giveIndex();
                cin >> index;
                stopwatch->start();
                array.addAt(var, index);
                stopwatch->stop();
                break;
            case 4:
                stopwatch->start();
                array.removeFirst();
                stopwatch->stop();
                break;
            case 5:
                stopwatch->start();
                array.removeLast();
                stopwatch->stop();
                break;
            case 6:
                MenuPrints::giveIndex();
                cin >> index;
                stopwatch->start();
                array.removeAt(index);
                stopwatch->stop();
                break;
            case 7:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                array.contains(var);
                stopwatch->stop();
                break;
            case 8:
                stopwatch->start();
                array.print();
                stopwatch->stop();
                break;
            case 9:
                MenuPrints::giveFileName();
                cin >> fileName;
                stopwatch->start();
                array.fromFile(fileName);
                stopwatch->stop();
                break;
        }
        cout << "Time spent: " << stopwatch->getTime() << " ns" << endl;
    }
}

void ManualTests::heapTest() {
    Heap heap;
    int option = 99;
    int var;
    string fileName;

    while (option != 0) {
        MenuPrints::testHeap();
        cin >> option;
        switch (option) {
            default:
                MenuPrints::badOption();
                break;
            case 0:
                break;
            case 1:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                heap.add(var);
                stopwatch->stop();
                break;
            case 2:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                heap.remove(var);
                stopwatch->stop();
                break;
            case 3:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                heap.contains(var);
                stopwatch->stop();
                break;
            case 4:
                stopwatch->start();
                heap.print();
                stopwatch->stop();
                break;
            case 5:
                MenuPrints::giveFileName();
                cin >> fileName;
                stopwatch->start();
                heap.fromFile(fileName);
                stopwatch->stop();
                break;
        }
        cout << "Time spent: " << stopwatch->getTime() << " ns" << endl;
    }
}

void ManualTests::listTest() {
    DoublyLinkedList list;
    int option = 99;
    int var;
    int index;
    string fileName;

    while (option != 0) {
        MenuPrints::testList();
        cin >> option;
        switch (option) {
            default:
                MenuPrints::badOption();
                break;
            case 0:
                break;
            case 1:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                list.addFront(var);
                stopwatch->stop();
                break;
            case 2:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                list.addEnd(var);
                stopwatch->stop();
                break;
            case 3:
                MenuPrints::giveVar();
                cin >> var;
                MenuPrints::giveIndex();
                cin >> index;
                stopwatch->start();
                list.addAt(var, index);
                stopwatch->stop();
                break;
            case 4:
                stopwatch->start();
                list.removeFront();
                stopwatch->stop();
                break;
            case 5:
                stopwatch->start();
                list.removeEnd();
                stopwatch->stop();
                break;
            case 6:
                MenuPrints::giveIndex();
                cin >> index;
                stopwatch->start();
                list.removeAt(index);
                stopwatch->stop();
                break;
            case 7:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                list.contains(var);
                stopwatch->stop();
                break;
            case 8:
                stopwatch->start();
                list.print();
                stopwatch->stop();
                break;
            case 9:
                MenuPrints::giveFileName();
                cin >> fileName;
                stopwatch->start();
                list.fromFile(fileName);
                stopwatch->stop();
                break;
        }
        cout << "Time spent: " << stopwatch->getTime() << " ns" << endl;
    }
}

void ManualTests::treeTest() {
    Tree tree;
    int option = 99;
    int var;
    string fileName;

    while (option != 0) {
        MenuPrints::testTree();
        cin >> option;
        switch (option) {
            default:
                MenuPrints::badOption();
                break;
            case 0:
                break;
            case 1:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                tree.add(var);
                stopwatch->stop();
                break;
            case 2:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                tree.remove(var);
                stopwatch->stop();
                break;
            case 3:
                MenuPrints::giveVar();
                cin >> var;
                stopwatch->start();
                tree.contains(var);
                stopwatch->stop();
                break;
            case 4:
                stopwatch->start();
                tree.print();
                stopwatch->stop();
                break;
            case 5:
                MenuPrints::giveFileName();
                cin >> fileName;
                stopwatch->start();
                tree.fromFile(fileName);
                stopwatch->stop();
                break;
        }
        cout << "Time spent: " << stopwatch->getTime() << " ns" << endl;
    }
}