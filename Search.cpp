#include <iostream>
#include <algorithm> 
using namespace std;

// Sequential Search (Iterative)
int sequentialSearch_iterativeMethod(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Sequential Search (Recursive)
int sequentialSearch_Recursive(int arr[], int n, int target, int i) {
    if (i == n) {
        return -1; // not found
    }
    if (arr[i] == target) {
        return i;
    }
    return sequentialSearch_Recursive(arr, n, target, i + 1);
}
// Binary Search (Iterative)
int binarySearch_iterativeMethod(int arr[], int n, int target) {
    sort(arr, arr + n); // make sure array is sorted
    int l = 0, r = n - 1;
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
int binarySearch_Recursive(int arr[], int l, int r, int target) {
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

    int array[size];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << "Enter the element you want to find: ";
    int target;
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
            result = sequentialSearch_iterativeMethod(array, size, target);
            break;
        case 2:
            result = sequentialSearch_Recursive(array, size, target, 0);
            break;
        case 3:
            result = binarySearch_iterativeMethod(array, size, target);
            break;
        case 4:
            sort(array, array + size); // ensure sorted before recursive binary search
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
