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

nodeaddress searchNode(nodeaddress search, int number){
    if(search == NULL){
        return NULL;
    }
    if(number > search->value){
        search->right = searchNode(search->right, number);
    }
    else if(number < search->value){
        search->left = searchNode(search->left, number);
    }
    return search;
}

void inorder(nodeaddress rootNode){
    if(rootNode != NULL){
        if(rootNode->left) {
            inorder(rootNode->left);
        }
        if(rootNode){
            printf("%d", rootNode->value);
        }
        if(rootNode->right) {
            inorder(rootNode->right);
        }
    }
}
void preorder(nodeaddress rootNode){
    if(rootNode != NULL){
        if(rootNode){
            printf("%d", rootNode->value);
        }
        if(rootNode->left) {
            preorder(rootNode->left);
        }
        if(rootNode->right) {
            preorder(rootNode->right);
        }
    }
}
void postorder(nodeaddress rootNode){
    if(rootNode != NULL){
        if(rootNode->left) {
            postorder(rootNode->left);
        }
        if(rootNode->right) {
            postorder(rootNode->right);
        }
        if(rootNode){
            printf("%d", rootNode->value);
        }  
    }
}

int main(){
    //printf("Test run 0 ");
    nodeaddress Node = NULL;  // It can be written struct node *Node but I have already typedef struct node to *nodeaddress
    Node = insertNode(Node, 30);  //                30
    insertNode(Node, 20);         //          20         40
    //printf("Test run 1");
    insertNode(Node, 40);         //      10     25   35     50
    insertNode(Node, 10);
    insertNode(Node, 25);
    insertNode(Node, 35);
    insertNode(Node, 50);
    
    
    nodeaddress searchResult = NULL;
    //searchResult = malloc(sizeof(nodeaddress));
    searchResult = searchNode(Node, 35);
    if(searchResult == NULL){
        printf("The element doesnot exit ! ");
    }
    else{
        printf("The element exits ! ");
    }

    inorder(Node);
    //printf("Test run 2 ");
    preorder(Node);
    postorder(Node);
    
    return 0;
}