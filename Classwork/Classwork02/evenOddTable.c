#include <stdio.h>

int main() {
    int i, evens = 0, odds = 0, num;
    for (i = -10; i <= 10; i++) {
        num = i * i;
        printf ("%d\t %d\t", i, num);
        if (num % 2 == 0) {
            evens++;
            printf("EVEN\n");
        } else {
            odds++;
            printf("ODD\n" );
        }
    }
    printf("# odd numbers = %d\n", odds);
    printf("# even numbers = %d\n", evens);
    return 0;
}     