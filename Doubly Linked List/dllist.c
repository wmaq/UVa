#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node* next;
	struct node* prev;
	int data;
} *head = NULL;

struct node* makeNewNode(int a){ 
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = a;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void insertHead(int a){
	struct node* newNode = makeNewNode(a);
	if( head == NULL ){
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}
void insertTail(int a){
	struct node* tempNode = head;
	struct node* newNode = makeNewNode(a);
	if( head == NULL ){
		head = newNode;
		return;
	}
	while(tempNode->next != NULL) tempNode = tempNode->next; 
	tempNode->next = newNode;
	newNode->prev = tempNode;
}
void insertPos(int a){
	int tempNum, tempIterator =1, rangeIterator = 1;
	printf("Insert position of new node: ");
	scanf("%d", &tempNum);
	struct node* tempNode = head;
	struct node* rangeNode = head;
	struct node* newNode = makeNewNode(a);
	if(head == NULL){
		insertHead(a);
		return;
	}
	while( rangeNode->next != NULL ){
		rangeNode = rangeNode->next;
		rangeIterator++;
	}
	if( tempNum > rangeIterator ){
		insertTail(a);
		return;
	}
	while( tempIterator != tempNum ){
		tempNode = tempNode->next;
		tempIterator++;
	}
	if(tempNode->prev==NULL) insertHead(a);
	else if(tempNode->next==NULL) insertTail(a);
	else{
		tempNode->prev->next = newNode;
		newNode->prev = tempNode->prev;
		tempNode->prev = newNode;
		newNode->next = tempNode;
	}
}
void removeVal(){
	int tempNum, tempIterator = 1;
	if(head == NULL) return;
	printf("Enter number of node you want to remove: ");
	scanf("%d", &tempNum);
	struct node* tempNode = head;
	while( tempIterator != tempNum ){
		if( tempNode == NULL ){
			printf("Not found\n");
			return;
		}
		tempNode = tempNode->next;
		tempIterator++;
	}
	if(tempNode->prev==NULL){
		head = tempNode->next;
		head->prev = NULL;
	} else if(tempNode->next == NULL){
		tempNode->prev->next=NULL;
	} else {
		tempNode->next->prev=tempNode->prev;
		tempNode->prev->next=tempNode->next;
	}
	printf("Removed record numero: %d.\n", tempNum);
	free(tempNode);
}
void printList(){
	struct node* readerNode = head;
	while(readerNode != NULL){
		printf("%d ", readerNode->data);
		readerNode = readerNode->next;
	}
	printf("\n");
}
void reversedPrint(){
	struct node* readerNode = head;
	if( readerNode == NULL ) return;
	while(readerNode->next != NULL) readerNode = readerNode->next;
	while(readerNode != NULL){
		printf("%d ", readerNode->data );
		readerNode = readerNode->prev;
	}
	printf("\n");
}
int main(void){
	insertPos(10000);
	printList();
	insertPos(555);
	reversedPrint();
	removeVal();
	insertTail(123);
	printList();
	insertHead(12);
	printList();
	printf("done\n");
	return 0;
}