#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *nodeaddress;

nodeaddress createNode(int number)
{
    nodeaddress temp = malloc(sizeof(nodeaddress));
    temp->data = number;
    temp->next = NULL;
    return temp;
}

nodeaddress insertNode(nodeaddress rootNode, int number)
{
    nodeaddress temp = malloc(sizeof(nodeaddress));

    if (rootNode == NULL)
    {                              // For the first time nodeaddress will always be null as there is no node.
        return createNode(number); // Takes the number it received and calls the createNode() function.
                                   // return temp;
    }
    else
    {
        //As, Rootnode should always point to the first node in the LL we create 
        // a new pointer iter that goes to the last node and then we use it to add temp to the list. (We dont touch the rootnode)
        nodeaddress iter = rootNode;
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        temp->data = number;
        temp->next = NULL;
        iter->next = temp;
        return rootNode;
    }
}

void printNodes(nodeaddress address)
{
    while (address != NULL)
    {
        printf("%d\n", address->data);
        address = address->next;
    }
}

void selectionSort(nodeaddress address)
{
    nodeaddress i, j;
    int temp;
    for (i = address; i->next != NULL; i = i->next) 
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data) // address is accessed and data at those address are compared and depending upon
            {                      // greater or less than they are sorted.
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main()
{
    nodeaddress Root = NULL;
    int n;
    int val;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values:\n");

    // NR: only takes input for node values in the for loop
    for (int i = 1; i <= n; i++)
    {
        printf("Value for node %d:", i);
        scanf("%d", &val);
        Root = insertNode(Root, val);
    }
    printf("The original elements are:\n");
    printNodes(Root);
    selectionSort(Root);

    printf("The elements after selection sort are:\n");
    printNodes(Root);

    return 0;
}