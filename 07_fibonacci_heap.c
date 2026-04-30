/*
Basic Question: Implement a Fibonacci Heap with make-heap, insert, find-minimum, and union operations.
Topic: Fibonacci Heap
Idea Used: Maintain a circular doubly linked root list with a pointer to the minimum node so merge and insertion stay efficient.
*/
//iit2024243
//abdul azeem
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


//TC only Delettion of Min element takes O(log(n)) time
//all other operations has O(1)
//

typedef struct Node {
    int key;
    int degree;
    struct Node *parent;
    struct Node *child;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct FibHeap {
    Node *min;
    int n;
} FibHeap;



Node* createNode(int key) {
    Node *x = (Node*)malloc(sizeof(Node));
    x->key = key;
    x->degree = 0;
    x->parent = NULL;
    x->child = NULL;
    x->left = x;
    x->right = x;
    return x;
}



FibHeap* makeHeap() {
    FibHeap *H = (FibHeap*)malloc(sizeof(FibHeap));
    H->min = NULL;
    H->n = 0;
    return H;
}



void insert(FibHeap *H, int key) {
    Node *x = createNode(key);

    if (H->min == NULL) {
        H->min = x;
    } else {
        
        x->right = H->min->right;
        x->left = H->min;
        H->min->right->left = x;
        H->min->right = x;

        if (x->key < H->min->key)
            H->min = x;
    }
    H->n++;
}



int findMin(FibHeap *H) {
    if (H->min == NULL)
        return INT_MAX;
    return H->min->key;
}



FibHeap* unionHeap(FibHeap *H1, FibHeap *H2) {
    FibHeap *H = makeHeap();

    H->min = H1->min;

    if (H->min == NULL ||
       (H2->min != NULL && H2->min->key < H1->min->key))
        H->min = H2->min;

    if (H1->min != NULL && H2->min != NULL) {
      
        Node *temp = H1->min->right;
        H1->min->right = H2->min->right;
        H2->min->right->left = H1->min;
        H2->min->right = temp;
        temp->left = H2->min;
    }

    H->n = H1->n + H2->n;
    return H;
}



int main() {
    FibHeap *H1 = makeHeap();
    FibHeap *H2 = makeHeap();

    insert(H1, 10);
    insert(H1, 3);
    insert(H1, 15);

    insert(H2, 7);
    insert(H2, 1);

    FibHeap *H = unionHeap(H1, H2);

    printf("Minimum key: %d\n", findMin(H));

    return 0;
}
