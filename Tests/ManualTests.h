#ifndef SDIZO_1_MANUALTESTS_H
#define SDIZO_1_MANUALTESTS_H


#include "Stopwatch.h"

class ManualTests {

public:
    ManualTests();
    void arrayTest();
    void heapTest();

    void listTest();

    void treeTest();

private:
    Stopwatch* stopwatch;

};


#endif //SDIZO_1_MANUALTESTS_H
