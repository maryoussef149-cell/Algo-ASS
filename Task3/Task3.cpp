#include <iostream>
#include <vector>
using namespace std;

//________________________________________________________________________________
//Task 3.1 - Heap Sort

template <typename T>
class Heap
{
private:
    vector<T> heap;
    bool isMaxHeap; // To control we need min or max heap

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    //Used After insertion
    void heapifyUp(int i)
    {
        while (i > 0)
        {
            bool validSwap = isMaxHeap ? (heap[i] > heap[parent(i)]) : (heap[i] < heap[parent(i)]);
            if (validSwap)
            {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
            else
                break;
        }
    }

    //Used After deletion
    void heapifyDown(int i)
    {
        int l = left(i), r = right(i), target = i;
        if (isMaxHeap)
        {
            if (l < heap.size() && heap[l] > heap[target])
                target = l;
            if (r < heap.size() && heap[r] > heap[target])
                target = r;
        }
        else
        {
            if (l < heap.size() && heap[l] < heap[target])
                target = l;
            if (r < heap.size() && heap[r] < heap[target])
                target = r;
        }
        if (target != i)
        {
            swap(heap[i], heap[target]);
            heapifyDown(target);
        }
    }

public:
    Heap(bool isMax = true) : isMaxHeap(isMax) {}

    void insert(T value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T extractRoot()
    {
        if (heap.empty()) {
        cout << "Heap is empty!" << endl;
        return T{};
        }

        T root = heap[0];
        heap[0] = heap.back();
        heap.pop_back(); // remove last element
        if (!heap.empty())
            heapifyDown(0);
        return root;
    }

    void printHeap() const
    {
        for (auto x : heap)
            cout << x << " ";
        cout << endl;
    }

    bool isEmpty() const { return heap.empty(); }
};

//________________________________________________________________________________
//Task 3.2 - Priority Queue

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

    //cout operator To print Node 
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

//________________________________________________________________________________
//Task 3.3 - Heap Sort

void heapSort(vector<int> &arr)
{
    Heap<int> heap(true);
    for (int x : arr)
        heap.insert(x);
    for (int i = arr.size() - 1; i >= 0; --i)
        arr[i] = heap.extractRoot();
}

//_____________________
//Main
int main()
{
    cout << "========== Heap ==========\n\n";
    Heap<int> heap(true); // true --> max heap
    heap.insert(10);
    heap.insert(4);
    heap.insert(15);
    heap.insert(7);

    cout << "Heap elements: ";
    heap.printHeap();

    cout << "Extracted root: " << heap.extractRoot() << endl;
    cout << "Heap after extraction: ";
    heap.printHeap();

    cout << "\n========== Priority Queue ==========\n\n";
    PriorityQueue pq(true);
    pq.enqueue(100, 1);
    pq.enqueue(200, 3);
    pq.enqueue(150, 2);

    cout << "Queue elements: ";
    pq.printQueue();

    cout << "Dequeued (highest priority): " << pq.dequeue() << endl;
    cout << "Queue now: ";
    pq.printQueue();

    cout << "\n========== Heap Sort ==========\n\n";
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    heapSort(arr);

    cout << "Array after heap sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n"
         << endl;

    return 0;
}