#include <stdio.h>
#include <stdlib.h>

/*Approach :
Step 1: Create a Heap prevesing the rule of complete binary tree. 
Step 2: We create the Max Heap. Then once we start deleting the elements from the max heap, every recursive process we 
delete the largest element and attach towards the last index of the array

*/
int *createArray(int n) {
	int *arr = malloc( n * sizeof(int) );
	if(arr) {
		for(int i=0; i<n; i++) 
        {  
            scanf("%d", &arr[i]);
        }
	}
	return arr;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void createHeap(int *a, int n, int i){
    int large_Num, left, right;
    large_Num = i;
    left = 2 * i + 1; //left child
    right = 2 * i + 2; //right child
    if(left < n){ 
        if(a[left] > a[large_Num])   
        large_Num = left; // change the parent node 
    }
    if(right < n){
        if(a[right] > a[large_Num])  
        large_Num = right; // change the parent node
    }
    if(large_Num != i){
        swap(&a[i], &a[large_Num]); // Swap the elements if the parent node was actually less than any of the children.
        createHeap(a, n, large_Num);
    }
}
void sortHeap(int *a, int n){  
    for(int i = n/2 - 1; i >= 0; i--){ // for creation of Max heap
        createHeap(a, n, i);
    }
    for(int i=n-1; i>=0; i--){  // heap sorting i.e swap the first node with the last node
        swap(&a[0], &a[i]);
        createHeap(a, i, 0);
    }
}
void printArray(int *a, int n) { // better version of printing the elements of array than PrintArray1() function.
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]); //Ternery operator to check where to put commas.
	}
	printf(".\n");
}

int main(){
    int *array, size;
    printf("Enter the size of array elements:");
    scanf("%d", &size);

    printf("Enter the values in an array: \n");
    array = createArray(size);


    sortHeap(array, size);
    printf("Sorted Array is: ");
    printArray(array, size);

    return 0;
}