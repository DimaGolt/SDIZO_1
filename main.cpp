#include <iostream>
#include "Tests/ManualTests.h"

using namespace std;

int main() {
    ManualTests tests;
    cout << "SDiZO, Projekt 1, Dmitry Goltstein, 259089" << endl << endl;
    tests.arrayTest();
    tests.listTest();
    tests.heapTest();
    tests.treeTest();
    return 0;
}
