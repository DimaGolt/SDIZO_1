#ifndef SDIZO_1_AUTOMATICTESTS_H
#define SDIZO_1_AUTOMATICTESTS_H

#include <string>
#include "Stopwatch.h"
#include <fstream>

class AutomaticTests {

public:
    AutomaticTests();
    ~AutomaticTests();
    void arrayTest();
    void listTest();
    void heapTest();
    void treeTest();

private:
    Stopwatch* stopwatch;
    std::string resultsPath = "C:\\Users\\Home\\CLionProjects\\SDIZO_1\\res\\";
    int getSelected(std::string header);
};


#endif //SDIZO_1_AUTOMATICTESTS_H
