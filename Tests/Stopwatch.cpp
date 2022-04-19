#include "Stopwatch.h"

void Stopwatch::start() {
    startPoint = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stop() {
    endPoint = std::chrono::high_resolution_clock::now();
}

long long Stopwatch::getTime() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(endPoint - startPoint).count();
}