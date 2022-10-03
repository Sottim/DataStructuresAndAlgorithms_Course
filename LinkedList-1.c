#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main () {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)(malloc(sizeof(struct Node*)));
    second = (struct Node*)(malloc(sizeof (struct Node))); //malloc() allocates the specific size in the memory and second finally would contain the address of the second node.
    third = (struct Node*)(malloc(sizeof(struct Node)));

    head-> data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;
    printf("First element: %d", head->data);
    
    return 0;
}