#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *findAddressOfMax(int *a, int n){ 
    int *amax = NULL;
    if(n>=1)
    {
        amax = a; // stores the base address of array a.
        for(int i=1; i<n; i++)
        {
            if(*(a+i) > *(a+amax) ) //i.e if a[1] > a[0] initially
            {
                amax = &(a+i);
            }
        }
        
    }    
    return amax;
}


int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}

void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}


int main(int argc, char **argv)
{
    int * a;
	int n = 10;

    srand(time(NULL));

    a = generateArray(n);
    printArray(a,n);

    return 0;

}