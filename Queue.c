// Simple working of queues
#include<stdio.h>
#include<stdlib.h>
#define max 10
int queue[max];
int rear = -1;int front = -1;

void Front(){
    if(front == -1 || front > rear){
        printf("Queue is Underflow");
    }
    else{
        printf("Front element is ", queue[front]);
    }
}

void Rear(){
    if(front == -1 || front > rear){
        printf("Queue is Underflow");
    }
    else{
        printf("The rear element is ", queue[rear]);
    }
}
void Display(){
    int i;
    if(front == -1 || front > rear){
        printf("Queue is Underflow");
    }
    else{
        printf("The elements in the queue are: ");
        for(i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
}

int main()
{   
    return 0;
}
