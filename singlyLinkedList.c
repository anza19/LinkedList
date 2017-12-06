/*
 * singlyLinkedList.c
 *
 *  Created on: Dec 06, 2017
 *      Author: Anza
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*This is the basis for our linked list, the link struct
 * it can be thought of self-referential because it contains
 * a pointer to the next struct in the list
 */
struct link
{
	int key;
	int data;
	struct link *next;
};

/*Our initial links*/
struct link *head = NULL;
struct link *current = NULL;


/*Our singly Linked list functions*/

/*void printList()
 * This function prints the contents of our linked list
 */
void printList(){
	/*current link is set to head*/
	struct link *current = head;
	/*iteration while link not null*/
	while(current!=NULL){
		printf("KEY:%d ********** VALUE:%d\n",current->key,current->data);
		/*incrementing to the next link in the list*/
		current = current->next;
	}
}

/*void insertFirst(int key, int data)
 * This function inserts a new link at the front
 */
void insertFirst(int key, int data){
	/*create a link dynamically*/
	struct link *current = malloc(sizeof(struct link));
	current->key = key;
	current->data = data;

	/*setting the next link as the old head*/
	current->next = head;
	head = current;
}
/*struct *link deleteFirst()
 * This function deletes the first link in the list
 */
struct link* deleteFirst(){
	struct link *temp = head;
	head = head->next;
	return temp;
}

/*bool isEmpty()
 * Just to check if linked list empty
 */
bool isEmpty(){
	return(head == NULL);
}

/*int length()
 * Gets us the size of the linked list
 */
int length(){
	struct link *current = head;
	int length=0;
	while(current!=NULL){
		length++;
		current = current->next;
	}
	return length;
}

/*struct link* find(int key)
 * This function is used to find a particular link
 * in the list
 */
struct link* find(int key){
	/*points to head*/
	struct link *current = head;
	/*if the list is empty, just return NULL*/
	if(isEmpty()){
		return NULL;
	}
	/*will continue iteration, until keys match*/
	while(current->key!=key){
		/*we have reached the end, unsuccessfully, return NULL*/
		if(current->next == NULL){
			return NULL;
		}else{
			/*incrementation*/
			current = current->next;
		}
	}
	return current;
}

/*struct link* delete(int key)
 * Deletes a link based on a key
 */
struct link* delete(int key){
	struct link *current = head;
	struct link *prev = NULL;
	if(isEmpty()){
		return NULL;
	}
	while(current->key!=key){
		if(current->next == NULL){
			return NULL;
		}else{
			prev = current;
			current = current->next;
		}
	}
	if(current == head){
		head = head->next;
	}else{
		prev->next = current->next;
	}
	return current;
}
int main(){
	for(int i=0;i<10;i++){
		insertFirst(i,i*10);
	}
	printList();
	int size = length();
	printf("SIZE = %d \n",size);
	struct link *x = find(5);
	if(x->key == 50){
		printf("WE FOUND THE KEY! OUR FIND FUNCTION WORKS!\n");
	}else{
		printf("DID NOT FIND KEY.\n");
	}
	struct link *del = delete(5);
	if(del->key == 5){
		printf("WE FOUND THE KEY! OUR FIND FUNCTION WORKS!\n");
	}else{
		printf("DID NOT FIND KEY.\n");
	}
	return 0;
}
