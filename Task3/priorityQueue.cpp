#include <iostream>
#include "heap.h"
using namespace std;

class Node
{
public:
    int value;
    int priority;

    Node(int v = 0, int p = 0) : value(v), priority(p) {}

    // Comparison operators for heap
    bool operator>(const Node &other) const
    {
        if (priority != other.priority)
            return priority > other.priority;
        return value > other.value;
    }

    bool operator<(const Node &other) const
    {
        if (priority != other.priority)
            return priority < other.priority;
        return value < other.value;
    }

    // To print Node objects
    friend ostream &operator<<(ostream &os, const Node &n)
    {
        os << "(" << n.value << ", p=" << n.priority << ")";
        return os;
    }
};

class PriorityQueue
{
private:
    Heap<Node> heap;

public:
    // Constructor: default to max-priority queue
    PriorityQueue(bool isMax = true) : heap(isMax) {}

    // Insert - enqueue
    void enqueue(int value, int priority)
    {
        Node node(value, priority);
        heap.insert(node);
    }

    // Remove top priority - dequeue
    Node dequeue()
    {
        return heap.extractRoot();
    }

    bool isEmpty() const
    {
        return heap.isEmpty();
    }

    void printQueue()
    {
        heap.printHeap();
    }
};
