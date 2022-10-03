
//Play around the concept of pointers and constants
#include<stdio.h>
int main(){
    
    const int a1 = 5;      // declare a constant var
    a1 = 6;                // we cannot change the value of constant. It shows error.

    // Working of Pointers, how they work
    int *p = &a1;        // p has the address of a1
    *p = 60;              
    printf("a1 = %d", a1);
    printf("*p = %d", *p);
    

    int a = 10;
    int b = ++a;      // Pre Increment
    int b = a++;      // Post Increment
    printf("a= %d, b=%d\n", a, b);

    // Characters and Strings

    char s1 = 'v';
    char *s = "abcd";
    *(s+5) = 'x';   // exactly same as saying: s[5] = 'x'
    s[6] = 'y';

    // Constant Strings
    const char * str = "Bla";  //
    str = "Error.";  // String is modified
    printf("%s\n", str);              // Printing of the new string

    return 0;
}