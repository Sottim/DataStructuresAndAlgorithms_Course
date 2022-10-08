#include <stdio.h> // Simple Linked list with 3 Nodes.
#include <stdlib.h>

//https://stackoverflow.com/questions/69975191/how-does-struct-node-ptr-mallocsizeofptr-work

struct Node{ // An object of the type struct Node is allocated a memory.
    int data;
    struct Node *next;
};

void ListTransversal_2(struct Node *address){ // For() loop for the above while loop.
    struct Node *c;
    printf("Elements are: ");
    for(c = address; c!=NULL; c= c->next)
    {
        printf("%d,", c->data);
    }
}

int main () {
    struct Node *head = NULL; // Initially the address of all is declared as NULL
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)(malloc(sizeof(struct Node*)));
    second = (struct Node*)(malloc(sizeof (struct Node))); //malloc() allocates the specific size in the memory and second finally would contain the address of the second node in the memory.
    third = (struct Node*)(malloc(sizeof(struct Node)));

    head-> data = 10; // the data stored in the first node is 10
    head->next = second; //contaions the address of the next node
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;

    ListTransversal_2(head);// function call with address of head as a parameter
    //OR
    //ListTransversal(head);

    return 0;
}