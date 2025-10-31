#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Sequential Search (Iterative)
int sequentialSearch_iterativeMethod(const vector<long long>& arr, long long target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Sequential Search (Recursive)
int sequentialSearch_Recursive(const vector<long long>& arr, int i, long long target) {
    if (i == arr.size()) {
        return -1; // not found
    }
    if (arr[i] == target) {
        return i;
    }
    return sequentialSearch_Recursive(arr, i + 1, target);
}

// Binary Search (Iterative)
int binarySearch_iterativeMethod(vector<long long> arr, long long target) {
    sort(arr.begin(), arr.end()); // make sure array is sorted
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// Binary Search (Recursive)
int binarySearch_Recursive(const vector<long long>& arr, int l, int r, long long target) {
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch_Recursive(arr, mid + 1, r, target);
    else
        return binarySearch_Recursive(arr, l, mid - 1, target);
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    vector<long long> array(size);
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    long long target;
    cout << "Enter the element you want to find: ";
    cin >> target;

    int choice;
    cout << "\nChoose a search method:\n";
    cout << "1. Sequential Search (Iterative)\n";
    cout << "2. Sequential Search (Recursive)\n";
    cout << "3. Binary Search (Iterative)\n";
    cout << "4. Binary Search (Recursive)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int result = -1;

    switch (choice) {
        case 1:
            result = sequentialSearch_iterativeMethod(array, target);
            break;
        case 2:
            result = sequentialSearch_Recursive(array, 0, target);
            break;
        case 3:
            result = binarySearch_iterativeMethod(array, target);
            break;
        case 4:
            sort(array.begin(), array.end()); // ensure sorted before recursive binary search
            result = binarySearch_Recursive(array, 0, size - 1, target);
            break;
        default:
            cout << "Invalid choice!\n";
            return 0;
    }

    if (result != -1)
        cout << "Element " << target << " found at index " << result << endl;
    else
        cout << "Element " << target << " not found.\n";

    return 0;
}
