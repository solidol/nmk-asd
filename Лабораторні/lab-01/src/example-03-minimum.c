#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int n;
    printf("Array size: ");
    if (scanf("%d", &n) != 1 || n <= 0 ||
        (size_t)n > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Enter a positive array size.\n");
        return 1;
    }

    int *a = malloc((size_t)n * sizeof *a);
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int *p = a; p != a + n; ++p) {
        if (scanf("%d", p) != 1) {
            fprintf(stderr, "Invalid input.\n");
            free(a);
            return 1;
        }
    }

    int minimum = *a;
    for (const int *p = a + 1; p != a + n; ++p)
        if (*p < minimum) minimum = *p;

    printf("Minimum: %d\n", minimum);
    free(a);
    return 0;
}
