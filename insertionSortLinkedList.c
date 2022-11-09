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

//Approach: we keep on adding the elements from head into sorted list after comparison
// Original elements : -1 , 5 , 3 , 4 , 0 
// First we add -1 as it is in the sorted list. Then we move head point to 5. we compare -1 and 5 then insert it. Then 3 is inserted in between of -1 and 5 by using the inner while loop and code following that.
nodeaddress insertionsort(nodeaddress head){ 
    nodeaddress sorted = NULL; // initially sorted list would contain 1000 as a random value
    
    while(head != NULL){ 
        nodeaddress temp = sorted;   // temp would contain the starting address of sorted every time so that at the end sorted would still contain the starting address of sorted list
        nodeaddress next = head->next;
        
        while(temp->next != NULL && temp->next->data < head->data){
            temp = temp->next;
        }
        head->next = temp->next;
        temp->next = head;
        head = next;
    }
    return sorted->next;  // sorted next is the starting address of the sorted list as for the first time it has random value of 1000
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
    Root = insertionsort(Root);
    printf("The elements after insertion sort are:\n");
    printNodes(Root);

    return 0;

}
