/* void insertionSort()
{
    Approach -->
    977, 385, 7, 885 ....
    Process is like this.
    977
    385, 977
    7, 385, 977
    7, 385, 885, 977

} */
#include <stdio.h>
#include <stdlib.h>

int *createArray(int n) {   //Asks the user to enter the elements in an array of size n.
	int *array = malloc( n * sizeof(int) );
	if(array) {
		for(int i=0; i<n; i++) 
        {  
            scanf("%d", &array[i]); // elements gets entered untill i = n.
        }
	}
	return array;  // The base address of the created array is returned.
}

int *insertionSort(int *a, int n){ // Insertion sort technique.
    int i,j;
    int temp;
    for(i=1; i<n; i++){
        temp = a[i];
        j = i-1;
        while(j >= 0){
            if(temp < a[j]){
                a[j+1] = a[j];
            }
            else  break;
            j = j-1;
        }
        //insert the value of x at num[j+1] position outside inner loop
        a[j+1] = temp;
    }
    return a; //Base address of the modified array is returned.
}

void printArray(int *a, int n) { 
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]); //Ternery operator to check where to put commas.
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
    
    array = insertionSort(array, n);
    printf("The sorted array is:\n ");
    printArray(array, n);
    
    
    return 0;
}
