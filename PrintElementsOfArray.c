#include <stdio.h>
#include <stdlib.h>

int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) 
        {
            t[i] = rand()%1000; // Randomly allocate and take the mod of thoes each values and saves in an array
        }
	}
	return t; //Doubtful if this return the starting address of array t or not.
}


void printArray(int *a, int n) { // better version of printing the elements of array than PrintArray1() function.
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf(" %d ", a[i]);
	}
}

int main(int argc, char **argv) {
	int * a;
	int n = 10;

	a = generateArray(n);
    //printf("Test: %p\n", a); //Just testing.
	printArray(a,n);
	printArray1(a,n);

	free(a);
	return 0;
}