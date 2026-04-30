/*
Basic Question: Build a dynamic array using malloc/calloc-style allocation and resize it using realloc.
Topic: Dynamic Array
Idea Used: Track current size and capacity, and double the capacity whenever the array becomes full.
*/
//IIT2024243
//
//ABDUL AZEEM ANSARI
//

#include <stdio.h>
#include <stdlib.h>

//made a structure to implemnet vector(int)
typedef struct {
    int *data;
    int maxSize;
    int currSize;
} vector;

void vector_init(vector *arr) {
    arr->data = NULL;
    arr->currSize = 0;
    arr->maxSize = 0;
}

void push_back(vector *arr, int a) {
    if (arr->currSize == arr->maxSize) {
        arr->maxSize = (arr->maxSize == 0) ? 1 : arr->maxSize * 2;
        arr->data = realloc(arr->data, sizeof(int) * arr->maxSize);
    }
    arr->data[arr->currSize++] = a;
}

int pop_back(vector *arr){
	int x = arr->data[arr->currSize-1];
	arr->currSize--;

	return x; 
}
//This approach is better as it increases the size of arr step wise, so we don;t have to allocate new space and copy existing elments to that.
int main() {
    vector arr;
    vector_init(&arr);
    
    push_back(&arr, 12);
    push_back(&arr, 16);
    push_back(&arr, 1);
    push_back(&arr, 6);
    push_back(&arr, 14);
   
    push_back(&arr, 200);

    int x = pop_back(&arr);
    //pop_back(&arr);


    printf("Pop: %d\n",x);

    for (int i = 0; i < arr.currSize; i++) {
        printf("%d ", arr.data[i]);
    }

    free(arr.data);
    return 0;
}
