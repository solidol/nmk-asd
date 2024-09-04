#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Ініціалізуємо генератор випадкових чисел
    srand(time(NULL));

    int rows, cols;

    printf("Введіть кількість рядків: ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців: ");
    scanf("%d", &cols);

    // Створюємо двовимірний динамічний масив
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    // Заповнюємо масив випадковими числами
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 100;  // Випадкові числа від 0 до 99
        }
    }

    // Виводимо масив на екран
    printf("Згенерований масив:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    // Видаляємо динамічний масив
    for (int i = 0; i < rows; ++i) {
        free(array[i]);
    }
    free(array);

    return 0;
}
