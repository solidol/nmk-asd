#include <stdio.h>

int main(void) {
    int x = 10;
    int *px = &x;

    printf("Before: x = %d, *px = %d\n", x, *px);
    *px *= 2;
    printf("After: x = %d, *px = %d\n", x, *px);
    return 0;
}
