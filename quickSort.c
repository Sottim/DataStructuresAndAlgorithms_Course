#include <stdio.h>
#include <stdlib.h>

int *createArray(int n) {
	int *array = malloc( n * sizeof(int) );
	if(array) {
		for(int i=0; i<n; i++) 
        {  
            scanf("%d", &array[i]);
            //array[i] = rand()%1000; 
        }
	}
	return array;
}

void swap(int *x, int *y)  // Call by reference changes the address location of the element directly in the array without creating the copy of that array.
{
    int t;
    t = *x; // t = value at address x
    *x = *y; // At address x, the value of y is stored.
    *y = t;
}

int partition(int *a, int low, int high){
    int pivot = a[high];
    int i = low-1; //this would be the potition of the smaller value
    
    int j;
    for(j = low; j<=high-1; j++){
        if(a[j] < pivot){ // if the a[j] is less than pivot element then increment i and swap the position of values
            i++;
            swap(&a[i], &a[j]); // swap the elements of an array
        }
    }
    swap(&a[i+1], &a[high]);
    return i+1;  //retun i+1 to quickSort
}


void quickSort(int *a, int low, int high){
    if(low < high){
        int part = partition(a, low, high);
        quickSort(a, low, part-1);  // call quicksort from lower index till 1 less than partion point
        quickSort(a, part+1, high); //here the starting point is 1 after the partition point
    }
}


void printArray(int *a, int n) { 
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]); //Ternery operator 
	}
	printf(".\n");
}



int main(){
    int n; 
    int *array;
    printf("Enter the size of array elements:");
    scanf("%d", &n);
    
    printf("Enter the values in an array: \n");
    array = createArray(n);

    printf("The original elements of an array are:\n ");
    printArray(array, n);
    
    quickSort(array, 0, n-1);
    printf("The sorted array using heap Sort is:\n ");
    printArray(array, n);
    
    return 0;
}