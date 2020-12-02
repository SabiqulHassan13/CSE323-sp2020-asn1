// CSE323 assignemnt part

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// define the structure for Singly Linked List
struct Node {
	int data;
	struct Node *next;
};

// define some variables

struct Node *headNode = NULL;
struct Node *currentNode = NULL;



// Necessary functions

void insertAtFirst(int value){
	// create a tempNode variable
	struct Node *tempNode = (struct Node*) malloc(sizeof(struct Node)); 
	
	// assign value to tempNode
	tempNode->data = value;
	
	// point and connect tempNode into list
	tempNode->next = headNode;
	
	// update the headNode of list
	headNode = tempNode;
}

void deleteFromFirst(){
	// take a tempNode reference variable and point to headNode
	struct Node *tempNode = NULL; 
	
	if(headNode == NULL) {
		printf("Nothing to delete. Linked List is empty");
	}
	else {
		// point to first headNode
		tempNode = headNode; 
		
		// store firstNode value
		int firstNodeValue = tempNode->data;		
		
		// update the headNode of list
		headNode = headNode->next;
		
		// delete the firstNode
		free(tempNode);
		
		printf("%d deleted from the list\n", firstNodeValue);
	}
}

/*
void deleteAValueFromList(int val){

	struct Node* currentNode = headNode;
	struct Node* previousNode = NULL;
	
	// if the list is empty
	if(currentNode == NULL) {
		printf("list is empty. Nothing to delete\n");
		
		//return NULL;
	}
	else{		// traverse the list
		
		while(currentNode->next != NULL) {
			// if data is not matched
			if(currentNode->data != val){
			
			}
			// if data is matched
			else{
			
			}
			
			// if this is only one Node in list
			if(currentNode->next == NULL){
				printf("\n%d item is not found\n", val);
				
				//return NULL;
			}
			else{
				// make a reference to previousNode
				previousNode = currentNode;
				
				// update the current Node
				currentNode = currentNode->next;
			}
			
		
		}
		
		// if find match in currentNode value
		// then delete the Node
	
		struct Node* tempNode = NULL;
		tempNode = currentNode;
		
		// if desired value found in last node
		if(tempNode->next == NULL){
			// set currentNode next node NULL
			currentNode->next = NULL;
			
			// delete the node
			//free(tempNode);
			
		}
		else{
			// update the currentNode
			currentNode = currentNode->next;	
			
			// delete the node
			//free(tempNode);
								
		}

		if(currentNode->data == val) {
			currentNode = currentNode->next;
		}		
				
		// delete the node
		free(tempNode);	
		
		printf("\n%d deleted from list\n", val);
		
	}
}
*/


void deleteValueFromList(int val){
	 struct Node *curNode, *prevNode, *tempNode;
	 int itemIsFound;
	 
	 // for 1st node set no previous node
	 prevNode = NULL;
	 
	 // point current node to head node
	 // and traverse the list untill node exists
	 for(curNode = headNode; curNode != NULL; prevNode = curNode, curNode = curNode->next){
	 	// found the item
	 	if(curNode->data == val){
	 		itemIsFound = 1;
	 		
	 		if(prevNode == NULL){
	 			// fix the beginner pointer
	 			headNode = curNode->next;
	 		}
	 		else{
	 			// update previous node's next to current node's next
	 			// and unlink the current node
	 			prevNode->next = curNode->next;
	 		}
	 		
	 		// delete current node
	 		free(curNode);
	 		
	 		//printf("\n%d deleted from the list\n", val);
	 	}
	 	
	 }
	 
	 // Not found the item
 	if(itemIsFound == 1){
 		printf("\n%d deleted from the list\n", val);
 	}
 	else{
 		printf("\n%d not found in the list to delete\n", val);
 	}
 
 
}

void printTheList(){
	// take a tempNode reference variable
	struct Node *tempNode = NULL;
	
	// assign headNode to tempNode
	tempNode = headNode;
	
	// start printing from headNode
	while(tempNode != NULL) {
		// store the node value 
		int nodeValue = tempNode->data; 
		
		printf("%d ", nodeValue);
		tempNode = tempNode->next;
	}
	printf("\n");
}

int listLength(){
	// variable to update length of list
	int length = 0;
	
	struct Node *currentNode = NULL;
	
	// point to headNode
	currentNode = headNode;
	
	// traverse the list
	while(currentNode != NULL) {
		length++;
		currentNode = currentNode->next;
	}
	
	// return length of list
	return length;
}

bool isEmpty(){
 return (headNode == NULL);
}

int main()
{
	printf("Singly Linked List\n");
	
	// list length at initial stage
	printf("List length: %d\n", listLength());
	
	// define node no for sample insert
	int nodeNoToInsert;
	printf("\nEnter a no for how many nodes to insert: ");
	scanf("%d", &nodeNoToInsert);
	
	int temp;
	
	// insert some values
	for(int i = 0; i < nodeNoToInsert; i++) {
		printf("\nEnter a value: ");
		scanf("%d", &temp);
		
		//insert 
		insertAtFirst(temp);
	}
	
	printf("List length: %d\n", listLength());
	printf("The List is: ");
	printTheList();
	
	
	// define node no for sample delete
	int nodeNoToDelete;
	printf("\nEnter a no for how many nodes to delete: ");
	scanf("%d", &nodeNoToDelete);
	
	// delete some values
	for(int i = 0; i < nodeNoToDelete; i++) {
		
		// delete
		deleteFromFirst();
	}
	
	printf("List length: %d\n", listLength());
	printf("The List is: ");
	printTheList();
	
	// define a value to delete
	int valueToDelete;
	printf("\nEnter a value to delete from list: ");
	scanf("%d", &valueToDelete);
	
	// delete the asked value
	deleteValueFromList(valueToDelete);
	
	
	printf("List length: %d\n", listLength());
	printf("The List is: ");
	printTheList();
	
	
	printf("\n");
	return 0;
}
