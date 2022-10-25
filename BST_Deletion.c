#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *left ;
    struct node *right ;
};

struct node *createNode(int number){
    struct node *temp = malloc(sizeof(struct node));
    temp->value = number;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

struct node *insertNode(struct node *rootNode, int number){
    
    if(rootNode == NULL){  
       return createNode(number);  
    }

    if(number > rootNode->value){
        rootNode->right = insertNode(rootNode->right, number);
    }
    else if(number < rootNode->value){
        rootNode->left = insertNode(rootNode->left, number);
    }
    return rootNode;
}

int smallest_Value(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root->value;
}

struct node *deleteNode(struct node *root, int num){
    if(root == NULL) return NULL;
    else{
        if(num < root->value){ // transerve to the left node of the root  and recursive call making the left node as the root now recursively
            root->left = deleteNode(root->left, num);
        }
        else if(num > root->value){
            root->right = deleteNode(root->right, num);
        }
        else{ // Now if now we reach the node which contains the number to be deleted i.e num, we have 3 cases -
            if(root->left == NULL){ //Case 1: when the left child of the node is NULL i.e it is basically a leaf node 
                return root->right; 
            }
            else if(root->right == NULL){ // Case 2: when the right child of the node is NULL 
                return root->left;
            }
            else{ } 
            // Now if the number is in between the node i.e it is not a leaf node.
            root->value = smallest_Value(root->right); // call the function to find the smallest value in the right subtree of the current node which is essentially in the left most part of that subtree.
            root->right = deleteNode(root->right, root->value); // call the function by passing that right subtree and deleting the node.
            return root;
            }
        }
        return root;

}

void inorder(struct node *rootNode){
    if(rootNode != NULL){
        inorder(rootNode->left);
        printf("%d\n", rootNode->value);
        inorder(rootNode->right); 
    }
}


int main(){
    struct node  *Root = NULL;  
    int n; int val;
    int deleteNum;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values: \n");
    for(int i=1; i<=n; i++){
        scanf("%d", &val);
        Root = insertNode(Root, val);
    }
    printf("The resultant tree's inorder transversal is: \n");
    inorder(Root);

    printf("Enter the number to be deleted: ");
    scanf("%d", &deleteNum); 
    Root = deleteNode(Root, deleteNum);

    printf("The resultant tree's inorder transversal after deletion is: \n");
    inorder(Root);



    return 0;
}