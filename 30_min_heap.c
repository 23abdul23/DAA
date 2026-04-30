/*
Basic Question: Build a Min-Heap with insert, delete, heapify, and find-min operations.
Topic: Min-Heap
Idea Used: Store heap elements in an array and maintain the heap property using upward and downward adjustments.
*/
//IIT2024243

//Abdul Azeem 

/* Time Complexity: 
Build Heap: O(n)
Insert: O(log n)
Delete/Extract Min: O(log n)
Find Min: O(1)
Space Complexity: O(n) to store the heap
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// heap
typedef struct {
    int array[MAX_SIZE];
    int size;
} MinHeap;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child exists and is smaller than root
    if (left < heap->size && heap->array[left] < heap->array[smallest])
        smallest = left;

    // Check if right child exists and is smaller than the current smallest
    if (right < heap->size && heap->array[right] < heap->array[smallest])
        smallest = right;

    // If smallest is not root, swap and recursively heapify the affected subtree
    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

void buildMinHeap(MinHeap *heap) {
    // Last non-leaf node index = (size / 2) - 1
    for (int i = (heap->size / 2) - 1; i >= 0; i--) {
        minHeapify(heap, i);
    }
}

// Add element
void insert(MinHeap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap Overflow\n");
        return;
    }

    // Insert new key at the end
    int i = heap->size;
    heap->array[i] = value;
    heap->size++;

    // if sift-up violated
    while (i != 0 && heap->array[(i - 1) / 2] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("Inserted %d\n", value);
}

// find min
int getMin(MinHeap *heap) {
    if (heap->size <= 0) return -1;
    return heap->array[0];
}

// remove element
int extractMin(MinHeap *heap) {
    if (heap->size <= 0) return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    // store min value
    int root = heap->array[0];

    // replace root w last element
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    //sift down
    minHeapify(heap, 0);

    return root;
}

// print heap
void printHeap(MinHeap *heap) {
    printf("Current Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main() {
    MinHeap heap;
    heap.size = 0;

    // input data
    int inputData[] = {50, 10, 20, 30, 5, 90, 80, 100, 85};
    int n = sizeof(inputData) / sizeof(inputData[0]);

    printf("--- Building Heap from Array ---\n");
    // copy to heap
    for(int i = 0; i < n; i++) {
        heap.array[i] = inputData[i];
    }
    heap.size = n;

    buildMinHeap(&heap);
    printHeap(&heap);

    printf("\n--- Operation Demonstrations ---\n");
    printf("Minimum Element: %d\n", getMin(&heap));

    int removed = extractMin(&heap);
    printf("Removed Element (Min): %d\n", removed);
    printHeap(&heap);

    insert(&heap, 15); 
    printHeap(&heap);

    return 0;
}
