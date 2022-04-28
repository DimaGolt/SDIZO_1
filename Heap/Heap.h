//
// Created by Home on 18-Apr-22.
//

#ifndef SDIZO_1_HEAP_H
#define SDIZO_1_HEAP_H


class Heap {

public:
    Heap();
    ~Heap();
    void add(int var);
    bool contains(int var);
    int indexOf(int var);
    void remove(int var);
    void print();

    void fromFile(std::string fileName);

private:
    int *headerPtr;

    int size;
    void correctHeap();


};


#endif //SDIZO_1_HEAP_H
