#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int data;
	struct Node *next;
};

//travsersal of a linked list
void printList(struct Node *n){
	//we pass the head of the list to this function
	struct Node *ptr = n;

	//cycle through the list
	while(ptr != NULL){
		printf("data = %d \n",ptr->data);

		//increment node to the next node
		ptr = ptr->next;
	}
}

//Complexity = O(1)!
void push(struct Node **ref, int data){
	//create a node
	struct Node *new_head = malloc(sizeof(struct Node));

	new_head->data = data;

	//make the next member of new_head point to ref
	new_head->next = *ref;

	//make sure our head points to new_head;
	*ref = new_head;
}

//Complexity = O(1)
void insertAfter(struct Node *prev_node, int data){

	//error checking! If prev is NULL, exit
	if(prev_node == NULL){
		return;
	}

	//create a node
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = data;

	//make our new_node's next member point to the next of the prev node
	new_node->next = prev_node->next;

	//make the next node of prev, to be our new node
	prev_node->next = new_node;
}

//Complexity = O(N), where N is the # of nodes in the list
//Can be updated to O(1) by using a pointer that points to the tail

void append(struct Node **head, int data){

	//first lets make the new node that will point to the end
	struct Node *new_end = malloc(sizeof(struct Node));
	new_end->data = data;
	//making it point to NULL, sign that is indeed our new ending node
	new_end->next = NULL;

	//now we need the old last
	struct Node *old_last = *head;

	//now we cycle this old_last to make it point to the end
	while(old_last->next != NULL){
		old_last = old_last->next;
	}

	//make the old last point to the end.
	old_last->next = new_end;
}

//Delete a node given a key
//3 step process
//1. Find the PREVIOUS node of the node to be deleted
//2. Change the next of previous to the next of the deleted Node
//3. Free the deleted node

//Complexit, O(N)
void deleteNode(struct Node **head, int key){
	struct Node *deleted = *head;

	//this node will hold the node previous to the node that must be deleted
	struct Node *prev_to_deleted;

	while(deleted->data != key){

		//holds the previous node
		prev_to_deleted = deleted;

		deleted = deleted->next;
	}

	//at this point we have reached the desired node

	//have the previous node to point to the next of deleted node
	prev_to_deleted->next = deleted->next;

	//free the deleted node
	free(deleted);
}

int main(int argc, char **argv){

	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	// allocate 3 nodes in the heap
	head  = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third  = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1; //assign data in first node
	head->next = second; // Link first node with second

	second->data = 2; //assign data to second node
	second->next = third;

	third->data = 3; //assign data to third node
	third->next = NULL;

	push(&head, 4);

	insertAfter(head->next, 5);
	append(&head, 6);
	deleteNode(&head, 3);
	printList(head);

	return(0);
}
