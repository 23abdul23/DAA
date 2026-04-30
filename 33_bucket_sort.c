/*
Basic Question: Sort uniformly distributed real numbers using Bucket Sort and study its behavior on different distributions.
Topic: Bucket Sort
Idea Used: Distribute elements into buckets by range, sort each bucket individually, and concatenate the results.
*/
//IIT2024243

//Abdul Azeem 

/* Time Complexity: 
Uniform Distribution: Average O(n + k)
Clustered Distribution: Worst O(n^2)
Space Complexity: O(n + k)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

// Helper
struct Node* InsertionSort(struct Node* list) {
    if (!list || !list->next) return list;
    struct Node* sorted = NULL;
    struct Node* curr = list;
    while (curr) {
        struct Node* next = curr->next;
        if (!sorted || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            struct Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    return sorted;
}

void BucketSort(float arr[], int n) {
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    //put elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i]; 
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = buckets[idx];
        buckets[idx] = newNode;
    }

    // sort buckets and merge
    int index = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = InsertionSort(buckets[i]);
        struct Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); // Free memory
        }
    }
    free(buckets);
}

int main() {
    float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);
    BucketSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);
    return 0;
}
