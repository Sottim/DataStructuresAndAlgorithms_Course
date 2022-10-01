#include <stdio.h>

/* print integers from 1 to 5 */

int main(int argc, char **argv) {
    
    int i;
    int count= 0;
    puts("Printing:");
    for(i = 1; i <= 10; i++) {
        printf("%d\n", i);
        count = count + 1;
    }
    printf("%d\n", count);
    return 0;
}
