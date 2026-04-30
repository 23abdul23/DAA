/*
Basic Question: Convert a weighted adjacency matrix into a weighted adjacency list.
Topic: Minimum Spanning Tree Preparation
Idea Used: Read the matrix row by row and create linked adjacency-list nodes for every non-zero edge weight.
*/
#include <stdio.h> 
#include <stdlib.h>
typedef struct Node{ 
	int idx;
	int wt;
	struct Node *adj;
	struct Node *next;
}Node;

int main(){
	int m, n;
	printf("Enter No of Nodes: n\n");
	scanf("%d", &n);
	
	int grid[n][n];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &grid[i][j]);
		}
		printf("\n");
	}

	Node *head, *HEAD;
	
	head = (Node*) malloc(sizeof(Node));

	HEAD = head;

	for (int i = 0; i < n; i++){
		Node *temp, *TEMP;
		temp = (Node*) malloc(sizeof(Node));

		TEMP = temp;

		temp->idx = i;
		temp->wt = 0;
		for (int j = 0; j < n; j++){
			if (grid[i][j] > 0){
				Node *new = (Node*) malloc(sizeof(Node));
				new->idx = j;
				new->wt = grid[i][j];
				new->adj = NULL;				
			

				temp->adj = new;
				temp = temp->adj;
			}
		}
		
		head->next = TEMP;
		head = head->next;

	}
	head->next = NULL;


	printf("\nAdjacency List:\n\n");

	Node *row = HEAD->next; 

	while (row != NULL) {
	    printf("%d", row->idx);

	    Node *curr = row->adj;

	    while (curr != NULL) {
		printf(" -> %d(%d)", curr->idx, curr->wt);
		curr = curr->adj;
	    }

	    printf("\n");
	    row = row->next;
	}
	return 0;
}
