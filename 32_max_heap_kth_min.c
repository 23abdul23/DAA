/*
Basic Question: Build a Max-Heap for the given elements and find the Kth minimum element.
Topic: Max-Heap
Idea Used: Heapify the array into a max-heap and use repeated extraction logic based on heap order statistics.
*/
//IIT2024243

//Abdul Azeem 

/* Time Complexity: 
Build Max-Heap: O(n)
Find Kth Min: O((n-k+1) log n) by extracting Max
Space Complexity: O(n)
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// max heap
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// build max heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// heap sort
void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;

    printf("Original Elements: 50, 10, 20, 30, 5, 90, 80, 100, 85\n");
    
    buildMaxHeap(arr, n);
    printf("Max-Heap array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    printf("\n\nEnter the value of K to find Kth minimum: ");
    scanf("%d", &k);

    if (k > 0 && k <= n) {
        heapSort(arr, n);
        printf("The %d-th minimum element is: %d\n", k, arr[k - 1]);
    } else {
        printf("Invalid K! Please enter a value between 1 and %d.\n", n);
    }

    return 0;
}
