
#include "list.h"
struct NODE {
	int data; //data stored in node
	struct NODE* next; //pointer to the next node in the list
	struct NODE* previous;
};

struct NODE* head = NULL;

void add(int data){

	struct NODE* n = (struct NODE*)malloc(sizeof(struct NODE)); //creating a new ndoe
        n->next = NULL;
	n->data = data;
	n->previous = NULL;

	if(head == NULL) 
	{
		head = n;
	}
	else {
		struct NODE* currentNode = head;
		while(currentNode->next != NULL) {
			currentNode = currentNode->next;
		}
		currentNode->next = n;
		n->previous = currentNode;
	}

}

void prettyPrint() {

	if( head == NULL) {
		printf("Empty list.");
	}
	else {
		struct NODE* currentNode = head;
		printf("[ ");
		while(currentNode != NULL) {

			printf("%d ", currentNode->data);
			currentNode=currentNode->next;
		}
		printf("]\n");
	}
}

struct NODE* find(int data) {
	if(head == NULL) {
		return NULL;
	}

	else {
		struct NODE* currentNode = head;
		while(currentNode != NULL) {
			if(currentNode->data == data) {
				return currentNode;
			}
			else {
				currentNode= currentNode->next;
			}
		}
		return NULL;
	}
}

BOOLEAN delete(int data) {

	struct NODE* nodeFound = find(data) ;
	if(nodeFound == NULL) {
		return FALSE;
	}

	if(nodeFound == head) {
		if(nodeFound->next != NULL) {
			head= nodeFound->next;
			nodeFound->next->previous = NULL;
		}
		else {
			head = NULL;
		}
	}
	else {
		if(nodeFound->next == NULL) {
			nodeFound->previous->next = NULL;
		}
		
		else {
			nodeFound->previous->next = nodeFound->next;
			nodeFound->next->previous = nodeFound->previous;
		}
	}

	free(nodeFound);
	return TRUE;
}

	
