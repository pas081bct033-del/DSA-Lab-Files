#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {   // Step 2: start from 2nd element
        int key = arr[i];           // current element
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];    // shift right
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int arr[] = {34, 12, 25, 16, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    insertionSort(arr, n);
    cout << "Sorted Array:   ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
