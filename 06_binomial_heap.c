/*
Basic Question: Implement a Binomial Heap with make-heap, insert, find-minimum, and union operations.
Topic: Binomial Heap
Idea Used: Represent the heap as a forest of binomial trees and merge root lists by degree while linking equal-degree trees.
*/
//iit2024243
//
////abdul azeem ansari 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//read that from Geek4Geeks
struct Node {
    int key;
    int degree;
    struct Node *parent;
    struct Node *child;
    struct Node *sibling;
};


//creates a Node 
//TC: O(1)
//
struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->degree = 0;
    node->parent = NULL;
    node->child = NULL;
    node->sibling = NULL;
    return node;
}



//mreges two trees
//TC: O(log(n))
struct Node* mergeRootLists(struct Node* h1, struct Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    struct Node* head = NULL;
    struct Node** pos = &head;

    while (h1 && h2) {
        if (h1->degree <= h2->degree) {
            *pos = h1;
            h1 = h1->sibling;
        } else {
            *pos = h2;
            h2 = h2->sibling;
        }
        pos = &((*pos)->sibling);
    }

    *pos = (h1) ? h1 : h2;
    return head;
}



void linkTrees(struct Node* y, struct Node* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree++;
}

//union also have the same
//TC: O(log(n))
//
struct Node* unionHeaps(struct Node* h1, struct Node* h2) {
    struct Node* head = mergeRootLists(h1, h2);
    if (!head) return NULL;

    struct Node *prev = NULL, *curr = head, *next = curr->sibling;

    while (next) {
        if (curr->degree != next->degree ||
           (next->sibling && next->sibling->degree == curr->degree)) {
            prev = curr;
            curr = next;
        } else {
            if (curr->key <= next->key) {
                curr->sibling = next->sibling;
                linkTrees(next, curr);
            } else {
                if (!prev)
                    head = next;
                else
                    prev->sibling = next;
                linkTrees(curr, next);
                curr = next;
            }
        }
        next = curr->sibling;
    }
    return head;
}

//TC: O(1) + O(log(n))
struct Node* insert(struct Node* heap, int key) {
    struct Node* node = createNode(key);
    return unionHeaps(heap, node);
}


//TC: O(log(n))
//
int findMin(struct Node* heap) {
    int min = INT_MAX;
    while (heap) {
        if (heap->key < min)
            min = heap->key;
        heap = heap->sibling;
    }
    return min;
}



int main() {
    struct Node* heap = NULL;

    heap = insert(heap, 10);
    heap = insert(heap, 3);
    heap = insert(heap, 7);
    heap = insert(heap, 1);

    printf("Minimum: %d\n", findMin(heap));

    return 0;
}
