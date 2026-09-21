#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main(void) {
    int n;
    printf("Array size: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > INT_MAX / 2 ||
        (size_t)n > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Enter a positive array size.\n");
        return 1;
    }

    int *a = malloc((size_t)n * sizeof *a);
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i)
        *(a + i) = 2 * i + 1;

    for (const int *p = a; p != a + n; ++p)
        printf("%d ", *p);
    putchar('\n');

    free(a);
    return 0;
}
