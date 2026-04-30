/*
Basic Question: Implement Heap Sort using the Min-Heap built earlier.
Topic: Heap Sort
Idea Used: Build a min-heap, then repeatedly move the root and heapify the reduced heap to produce sorted order.
*/
//IIT2024243

//Abdul Azeem 

/* Time Complexity: O(n log n)
Space Complexity: O(1) (In-place sorting)
Note: Sorting with Min-Heap results in a Descending order array.
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min heap
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// heap sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);

        minHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array (Descending via Min-Heap): ");
    printArray(arr, n);

    return 0;
}
