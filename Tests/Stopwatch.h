#ifndef SDIZO_1_STOPWATCH_H
#define SDIZO_1_STOPWATCH_H

#include <chrono>

class Stopwatch {
public:
    void start();
    void stop();
    long long int getTime();

private:
    std::chrono::high_resolution_clock::time_point startPoint;
    std::chrono::high_resolution_clock::time_point endPoint;
};


#endif //SDIZO_1_STOPWATCH_H
