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

private:
    ListNode* firstNode;
    ListNode* lastNode;
    int size;

    void addFront(int var);

    void addBack(int var);

    void addAt(int var, int index);

    void contains(int var);

    void removeFront();

    void removeBack();

    void removeAt(int index);
};


#endif //SDIZO_1_DOUBLYLINKEDLIST_H