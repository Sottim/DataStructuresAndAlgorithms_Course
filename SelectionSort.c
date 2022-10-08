// Pseudocode
// bucket numbers : 0, 1, 2, 3 ...98, 99

#include <stdio.h>
#include <stdlib.h>

int *generateArray(int n) {
	int *array = malloc( n * sizeof(int) );
	if(array) {
		for(int i=0; i<n; i++) 
        {
            array[i] = rand()%1000; // Randomly allocate and take the mod of thoes each values( coz num generated are big) and saves in an array
        }
	}
	return array; //Doubtful if this return the starting address of array t or not.
}

void printArray(int *a, int n) { // better version of printing the elements of array than PrintArray1() function.
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]); //Ternery operator to check where to put commas.
	}
	printf(".\n");
}

int IndexOfMaxElement(int *a, int n)
{
    int maxI;
    if(n<1) return 0; //error case if there are no elements in the list return 0 and move out of function.
    
    maxI = 0; // I am assuming a[0] is the max element.
    for (int i=1; i<n; i++){
        if(a[i] > a[maxI]){
            maxI = i;
        }
    }
    return maxI; //Returns the maximum Index
}

void swap(int *x, int *y)  // Call by reference changes the address location of the element directly in the array without creating the copy of that array.
{
    int t;
    t = *x; // t = value at address x
    *x = *y; // At address x, the value of y is stored.
    *y = t;
}

void selectionSort(int *a, int n)
{
    // here n = 100
    int i;
    int imax; // this will contain index of the maximum element in an array
    for (i = n; i > 1; i = i - 1) // i!>0 coz we are assuming that the 
    {
        imax = IndexOfMaxElement(a, i);
        swap(&a[imax], &a[i-1]); // OR swap(a+imax, a+i-1)
        
    }
}

void swap2(int x, int y) // This function is just for my understanding of Call by Value concept.
{
    int t = x;
    x = y;
    y = t;
}
// Here if we call swap2 functions from the main(), then print the value of x there, value of x wont be swapped. This is because of Call by Value as the copies of x and y are sent

int main(int argc, char **argv){
    int n;
    int *array; 
    printf("Enter the size of array:");
    scanf("%d", &n);

    array = generateArray(n);
    printf("Original Array = ");
    printArray(array, n);

    selectionSort(array, n);
    printf("Sorted Array = ");
    printArray(array, n);

    return 0;
}