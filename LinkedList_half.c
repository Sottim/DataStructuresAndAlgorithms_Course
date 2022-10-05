//First half of the linked list from the full list
// Approach: Hare and Tortoise algorithm concept
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node *NodeAddress;  // typedef the node to nodeAddress


// Generating the linked list 
NodeAddress generateLinkedList(int n)
{
    int i;
    NodeAddress root = NULL;
    NodeAddress temp = NULL;
    root = malloc(sizeof(struct Node));
    root->val = rand()%1000;       //  a random value to the head->val
    root->next = NULL;              // head->next is null.
    temp = root;
    // general case
    for(i=1; i<n; i++){
        temp->next = malloc(sizeof(struct Node));
        temp = temp->next;
        temp->val = rand()%1000;            // assigning a random value to the temp->val
        temp->next = NULL;                  // assigning NULL to the temp->next
    }
    return root;                            // returning the address of the head of Linked List
}

void printLinkedList(NodeAddress root, int val)
{
    NodeAddress temp = root;
    printf("Complete Linked List = ");
    for(int i=0; i < val; i++){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
    }
}
void print_LinkedListHalf(NodeAddress head)
{

    // Hare and Tortoise Algorithm with pointer
    NodeAddress last = head;
    NodeAddress first = head;
    while(first != NULL && first->next != NULL){
        last = last->next;
        first = first->next->next;
    }
    
    NodeAddress temp = head; // Printing the first half of the given linked list 
    int i = 0;
    printf("Half Linked List using Hare and tortoise algorithm= ");
    while(temp != last){
        printf(i?", %d":"%d", temp->val);
        temp = temp->next;
        i++;
    }
}

// deletion of linked list
void delete_LinkedList(NodeAddress root){
    NodeAddress previous;
	while(root)
    {                // while head is not NULL. When the head is NULL it will be the last node
		previous = root;
		root = root->next;
		free(previous); // moving ahead one step, killing the last guy
	}
}


int main()
{
    int num;
    printf("Enter the number of elements ");
    scanf("%d", &num);
    NodeAddress newLinkedList, tail;         // new linked list 

    newLinkedList = generateLinkedList(num);              
    print_LinkedListHalf(newLinkedList);  // printing the half list given the full list
    delete_LinkedList(newLinkedList);                         \
    return 0;

}
