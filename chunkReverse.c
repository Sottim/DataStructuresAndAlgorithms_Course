#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void addNode(struct node **headaddress, int value){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->next = *headaddress;
    *headaddress = temp;
}

void ReverseKthNodes(struct node **headaddress, int key){
    struct node *temp = *headaddress;
    int c = 1 ; // count variable
    while(c < key) { // count keeps track of the position of where to divide the original linked list.
        temp = temp->next;
        c++;
    }

    struct node *breakPoint = temp->next ;  // temp->next is the address of the node where the new linked list starts.
    temp->next = NULL;   // Make the address contained in the node before the key to be null now.

    struct node *prev = NULL; // Initially both prev and next have NULL as the addresses.
    struct node *current = *headaddress;
    struct node *next;

    while (current != NULL) // Reverse the list till Kth node.
    {                      // At the end head has to be NULL coz it would be the last node which contains some data but the address is NULL.
        next = current->next; // Reverse technique.
        current->next = prev;
        prev = current;
        current = next;
    }
    *headaddress = prev; // At the end of above loop head points to the next node. Since the next node would not exist at the end of the list head has to have addre. of prev which is the last address of the list.
    current = *headaddress;
    while(current->next != NULL){
        current = current->next;
    
    current->next = breakPoint;
    }
}

void printNodes(struct node *headaddress)
{
    printf("Elements are : \n");
    while (headaddress != NULL)
    {
        printf("%d\n", headaddress->data);
        headaddress = headaddress->next;
    }
}

int main(){
    struct node *head = NULL;

    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    addNode(&head, 20);
    addNode(&head, 25);
    addNode(&head, 30);
    addNode(&head, 35);
    addNode(&head, 40); 

    printf("The elements of the nodes are: \n");
    printNodes(head);

    printf("After modification, elements of the nodes are: \n");
    ReverseKthNodes(&head, 15);
    printNodes(head);

    return 0;
}