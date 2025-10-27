#include <iostream>
#include <vector>
#include "priorityQueue.cpp"
#include "heapSort.cpp"
using namespace std;

int main()
{
    cout << "========== Heap ==========\n\n";
    Heap<int> heap(true); 
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

    cout << "Dequeued (highest priority): " << pq.dequeue()<<endl;
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
    cout <<"\n"<<endl;

    return 0;
}