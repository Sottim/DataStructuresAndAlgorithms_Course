//Stress test of loops as discussed in class. 

#include<stdio.h>
#include<stdlib.h>
// Just to see whether the loop breaks or not, does it run infinitely

int main(){
    float i;
    float increse = 0.000000001; 
    float n = 0.00000001; // very small value of n
    int counter = 1;

    for(i=0.0; i < n; i += increse) {
        printf("the loop number is: %d\n", counter);
        counter++;
    }
    return 0;
}