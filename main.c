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

//Length of the linked list, ITERATIVELY!
int length_of_list(struct Node *n){
	int count = 0;
	struct Node *ptr = n;

	while(ptr != NULL){
		count++;
		ptr = ptr->next;
	}

	return(count);
}

//Length of the list, RECURSIVELY!
int length_recursive(struct Node *head){
	//base case
	if(head == NULL)
		return (0);
	else
		return (1+length_recursive(head->next));
}

//searching a list for a given node
//iterative search
bool search(struct Node *head, int key){

	//initialize a node called current
	struct Node *current = head;

	//while current does not equal NULL
	while(current != NULL){

		//check if the key of current matches our key
		if(current->data == key){

			//equal, found our node of interest
			return(true);
		}

		//if not, increment along the list
		current = current->next;
	}
	return(false);
}

//search using recursion
bool search_R(struct Node *head, int key){

	//if head is the NULL, return false
	//this is our base case
	if(head == NULL)
		return(false);

	//if same as key, return true
	if(head->data == key)
		return(true);

	//else update
	else
		return(search_R(head->next, key));
}

int get_nth_node(struct Node *ptr, int index){

	//first check if the index is within bounds
	if(index > length_of_list(ptr)-1){
		return(-1);
	}

	int count = 0;
	while(ptr != NULL){
		if(count == index){
			return(ptr->data);
		}
		count++;
		ptr = ptr->next;
	}
	return(-1);
}

void printMiddle(struct Node *ptr){
	struct Node *fast_ptr = ptr;
	struct Node *slow_ptr = ptr;

	while(fast_ptr != NULL && fast_ptr->next != NULL){
		//we update our fast_ptr by 2 so it reaches the end of the list before
		//the slow_ptr

		fast_ptr = fast_ptr->next->next;

		//we update the slow_ptr by 1
		//by the time the fast_ptr reaches the end, the slow will have reached the middle
		slow_ptr = slow_ptr->next;
	}

	//reached the middle
	printf("middle value of the middle = %d \n",slow_ptr->data);
}

bool detectLoop(struct Node *ptr){
	struct Node *slow_ptr;
	struct Node *fast_ptr;

	fast_ptr = ptr;
	slow_ptr = ptr;

	while(slow_ptr && fast_ptr && fast_ptr->next){
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

		if(slow_ptr == fast_ptr){
			return(true);
		}
	}
	return(false);
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
	printf("length of the list = %d \n",length_of_list(head));
	printf("length of the list recursively = %d \n",length_recursive(head));
	bool node_wanted = search(head, 10);
	printf("node_wanted = %d \n",node_wanted);
	int x = get_nth_node(head, 50);
	printf("x = %d \n",x);
	printMiddle(head);

    head->next->next->next->next = head;
    printf("Loop status = %d \n", detectLoop(head));

	return(0);
}
