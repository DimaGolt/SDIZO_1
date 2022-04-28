#include <iostream>
#include "Tests/ManualTests.h"
#include "Tests/AutomaticTests.h"

using namespace std;

int main() {
    ManualTests tests;
    cout << "SDiZO, Projekt 1, Dmitry Goltstein, 259089" << endl << endl;
    tests.arrayTest();
    tests.listTest();
    tests.heapTest();
    tests.treeTest();
    AutomaticTests automaticTests;
    automaticTests.heapTest();

    return 0;
}