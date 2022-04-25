#include <iostream>
#include "MenuPrints.h"

using namespace std;

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
    cout << "    0. Exit" << endl << endl;
    cout << "Choice: ";
}

void MenuPrints::testHeap() {
    cout << "Choose heap function:" << endl;
    cout << "    1. Add" << endl;
    cout << "    2. Remove" << endl;
    cout << "    3. Check if contains" << endl;
    cout << "    4. Print heap" << endl;
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
    cout << "    0. Exit" << endl << endl;
    cout << "Choice: ";
}

void MenuPrints::testTree() {
    cout << "Choose tree function:" << endl;
    cout << "    1. Add" << endl;
    cout << "    2. Remove" << endl;
    cout << "    3. Check if contains" << endl;
    cout << "    4. Print tree" << endl;
    cout << "    0. Exit" << endl << endl;
    cout << "Choice: ";
}

void MenuPrints::badOption () {
    cout << "Bad option, choose another" << endl;
}

void MenuPrints::giveVar() {
    cout << "Input variable: ";
}

void MenuPrints::giveIndex() {
    cout << "Input index: ";
}