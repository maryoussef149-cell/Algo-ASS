#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Heap
{
private:
    vector<T> heap;
    bool isMaxHeap; // To control we needed min or max heap

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    //After insertion
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

    //After deletion
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
        if (heap.empty())
            cout<<"Empty Heap !"<<endl;

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
