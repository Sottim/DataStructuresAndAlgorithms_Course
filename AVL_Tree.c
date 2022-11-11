#include <stdlib.h>
#include <stdio.h>

//Implementation of AVL Tree
struct node{  //AVL tree node 
    int value;
    int height;
    struct node *left;
    struct node *right;
};
typedef struct node *nodeaddress;

nodeaddress createNode(int number)
{//Create the new node temp to store the sent data in this function
    nodeaddress temp = malloc(sizeof(nodeaddress));
    temp->value = number;
    temp->height = 1;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(nodeaddress node){ // This function calculates the height of the binary tree
    if(node == NULL){
        return 0; 
    return node->height;
    }
}
int subtract(int a, int b){
    return a - b;
}

int balanceFactor(nodeaddress node){
    if(node == NULL){
        return 0;
    }
    return subtract(height(node->left), height(node->right)); 
}
//RightRotation
nodeaddress rotateRight(nodeaddress node)
{ 
    nodeaddress temp1 = node->left;
    nodeaddress temp2 = temp1->right;

    temp1->right = node;
    node->left = temp2;

    if(height(node->left) > height(node->right)){
        node->height =  1 + height(node->left);
    }
    else 
        node->height =  1 + height(node->right);

    if(height(temp1->left) > height(temp1->right)){
        temp1->height =  1 + height(temp1->left);
    }
    else
        temp1->height =  1 + height(temp1->right);

    return temp1;
}
//LEFT Rotation
nodeaddress rotateLeft(nodeaddress temp1)
{ 
    nodeaddress node = temp1->right;
    nodeaddress temp2 = node->left;

    node->left = temp1;
    temp1->right = temp2;

    if(height(temp1->left) > height(temp1->right)){
        temp1->height =  1 + height(temp1->left);
    }
    else
        temp1->height =  1 + height(temp1->right);

    if(height(node->left) > height(node->right)){
        node->height =  1 + height(node->left);
    }
    else
        node->height =  1 + height(node->right);

    return node;
}

nodeaddress insertNode(nodeaddress rootNode, int number)
{
    int balancing;
    if (rootNode == NULL)                        
        return createNode(number); // If this is the first node to be created i.e root is currently null then go to createNode to create the first node of the list which is a root node.

    if(number > rootNode->value){ // Normal BST Rule for the insertion in the right side of BST
        rootNode->right = insertNode(rootNode->right, number);
    }
    else if(number < rootNode->value){ // Normal BST Rule for the insertion in the left side of BST
        rootNode->left = insertNode(rootNode->left, number);
    }
    else 
        return rootNode;

// Checks for which side of BST the height is bigger
    if(height(rootNode->left) > height(rootNode->right)){
        rootNode->height =  1 + height(rootNode->left);
    }
    else 
        rootNode->height =  1 + height(rootNode->right);
// To check if the tree became unbalanced after the node insertion
    balancing = balanceFactor(rootNode);

// RR Rotation using recursion
    if(balancing > -1 && number > rootNode->right->value){
        return rotateLeft(rootNode);
    }

// LL Rotation using recursion
    if(balancing > 1 && number < rootNode->left->value){
        return rotateRight(rootNode);
    }
// RL Rotation
    if(balancing < -1 && number < rootNode->right->value){
        rootNode->right = rotateRight(rootNode->right);
        return rotateLeft(rootNode);
    }
// LR Rotation
    if(balancing > 1 && number > rootNode->left->value){
        rootNode->left = rotateLeft(rootNode->left);
        return rotateRight(rootNode);
    }
    return rootNode;
}
//Preorder transversal to print in the sorted order
void preorder(nodeaddress rootNode){
    if(rootNode != NULL){
        printf("%d\n", rootNode->value);
        preorder(rootNode->left);
        preorder(rootNode->right);
    }
}

int main(){
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

    printf("Preorder transversal order of the tree is: \n");
    preorder(Root);

    return 0;
}