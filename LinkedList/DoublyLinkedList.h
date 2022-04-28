#ifndef SDIZO_1_DOUBLYLINKEDLIST_H
#define SDIZO_1_DOUBLYLINKEDLIST_H


struct ListNode {
    int value{0};

    ListNode *next{nullptr};
    ListNode *previous{nullptr};

    ListNode(int value, ListNode *next, ListNode *previous) : value(value), previous(previous), next(next) {}
};

class DoublyLinkedList {

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void addFront(int var);
    void addEnd(int var);
    void addAt(int var, int index);
    void contains(int var);
    void removeFront();
    void removeEnd();
    void removeAt(int index);
    int getSize();
    void print();

    void fromFile(std::string fileName);

private:
    ListNode* firstNode;
    ListNode* lastNode;
    int size;
    void addFromFront(int index, int var);
    void addFromEnd(int index, int var);
    void removeFromFront(int index);
    void removeFromEnd(int index);
    void createFirstNode(int var);

};


#endif //SDIZO_1_DOUBLYLINKEDLIST_H
