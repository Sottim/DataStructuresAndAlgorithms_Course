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

nodeaddress Tail(nodeaddress head){
    nodeaddress temp = head;
    while(temp != NULL){
        temp = temp->next;
    }
    return temp;
}

nodeaddress partition(nodeaddress head, nodeaddress tail){ // function to find the pivot address
    nodeaddress pivot = head;
    nodeaddress start = head->next;
    nodeaddress prev =  head;

    while(start != tail->next){
        int t;
        if(pivot->data > start->data){
            // Now swapping the prev->next->data and prev->data
            t = prev->data;
            prev->data = start->data;
            start->data = t;
            // incrementing the prev to prev->next;
            prev = prev->next;
        }
        else{
            start = start->next;
        }
        
    }
    // swap(prev->data, pivot->data);
    int t1;
    t1 = prev->data;
    prev->data = pivot->data;
    pivot->data = t1; 

    return prev; // This would return the pivot address
}

void quicksort(nodeaddress head, nodeaddress tail){

    if(head == NULL || head->next == NULL){
        return;
    }
    else{
        nodeaddress pivot = partition(head, tail); // finds the pivot address by calling partition function.

        quicksort(head, pivot);  // we now call the actual sorting by quicksort till the 
        quicksort(pivot->next, tail); // 
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
    
    nodeaddress end = Tail(Root);

    quicksort(Root, end);
    printf("The elements after sorting are:\n");
    printNodes(Root);

    return 0;

}
