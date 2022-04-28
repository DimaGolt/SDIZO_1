#include <iostream>
#include "Tests/ManualTests.h"
#include "Tests/AutomaticTests.h"
#include "Tests/MenuPrints.h"

using namespace std;

int main() {
    ManualTests tests;
    AutomaticTests automaticTests;
    cout << "SDiZO, Projekt 1, Dmitry Goltstein, 259089" << endl << endl;

    int option = 99;
    int testOption;

    while (option != 0) {
        MenuPrints::mainMenu();
        cin >> option;
        switch (option) {
            default:
                MenuPrints::badOption();
                break;
            case 0:
                break;
            case 1:
                testOption = MenuPrints::getType();
                if (testOption == 1)
                    tests.arrayTest();
                else
                    automaticTests.arrayTest();
                option = 99;
                break;
            case 2:
                testOption = MenuPrints::getType();
                if (testOption == 1)
                    tests.heapTest();
                else
                    automaticTests.heapTest();
                option = 99;
                break;
            case 3:
                testOption = MenuPrints::getType();
                if (testOption == 1)
                    tests.listTest();
                else
                    automaticTests.listTest();
                option = 99;
                break;
            case 4:
                testOption = MenuPrints::getType();
                if (testOption == 1)
                    tests.treeTest();
                else
                    automaticTests.treeTest();
                option = 99;
                break;
        }
    }

    return 0;
}