#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node ReverseLinkedList(struct Node *head)
{

    struct Node *prev = NULL; // Initially both prev and next have NULL as the addresses.
    struct Node *next = NULL;

    while (head != NULL)
    {                      // At the end head has to be NULL coz it would be the last node which contains some data but the address is NULL.
        next = head->next; // Reverse technique.
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev; // At the end of above loop head points to the next node. Since the next node would not exist at the end of the list head has to have addre. of prev which is the last address of the list.

    return *head; // We return the last address of the list as the head so as to reverse the list.
}

int main()
{

    struct Node *head = NULL;
    head = malloc(sizeof(struct Node));

    struct Node *address = NULL;
    address = malloc(sizeof(struct Node));


    *address = ReverseLinkedList(head);
    if (address != NULL) // Checks if the Original list is empty.
    {
        printf("Reversed Order is:");
        while (address != NULL)
        { // Takes the end address which is now the first address of the Linked List
            printf("%d,", address->data);
            address = address->next;
        }
        return 0;
    }
}
