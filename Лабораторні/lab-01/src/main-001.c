#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Ініціалізуємо генератор випадкових чисел
    srand(time(NULL));

    int size;

    printf("Введіть розмір масиву: ");
    scanf("%d", &size);

    // Створюємо одновимірний динамічний масив
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Помилка виділення пам'яті\n");
        return 1;
    }

    // Заповнюємо масив випадковими числами
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;  // Випадкові числа від 0 до 99
    }

    // Виводимо масив на екран
    printf("Згенерований масив:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Звільняємо динамічний масив
    free(array);

    return 0;
}
