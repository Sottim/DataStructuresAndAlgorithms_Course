#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};
typedef struct node * NodeAddress;

/* ================================================== */
void bubbleSort(int * a, int n) {
	int done, i, t, swap;

	for(done=0; done<n; done++) {

		swap = 0;
		for(i=0; i<n-1-done; i++) {

			if( a[i] > a[i+1] ) {
				// swap these elements since they are in the wrong order
				t      = a[i];
				a[i]   = a[i+1];
				a[i+1] = t;
				swap   = 1;
			}

		} // end of the i loop
		if(swap==0)
			break;

	} // end of the done loop
}

NodeAddress bubbleSortLinkedList(NodeAddress head) {
	NodeAddress c, lastDone; //lastDone means the address after which the elements are sorted.
	int t;

	for(lastDone = NULL; lastDone!=head; lastDone=c) { //In first case lastDone is zero and lastDone=c means that it runs till where the inner loop ended.

		for(c=head; c->next!=lastDone; c=c->next) { //c->next!=lastDone because we dont want to swap the elemented that is already sorted.

			if( c->val > c->next->val ) {
				t = c->val;
				c->val = c->next->val;
				c->next->val = t;
			}

		} // end of c loop; the element has been bubbled up to position c

	}
	return head;
}

/* ================================================== */
int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}

NodeAddress linkedListFromArray(int * a, int n) {
	int i;
	NodeAddress head = NULL;
	NodeAddress temp = NULL;

	// special case for head
	if(n>0) {
		head = malloc( sizeof(struct node) );
		head->val  = a[0];
		head->next = NULL;
		temp = head;
	}


	for(i=1; i<n; i++) {
		temp->next = malloc( sizeof(struct node) ); // creates the memory for the next house in the list 
		temp = temp->next; //Now temp points to the new house that was created above
		temp->val = a[i]; // The value in that house is a[1] in after a[0] in second case.
		temp->next = NULL; // The house stores the NULL address for the next node.
	}

	return head;
}

void freeLinkedList(NodeAddress head) {
	NodeAddress prev;
	while(head) { // You are moving one step forward while erasing the last node.
		prev = head;
		head = head->next;
		free(prev);
	}
}

/* ================================================== */
void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf(" %d ", a[i]);
	}
}

void printLinkedList(NodeAddress head) { // NodeAddress is the data type of the list and head is the head of the list that we are getting. 
	NodeAddress c; // instead of int i;
	printf("Linked List = ");
	for(c=head; c!=NULL; c=c->next) {
		printf( c==head?"%d":", %d", c->val);
	}
	printf(".\n");
}

/* ================================================== */
int main(int argc, char **argv) {
	int * a;
	int n = 10;
	NodeAddress list; //we used typedef to convert struct Node to Nodeaddress

	srand(time(NULL));

	a = generateArray(n);
	list = linkedListFromArray(a,n);

	printArray(a,n);
	bubbleSort(a,n);
	printArray(a,n);

	printLinkedList(list);
	bubbleSortLinkedList(list);
	printLinkedList(list);

	free(a);
	freeLinkedList(list);

	return 0;
}