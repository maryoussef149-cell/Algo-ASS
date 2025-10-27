#include "heap.h"
#include <vector>
using namespace std;

void heapSort(vector<int> &arr)
{
    Heap<int> heap(true);
    for (int x : arr)
        heap.insert(x);
    for (int i = arr.size() - 1; i >= 0; --i)
        arr[i] = heap.extractRoot();
}
