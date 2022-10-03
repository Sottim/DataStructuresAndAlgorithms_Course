#include <stdio.h>
#include <stdlib.h>
//https://stackoverflow.com/questions/69975191/how-does-struct-node-ptr-mallocsizeofptr-work
struct Node{ // An object of the type struct Node is allocated a memory.
    int data;
    struct Node *next;
};

int main () {
    struct Node *head = NULL; // Initialize address of all is declared as NULL
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)(malloc(sizeof(struct Node*)));
    second = (struct Node*)(malloc(sizeof (struct Node))); //malloc() allocates the specific size in the memory and second finally would contain the address of the second node.
    third = (struct Node*)(malloc(sizeof(struct Node)));

    head-> data = 10; // the data stored in the first node is 10
    head->next = second; //contaions the address of the next node
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;

    printf("First Element: %d\n", head->data); //One by one tech. to print elements in diff. nodes (which is inefficient)
    printf("Second Ele: %d\n", second->data);
    
    return 0;
}