#include <stdio.h>
#include <stdlib.h>

// Approach : the code is based on the Elevator taught by Professor in the class.
struct Node{
int val;
struct Node *next;
struct Node *next5;
struct Node *next10;
};

typedef struct Node node_Address;

//Randomly generate the array elements according to the size entered by the user
int *generateArray(int n) {
	int *array = malloc( n * sizeof(int) );
	if(array) {
		for(int i=0; i<n; i++) 
        {
            array[i] = rand()%1000; // Randomly allocate and take the mod of thoes each values( coz num generated are big) and saves in an array
        }
	}
	return array; 
}

//print linked list
void printLinkedList1(node_Address *head){
    node_Address * temp = head;
    while(temp!=NULL){
        if (temp->next==NULL)
            printf("%d",temp->val);
        
        else
            printf("%d->",temp->val);
        
        temp = temp->next;
    }
    printf("\n");
}

void printLinkedList5(node_Address *head){
    printf("%d ",head->val);
    node_Address * temp = head;
    while(temp!=NULL){
        if (temp->next5!=NULL){
            printf("%d ",temp->next->val);
        }
        temp = temp->next;
    }
    printf("\n");
}

void printLinkedList10(node_Address *head){
    printf("%d ",head->val);
    node_Address * temp = head;
    while(temp!=NULL){
        if (temp->next10!=NULL){
            printf("%d ",temp->next->val);
        }
        temp = temp->next;
    }
    printf("\n");
}

//convert an array to skip list
node_Address * arrayToSkipList(int *a, int n){
    node_Address * root = malloc(sizeof(node_Address));
    root->val = a[0];
    root->next = NULL;
    root->next5 = NULL;
    root->next10 = NULL;
    node_Address *temp = root;


    for(int i=1;i<n;i++){
        node_Address *new_Node = malloc(sizeof(node_Address));
        new_Node->val = a[i];
        new_Node->next = NULL;
        new_Node->next5 = NULL;
        new_Node->next10 = NULL;

        temp->next = new_Node;
        temp = temp->next;
    }

    //add the next5 and next10 in the list
    temp = root;
    int counter = 0;
    while(temp!=NULL){
        counter++;
        if (counter%5==0){
            temp->next5 = temp->next;
        }
        if (counter%10==0){
            temp->next10 =temp->next;
        }
        temp = temp->next;
    }

    return root;
}


int main(){
    int n;
    printf("Enter the size of the array: \n");
    scanf("%d", &n);

    int *arr = generateArray(n);

    printf("The original length of array: \n %d", n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    printf("\n");

    printf("The skip list is as follows: \n");
    node_Address *root = arrayToSkipList(arr,n);
    printLinkedList1(root);
    printLinkedList5(root);
    printLinkedList10(root);

    return 0;
}