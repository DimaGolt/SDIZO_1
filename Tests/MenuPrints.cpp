#include <iostream>
#include "MenuPrints.h"

using namespace std;

void MenuPrints::mainMenu() {
    cout << "Choose data structure:" << endl;
    cout << "   1. Array" << endl;
    cout << "   2. Heap" << endl;
    cout << "   3. Doubly linked list" << endl;
    cout << "   4. Red Black Tree" << endl;
    cout << "   0. Exit" << endl;
}

void MenuPrints::testType() {
    cout << "Choose test type:" << endl;
    cout << "   1. Manual tests" << endl;
    cout << "   2. Automatic tests" << endl;
}

void MenuPrints::testArray() {
    cout << "Choose array function:" << endl;
    cout << "    1. Add at front" << endl;
    cout << "    2. Add at end" << endl;
    cout << "    3. Add at index" << endl;
    cout << "    4. Remove first" << endl;
    cout << "    5. Remove last" << endl;
    cout << "    6. Remove at index" << endl;
    cout << "    7. Check if contains" << endl;
    cout << "    8. Print array" << endl;
    cout << "    9. Read from file" << endl;
    cout << "    0. Exit" << endl << endl;
    cout << "Choice: ";
}

void MenuPrints::testHeap() {
    cout << "Choose heap function:" << endl;
    cout << "    1. Add" << endl;
    cout << "    2. Remove" << endl;
    cout << "    3. Check if contains" << endl;
    cout << "    4. Print heap" << endl;
    cout << "    5. Read from file" << endl;
    cout << "    0. Exit" << endl << endl;
    cout << "Choice: ";
}

void MenuPrints::testList() {
    cout << "Choose list function:" << endl;
    cout << "    1. Add at front" << endl;
    cout << "    2. Add at end" << endl;
    cout << "    3. Add at index" << endl;
    cout << "    4. Remove first" << endl;
    cout << "    5. Remove last" << endl;
    cout << "    6. Remove at index" << endl;
    cout << "    7. Check if contains" << endl;
    cout << "    8. Print array" << endl;
    cout << "    9. Read from file" << endl;
    cout << "    0. Exit" << endl << endl;
    cout << "Choice: ";
}

void MenuPrints::testTree() {
    cout << "Choose tree function:" << endl;
    cout << "    1. Add" << endl;
    cout << "    2. Remove" << endl;
    cout << "    3. Check if contains" << endl;
    cout << "    4. Print tree" << endl;
    cout << "    5. Read from file" << endl;
    cout << "    0. Exit" << endl << endl;
    cout << "Choice: ";
}

void MenuPrints::badOption () {
    cout << "Bad option, choose another" << endl;
}

void MenuPrints::giveVar() {
    cout << "Input variable: ";
}

void MenuPrints::giveFileName() {
    cout << "Enter file name: ";
}

void MenuPrints::giveIndex() {
    cout << "Input index: ";
}

int MenuPrints::getType() {
    int testOption = 99;
    while (testOption != 1 || testOption != 2) {
        MenuPrints::testType();
        cin >> testOption;
        if (testOption == 1)
            return 1;
        else if (testOption == 2)
            return 2;
        else
            MenuPrints::badOption();
    }
}