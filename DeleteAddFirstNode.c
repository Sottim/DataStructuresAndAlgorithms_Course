#include <stdio.h> 
#include <stdlib.h>

struct Node{ 
    int data;
    struct Node *next;
};

void ListTransversal(struct Node *address){ 
    while(address != NULL){
        printf("Elements = %d\n", address->data);
        address = address->next;
    }
}
struct Node *DeleteFirstNode(struct Node *address){ // DeleteFirstNode has a data type struct Node and returns the address the second node as head by after deleting the first node.
    if(address != NULL){
        struct Node *temp = address; //temperory node to containing the address of head passed from the main.
        address = address->next; // address of head is updated here
        free(temp);  // free up the space for temp as we no longer require the first node.
    }
    return(address);
}

struct Node *InsertNodeBeg(struct Node *address, int value)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = value; // If I remove this statement the first node will contain the random variable and not the passed variable 
    temp->next = NULL;

    temp->next = address;
    address = temp;
    
    //free(temp); I cannot free temp here coz address is actually carrying the address of temp and returing it.
    return address;
}

int main () {
    struct Node *head = NULL; // Initially the address of all is declared as NULL
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;
    

    head = (struct Node*)(malloc(sizeof(struct Node*)));
    second = (struct Node*)(malloc(sizeof (struct Node))); //malloc() allocates the specific size in the memory and second finally would contain the address of the second node in the memory.
    third = (struct Node*)(malloc(sizeof(struct Node)));
    fourth = (malloc(sizeof(struct Node)));

    head-> data = 10; // the data stored in the first node is 10
    head->next = second; //contaions the address of the next node
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = NULL;

    printf("The Original list is: \n");
    ListTransversal(head);

    printf("List after first node deletion: \n");
    head = DeleteFirstNode(head);
    ListTransversal(head);
    
    printf("List after adding new node in the first place: \n");
    head = InsertNodeBeg(head, 5);
    ListTransversal(head);

    return 0;
}