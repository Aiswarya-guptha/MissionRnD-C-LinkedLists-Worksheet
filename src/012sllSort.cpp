/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){

	//using three head pointers at 0,1,2 and insert respected values at it's head
	//initialization
	struct node *copy = (struct node *)malloc(sizeof(struct node*));
	struct node *head0 = (struct node *)malloc(sizeof(struct node*));
	struct node *head1 = (struct node *)malloc(sizeof(struct node*));
	struct node *head2 = (struct node *)malloc(sizeof(struct node*));
	copy = head;
	head0 = NULL;
	head1 = NULL;
	head2 = NULL;
	int flag = 0;


	while (head != NULL){

		//if it has 0 as data 
		if (head->data == 0){
			if (head0 == NULL){
				head0 = head;
				//takes all the continous 0's
				for (;head!=NULL&& head->data == 0; head = head->next){
					head1=head;
				}
				//initalize the heads to end of 0's
				head1->next = NULL;
				head2=head1;
			}
			else{
				//insert before head0
				struct node *nextNode = head->next;
				head->next = head0;
				head0 = head;
				if (nextNode == NULL)	break;
				head = nextNode;
			}
		}

		//if it has 1 as data 
		else if (head->data == 1){
			if (head1 == NULL){
				//initalize the heads
				head0 = head;
				//takes all the continous 1's
				for (; head != NULL&& head->data == 1; head = head->next){
					head1 = head;
				}
				head1->next = NULL;
				head2 = head1;
			}
			else if (head1->data == -1){
				//if node created for 1
				head1->data = 1;
				head = head->next;
			}
			else{
				//insert after head1
				struct node *next = head->next;
				head->next = head1->next;
				head1->next = head;
				head = next;
				if (flag == 0){
					head2 = head2->next;
					flag = 1;
				}
			}
		}

		//if it has 2 as data 
		else if (head->data == 2){
			if (head1 == NULL){
				//create node for 1 
				struct node *next = (struct node *)malloc(sizeof(struct node*));
				next->data = -1;
				//initialize heads
				next->next = head;
				head0 = next;
				head1 = next;
				//takes all the continous 2's
				for (; head != NULL&& head->data == 2; head = head->next){
					head2 = head;
				}
				head2->next = NULL;
			}
			else{
				//insert after head2
				struct node *next = head->next;
				head->next = head2->next;
				head2->next = head;
				head = next;
			}
		}

	}


	//address of head can not be change so copyinyiny everything in head
	struct node *cop = (struct node *)malloc(sizeof(struct node*));
	struct node *copycop = (struct node *)malloc(sizeof(struct node*));
	copycop = cop;
	struct node *copp = (struct node *)malloc(sizeof(struct node*));
	copp = copy;
	if (copy->data!=0){
		head = copy;
		for (; copy != NULL; copy = copy->next, cop = cop->next){
			cop->data = copy->data;
			if (copy->next == NULL){
				cop->next = NULL;
				break;
			}
			cop->next =(struct node *)malloc(sizeof(struct node*));
		}
		for (; &head0 != &copp; head0 = head0->next, head = head->next){
			head->data = head0->data;
			if (&head0->next->next == &copp->next){
				head->next = copycop;
				break;
			}
			head->next = (struct node *)malloc(sizeof(struct node*));
		}
	}
	
	
}