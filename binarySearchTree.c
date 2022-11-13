#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node *nodeaddress;

nodeaddress createNode(int number){
    nodeaddress temp = malloc(sizeof(nodeaddress));
    temp->value = number;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

nodeaddress insertNode(nodeaddress rootNode, int number){
    //nodeaddress temp = malloc(sizeof(nodeaddress));

    if(rootNode == NULL){  // For the first time nodeaddress will always be null as there is no node.
       return createNode(number);  // Takes the number it received and calls the createNode() function.
       //return temp;
    }

    if(number > rootNode->value){
        rootNode->right = insertNode(rootNode->right, number);
    }
    else if(number < rootNode->value){
        rootNode->left = insertNode(rootNode->left, number);
    }
    return rootNode;
}

void inorder(nodeaddress rootNode){
    if(rootNode != NULL){
        inorder(rootNode->left);
        printf("%d\n", rootNode->value);
        inorder(rootNode->right); 
    }
}
void preorder(nodeaddress rootNode){
    if(rootNode != NULL){
        printf("%d\n", rootNode->value);
        preorder(rootNode->left);
        preorder(rootNode->right);
    }
}
void postorder(nodeaddress rootNode){
    if(rootNode != NULL){
        postorder(rootNode->left);
        postorder(rootNode->right);
        printf("%d\n", rootNode->value);
    }
}

int main(){
    nodeaddress Root = NULL;  // It can be written struct node *Node but I have already typedef struct node to *nodeaddress
    
    int n; int val;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values: \n");
    for(int i=1; i<=n; i++){
        scanf("%d", &val);
        Root = insertNode(Root, val);
    }

    printf("printing In-order \n");
    inorder(Root);
    printf("Printing Pre-order \n");
    preorder(Root);
    printf("Printing Post-order \n");
    postorder(Root);
    
    return 0;
}