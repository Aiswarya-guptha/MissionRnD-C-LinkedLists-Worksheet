/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	if (N < 0)	N = N*-1;
	struct node *root =  (struct node *)malloc(sizeof(struct node));
	if (N == 0){
		//if zero
		root->num = 0;
		root->next = NULL;
		return root;
	}
	root = NULL;
	while (N > 0){
		//if num
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode->num = N % 10;
		N = N / 10;
		newNode->next = root;
		root = newNode;
	}
	return root;
}