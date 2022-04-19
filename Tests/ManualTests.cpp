#include <iostream>
#include "ManualTests.h"
#include "../Array/Array.h"
#include "MenuPrints.h"
#include "../Heap/Heap.h"
#include "../LinkedList/DoublyLinkedList.h"

using namespace std;

void ManualTests::arrayTest() {
    Array array;
    int option = 99;
    int var;
    int index;

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
                array.addFront(var);
                break;
            case 2:
                MenuPrints::giveVar();
                cin >> var;
                array.addEnd(var);
                break;
            case 3:
                MenuPrints::giveVar();
                cin >> var;
                MenuPrints::giveIndex();
                cin >> index;
                array.addAt(var, index);
                break;
            case 4:
                array.removeFirst();
                break;
            case 5:
                array.removeLast();
                break;
            case 6:
                MenuPrints::giveIndex();
                cin >> index;
                array.removeAt(index);
                break;
            case 7:
                MenuPrints::giveVar();
                cin >> var;
                array.contains(var);
                break;
            case 8:
                array.print();
                break;
        }
    }
}

void ManualTests::heapTest() {
    Heap heap;
    int option = 99;
    int var;
    int index;

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
                heap.add(var);
                break;
            case 2:
                MenuPrints::giveVar();
                cin >> var;
                heap.remove(var);
                break;
            case 3:
                MenuPrints::giveVar();
                cin >> var;
                heap.contains(var);
                break;
            case 4:
                heap.print();
        }
    }
}

void ManualTests::listTest() {
    DoublyLinkedList list;
    int option = 99;
    int var;
    int index;

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
                list.addFront(var);
                break;
            case 2:
                MenuPrints::giveVar();
                cin >> var;
                list.addEnd(var);
                break;
            case 3:
                MenuPrints::giveVar();
                cin >> var;
                MenuPrints::giveIndex();
                cin >> index;
                list.addAt(var, index);
                break;
            case 4:
                list.removeFront();
                break;
            case 5:
                list.removeEnd();
                break;
            case 6:
                MenuPrints::giveIndex();
                cin >> index;
                list.removeAt(index);
                break;
            case 7:
                MenuPrints::giveVar();
                cin >> var;
                list.contains(var);
                break;
            case 8:
                list.print();
                break;
        }
    }
}