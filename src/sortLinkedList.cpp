/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/
#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	int swap=1,temp;
	if (head == NULL || head->next == NULL)
		return head;
	struct node *headRef;
	
	for (struct node *endRef = NULL; swap == 1;endRef=headRef){
		for (swap = 0, headRef = head; headRef->next != endRef; headRef = headRef->next){
			if (headRef->num > headRef->next->num){
				temp = headRef->num;
				headRef->num = headRef->next->num;
				headRef->next->num = temp;
				swap = 1;
			}
		}


	}
	return head;
}