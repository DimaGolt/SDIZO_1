#include "AutomaticTests.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include "../Array/Array.h"
#include "../Heap/Heap.h"
#include "../LinkedList/DoublyLinkedList.h"
#include "../Tree/Tree.h"
#include "MenuPrints.h"

using namespace std;

AutomaticTests::AutomaticTests()
        : stopwatch(new Stopwatch())
{
    srand(time(nullptr));
}

AutomaticTests::~AutomaticTests()
{
    if (stopwatch != nullptr)
    {
        delete stopwatch;
    }
}

int AutomaticTests::getSelected(string header)
{
    int option = -1;
    cout << header << endl;
    cin >> option;
    cout << string(50, '#') << endl;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Failed. Selected -1 instead" << endl;
        return -1;
    }
    return option;
}

void AutomaticTests::arrayTest()
{
    Array* systemUnderTests;

    int dataNumber = this->getSelected("Enter number of data");
    int repeats = this->getSelected("Enter number of repeats");
    int maxDataSize = this->getSelected("Enter maximum data size");

    if (dataNumber < 10 && maxDataSize < 10)
    {
        cout << "Invalid initial data" << endl;
        return;
    }

    ofstream resultFile(this->resultsPath + "array/" + to_string(dataNumber) + "-results.txt");

    vector<int> addResults;
    addResults.reserve(dataNumber);
    vector<int> removeResults;
    removeResults.reserve(dataNumber);
    vector<int> searchResults;
    searchResults.reserve(dataNumber);
    int valueToAdd;
    int valueToSearch = -1;

    for (int i = 0; i < repeats; i++)
    {
        systemUnderTests = new Array();

        for (int i = 0; i < dataNumber - 1; i++)
        {
            valueToAdd = rand() % (maxDataSize + 1);
            systemUnderTests->addFront(valueToAdd);
            if (i == dataNumber / 2)
            {
                valueToSearch = valueToAdd;
            }
        }

        this->stopwatch->start();
        systemUnderTests->addFront(rand() % (maxDataSize + 1));
        this->stopwatch->stop();
        addResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->contains(valueToSearch);
        this->stopwatch->stop();
        searchResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->removeFirst();
        this->stopwatch->stop();
        removeResults.push_back(this->stopwatch->getTime());

        delete systemUnderTests;
    }

    resultFile << "Array: contains, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(searchResults.begin(), searchResults.end(), 0) / searchResults.size()) << endl;
    resultFile << "Array: addFront, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << endl;
    resultFile << "Array: removeFront, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << endl;

    addResults.clear();
    removeResults.clear();
    searchResults.clear();

    for (int i = 0; i < repeats; i++)
    {
        systemUnderTests = new Array();

        for (int i = 0; i < dataNumber - 1; i++)
        {
            systemUnderTests->addFront(rand() % (maxDataSize + 1));
        }

        this->stopwatch->start();
        systemUnderTests->addEnd(rand() % (maxDataSize + 1));
        this->stopwatch->stop();
        addResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->removeLast();
        this->stopwatch->stop();
        removeResults.push_back(this->stopwatch->getTime());

        delete systemUnderTests;
    }

    resultFile << "Array: addEnd, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << endl;
    resultFile << "Array: removeEnd, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << endl;

    addResults.clear();
    removeResults.clear();

    for (int i = 0; i < repeats; i++)
    {
        systemUnderTests = new Array();

        for (int i = 0; i < dataNumber - 1; i++)
        {
            systemUnderTests->addFront(rand() % (maxDataSize + 1));
        }

        this->stopwatch->start();
        systemUnderTests->addAt(rand() % systemUnderTests->getSize(), rand() % (maxDataSize + 1));
        this->stopwatch->stop();
        addResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->removeAt(rand() % systemUnderTests->getSize());
        this->stopwatch->stop();
        removeResults.push_back(this->stopwatch->getTime());

        delete systemUnderTests;
    }

    resultFile << "Array: addAt, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << endl;
    resultFile << "Array: removeAt, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << endl;

    resultFile.close();
}

void AutomaticTests::listTest()
{
    DoublyLinkedList* systemUnderTests;

    int dataNumber = this->getSelected("Enter number of data");
    int repeats = this->getSelected("Enter number of repeats");
    int maxDataSize = this->getSelected("Enter maximum data size");

    if (dataNumber < 10 && maxDataSize < 10)
    {
        cout << "Invalid initial data" << endl;
        return;
    }

    ofstream resultFile(this->resultsPath + "list/" + to_string(dataNumber) + "-results.txt");

    vector<int> addResults;
    addResults.reserve(dataNumber);
    vector<int> removeResults;
    removeResults.reserve(dataNumber);
    vector<int> searchResults;
    searchResults.reserve(dataNumber);
    int valueToAdd;
    int valueToSearch = -1;

    for (int i = 0; i < repeats; i++)
    {
        systemUnderTests = new DoublyLinkedList();

        for (int i = 0; i < dataNumber - 1; i++)
        {
            valueToAdd = rand() % (maxDataSize + 1);
            systemUnderTests->addFront(valueToAdd);
            if (i == dataNumber / 2)
            {
                valueToSearch = valueToAdd;
            }
        }

        this->stopwatch->start();
        systemUnderTests->addFront(rand() % (maxDataSize + 1));
        this->stopwatch->stop();
        addResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->contains(valueToSearch);
        this->stopwatch->stop();
        searchResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->removeFront();
        this->stopwatch->stop();
        removeResults.push_back(this->stopwatch->getTime());

        delete systemUnderTests;
    }

    resultFile << "List: contains, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(searchResults.begin(), searchResults.end(), 0) / searchResults.size()) << endl;
    resultFile << "List: addFront, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << endl;
    resultFile << "List: removeFront, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << endl;

    addResults.clear();
    removeResults.clear();
    searchResults.clear();

    for (int i = 0; i < repeats; i++)
    {
        systemUnderTests = new DoublyLinkedList();

        for (int i = 0; i < dataNumber - 1; i++)
        {
            systemUnderTests->addFront(rand() % (maxDataSize + 1));
        }

        this->stopwatch->start();
        systemUnderTests->addEnd(rand() % (maxDataSize + 1));
        this->stopwatch->stop();
        addResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->removeEnd();
        this->stopwatch->stop();
        removeResults.push_back(this->stopwatch->getTime());

        delete systemUnderTests;
    }

    resultFile << "List: addEnd, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << endl;
    resultFile << "List: removeEnd, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << endl;

    addResults.clear();
    removeResults.clear();

    for (int i = 0; i < repeats; i++)
    {
        systemUnderTests = new DoublyLinkedList();

        for (int i = 0; i < dataNumber - 1; i++)
        {
            systemUnderTests->addFront(rand() % (maxDataSize + 1));
        }

        this->stopwatch->start();
        systemUnderTests->addAt(rand() % systemUnderTests->getSize(), rand() % (maxDataSize + 1));
        this->stopwatch->stop();
        addResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->removeAt(rand() % systemUnderTests->getSize());
        this->stopwatch->stop();
        removeResults.push_back(this->stopwatch->getTime());

        delete systemUnderTests;
    }

    resultFile << "List: addAt, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << endl;
    resultFile << "List: removeAt, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << endl;

    resultFile.close();
}



void AutomaticTests::heapTest()
{
    Heap* systemUnderTests;

    int dataNumber = this->getSelected("Enter number of data");
    int repeats = this->getSelected("Enter number of repeats");
    int maxDataSize = this->getSelected("Enter maximum data size");

    if (dataNumber < 10 && maxDataSize < 10)
    {
        cout << "Invalid initial data" << endl;
        return;
    }

    ofstream resultFile(this->resultsPath + "heap/" + to_string(dataNumber) + "-results.txt");

    vector<int> addResults;
    addResults.reserve(dataNumber);
    vector<int> removeResults;
    removeResults.reserve(dataNumber);
    vector<int> searchResults;
    searchResults.reserve(dataNumber);
    int valueToAdd;
    int valueToSearch = -1;

    for (int i = 0; i < repeats; i++)
    {
        systemUnderTests = new Heap();

        for (int i = 0; i < dataNumber - 1; i++)
        {
            valueToAdd = rand() % (maxDataSize + 1);
            systemUnderTests->add(valueToAdd);
            if (i == dataNumber / 2)
            {
                valueToSearch = valueToAdd;
            }
        }

        this->stopwatch->start();
        systemUnderTests->add(rand() % (maxDataSize + 1));
        this->stopwatch->stop();
        addResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->contains(valueToSearch);
        this->stopwatch->stop();
        searchResults.push_back(this->stopwatch->getTime());

        int varToRemove = rand() % (maxDataSize + 1);
        this->stopwatch->start();
        systemUnderTests->remove(varToRemove);
        this->stopwatch->stop();
        removeResults.push_back(this->stopwatch->getTime());

        delete systemUnderTests;
    }

    resultFile << "Heap: contains, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(searchResults.begin(), searchResults.end(), 0) / searchResults.size()) << endl;
    resultFile << "Heap: add, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << endl;
    resultFile << "Heap: removeRoot, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << endl;

    resultFile.close();
}



void AutomaticTests::treeTest()
{
    Tree* systemUnderTests;

    int dataNumber = this->getSelected("Enter number of data");
    int repeats = this->getSelected("Enter number of repeats");
    int maxDataSize = this->getSelected("Enter maximum data size");

    if (dataNumber < 10 && maxDataSize < 10)
    {
        cout << "Invalid initial data" << endl;
        return;
    }

    ofstream resultFile(this->resultsPath + "tree/" + to_string(dataNumber) + "-results.txt");

    vector<int> addResults;
    addResults.reserve(dataNumber);
    vector<int> removeResults;
    removeResults.reserve(dataNumber);
    vector<int> searchResults;
    searchResults.reserve(dataNumber);
    int valueToAdd;
    int valueToSearch = -1;

    for (int i = 0; i < repeats; i++)
    {
        systemUnderTests = new Tree();

        for (int i = 0; i < dataNumber - 1; i++)
        {
            valueToAdd = rand() % (maxDataSize + 1);
            systemUnderTests->add(valueToAdd);
            if (i == dataNumber / 2)
            {
                valueToSearch = valueToAdd;
            }
        }

        this->stopwatch->start();
        systemUnderTests->add(rand() % (maxDataSize + 1));
        this->stopwatch->stop();
        addResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->contains(valueToSearch);
        this->stopwatch->stop();
        searchResults.push_back(this->stopwatch->getTime());

        this->stopwatch->start();
        systemUnderTests->remove(valueToSearch);
        this->stopwatch->stop();
        removeResults.push_back(this->stopwatch->getTime());

        delete systemUnderTests;
    }

    resultFile << "Tree: contains, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(searchResults.begin(), searchResults.end(), 0) / searchResults.size()) << endl;
    resultFile << "Tree: add, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << endl;
    resultFile << "Tree: remove, data range: 0 - " << maxDataSize << ", repeats: " << repeats
               << ", average time: " << (accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << endl;

    resultFile.close();
}