#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Push(struct Node **address, int value) // Keeps on adding the node from left hand side in the format , add = value + add
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = value; // If I remove this statement the first node will contain the random variable and not the passed variable 
    // temp->next = NULL; Not required
    temp->next = *address;
    *address = temp;
    //free(temp); I cannot free temp here coz address is actually carrying the address of temp and returing it.
}
void insertSpecificPos(struct Node *address, int value){
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = address->next; // i.e temp->next receives the address->next->next.
    address->next = temp;
}

void ListTransversal(struct Node *address)
{ // Using while() loop
    while (address != NULL)
    {
        printf("Elements = %d\n", address->data);
        address = address->next;
    }
}

int main(){
    struct Node *head = NULL;
    // head = (struct Node *)(malloc(sizeof(struct Node *))); // We don't write this here.  
    Push(&head, 3);   // Passing the pointer to pointer as argument.
    Push(&head, 6);
    Push(&head, 7);
    Push(&head, 10);
    Push(&head, 20);
    Push(&head, 30);
    printf("The Original list is: \n");
    ListTransversal(head);
    insertSpecificPos(head->next, 15);
    printf("The changed list is: \n");
    ListTransversal(head);

    return 0;
}
