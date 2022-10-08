// Pseudocode
// bucket numbers : 0, 1, 2, 3 ...98, 99
void selectionSort(int *a, int n)
{
    // here n = 100
    int i; int t;
    int imax; // this will contain index of the maximum element in an array
    for (i = n; i > 1; i = i - 1) // i!>0 coz we are assuming that the 
    {
        imax = findIndexOfMax(a, i);
        swap(&a[imax], &a[i-1]); // OR swap(a+imax, a+i-1)
        
    }
}

int findIndexOfMax(int *a, int n)
{
    int imax;
    if(n<1) return 0; //error case if there are no elements in the list
    
    imax = 0; // I am assuming a[0] is the max element.
    for (i=1; i<n; i++){
        if(a[i] > a[imax]){
            imax = i;
        }
    }
    return imax;
}

i
printf("Index of max element = %d, value of that element= %d\n",maxindex, a[maxindex]);

int findAddressOfMax(int *a, int n){ //Upload to gitHub
    int *amax = NULL;
    int 
    if(n>=1)
    {
        amax = a; // stores the base address of array a.
        for(int i=1; i<n; i++)
        {
            if(*(a+i) > *(a+amax) ) //i.e if a[1] > a[0] initially
            {
                amax = i;
            }
        }
        return amax
    }    
}

void swap(int *x, int *y)  // Call by reference
{
    int t;
    t = *x; // t = value at address x
    *x = *y; // At address x, the value of y is stored.
    *y = t;
}
void swap2(int x, int y) // Call by Value
{
    int t = x;
    x = y;
    y = t;
}
// Here if we call swap2 functions from the main(), then print the value of x there, value of x wont be swapped. This is because of Call by Value as the copies of x and y are sent.